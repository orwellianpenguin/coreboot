/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2007-2009 coresystems GmbH
 * Copyright (C) 2011 Sven Schnelle <svens@stackframe.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of
 * the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <stdint.h>
#include <cf9_reset.h>
#include <delay.h>
#include <device/pnp_ops.h>
#include <device/pci_ops.h>
#include <device/pci_def.h>
#include <device/pnp_def.h>
#include <cpu/x86/lapic.h>
#include <arch/acpi.h>
#include <console/console.h>
#include <arch/romstage.h>
#include <northbridge/intel/i945/i945.h>
#include <northbridge/intel/i945/raminit.h>
#include <southbridge/intel/i82801gx/i82801gx.h>
#include <southbridge/intel/common/gpio.h>
#include <southbridge/intel/common/pmclib.h>
#include "dock.h"

static void ich7_enable_lpc(void)
{
	// Enable Serial IRQ
	pci_write_config8(PCI_DEV(0, 0x1f, 0), SERIRQ_CNTL, 0xd0);
	// decode range
	pci_write_config16(PCI_DEV(0, 0x1f, 0), LPC_IO_DEC, 0x0210);
	// decode range
	pci_write_config16(PCI_DEV(0, 0x1f, 0), LPC_EN, CNF1_LPC_EN | MC_LPC_EN
			| KBC_LPC_EN | GAMEH_LPC_EN | GAMEL_LPC_EN | FDD_LPC_EN
			| LPT_LPC_EN | COMA_LPC_EN);
	/* range 0x1600 - 0x167f */
	pci_write_config32(PCI_DEV(0, 0x1f, 0), GEN1_DEC, 0x007c1601);

	/* range 0x15e0 - 0x15ef */
	pci_write_config32(PCI_DEV(0, 0x1f, 0), GEN2_DEC, 0x000c15e1);

	/* range 0x1680 - 0x169f */
	pci_write_config32(PCI_DEV(0, 0x1f, 0), GEN3_DEC, 0x001c1681);
}

static void early_superio_config(void)
{
	int timeout = 100000;
	pnp_devfn_t dev = PNP_DEV(0x2e, 3);

	pnp_write_config(dev, 0x29, 0x06);

	while (!(pnp_read_config(dev, 0x29) & 0x08) && timeout--)
		udelay(1000);

	/* Enable COM1 */
	pnp_set_logical_device(dev);
	pnp_set_iobase(dev, PNP_IDX_IO0, 0x3f8);
	pnp_set_enable(dev, 1);
}

static void rcba_config(void)
{
	/* Set up virtual channel 0 */
	RCBA32(V0CTL) = 0x80000001;

	/* Device 1f interrupt pin register */
	RCBA32(D31IP) = 0x00001230;
	RCBA32(D29IP) = 0x40004321;

	/* PCIe Interrupts */
	RCBA32(D28IP) = 0x00004321;
	/* HD Audio Interrupt */
	RCBA32(D27IP) = 0x00000002;

	/* dev irq route register */
	RCBA16(D31IR) = 0x1007;
	RCBA16(D30IR) = 0x0076;
	RCBA16(D29IR) = 0x3210;
	RCBA16(D28IR) = 0x7654;
	RCBA16(D27IR) = 0x0010;

	/* Enable IOAPIC */
	RCBA8(OIC) = 0x03;

	/* Disable unused devices */
	RCBA32(FD) |= FD_INTLAN;

	/* Set up I/O Trap #0 for 0xfe00 (SMIC) */
	RCBA64(IOTR0) = 0x000200010000fe01ULL;

	/* Set up I/O Trap #3 for 0x800-0x80c (Trap) */
	RCBA64(IOTR3) = 0x000200f0000c0801ULL;
}

static void early_ich7_init(void)
{
	uint8_t reg8;
	uint32_t reg32;

	// program secondary mlt XXX byte?
	pci_write_config8(PCI_DEV(0, 0x1e, 0), 0x1b, 0x20);

	// reset rtc power status
	reg8 = pci_read_config8(PCI_DEV(0, 0x1f, 0), 0xa4);
	reg8 &= ~(1 << 2);
	pci_write_config8(PCI_DEV(0, 0x1f, 0), 0xa4, reg8);

	// usb transient disconnect
	reg8 = pci_read_config8(PCI_DEV(0, 0x1f, 0), 0xad);
	reg8 |= (3 << 0);
	pci_write_config8(PCI_DEV(0, 0x1f, 0), 0xad, reg8);

	reg32 = pci_read_config32(PCI_DEV(0, 0x1d, 7), 0xfc);
	reg32 |= (1 << 29) | (1 << 17);
	pci_write_config32(PCI_DEV(0, 0x1d, 7), 0xfc, reg32);

	reg32 = pci_read_config32(PCI_DEV(0, 0x1d, 7), 0xdc);
	reg32 |= (1 << 31) | (1 << 27);
	pci_write_config32(PCI_DEV(0, 0x1d, 7), 0xdc, reg32);

	ich7_setup_cir();
}

void mainboard_romstage_entry(void)
{
	int s3resume = 0;
	const u8 spd_addrmap[2 * DIMM_SOCKETS] = { 0x50, 0, 0x51, 0 };

	enable_lapic();

	/* Enable GPIOs */
	pci_write_config32(PCI_DEV(0, 0x1f, 0), GPIOBASE, DEFAULT_GPIOBASE | 1);
	pci_write_config8(PCI_DEV(0, 0x1f, 0), 0x4c, 0x10);  /* 0x4c == GC */
	setup_pch_gpios(&mainboard_gpio_map);

	ich7_enable_lpc();

	dlpc_init();
	/* dock_init initializes the DLPC switch on
	 *  thinpad side, so this is required even
	 *  if we're undocked.
	 */
	if (dock_present()) {
		dock_connect();
		early_superio_config();
	}

	/* Set up the console */
	console_init();

	if (dock_present())
		printk(BIOS_DEBUG, "Dock is present\n");
	else
		printk(BIOS_DEBUG, "Dock is not present\n");

	if (MCHBAR16(SSKPD) == 0xCAFE) {
		printk(BIOS_DEBUG,
		       "Soft reset detected, rebooting properly.\n");
		system_reset();
	}

	/* Perform some early chipset initialization required
	 * before RAM initialization can work
	 */
	i945_early_initialization();

	s3resume = southbridge_detect_s3_resume();

	/* Enable SPD ROMs and DDR-II DRAM */
	enable_smbus();

	if (CONFIG(DEBUG_RAM_SETUP))
		dump_spd_registers();

	sdram_initialize(s3resume ? 2 : 0, spd_addrmap);

	/* Perform some initialization that must run before stage2 */
	early_ich7_init();

	/* This should probably go away. Until now it is required
	 * and mainboard specific
	 */
	rcba_config();

	/* Chipset Errata! */
	fixup_i945_errata();

	/* Initialize the internal PCIe links before we go into stage2 */
	i945_late_initialization(s3resume);
}
