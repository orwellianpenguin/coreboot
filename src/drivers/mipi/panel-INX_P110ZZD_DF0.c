/* SPDX-License-Identifier: GPL-2.0-only */

#include <mipi/panel.h>

struct panel_serializable_data INX_P110ZZD_DF0 = {
	.edid = {
		.ascii_string = "P110ZZD-DF0",
		.manufacturer_name = "INX",
		.panel_bits_per_color = 8,
		.panel_bits_per_pixel = 24,
		.mode = {
			.pixel_clock = 166594,
			.lvds_dual_channel = 0,
			.refresh = 60,
			.ha = 1200, .hbl = 76, .hso = 40, .hspw = 8,
			.va = 2000, .vbl = 176, .vso = 26, .vspw = 1,
			.phsync = '-', .pvsync = '-',
			.x_mm = 143, .y_mm = 238,
		},
	},
	.init = {
		PANEL_DCS(0xFF, 0x20),
		PANEL_DCS(0xFB, 0x01),
		PANEL_DCS(0x05, 0xD1),
		PANEL_DCS(0x0D, 0x63),
		PANEL_DCS(0x07, 0x8C),
		PANEL_DCS(0x08, 0x4B),
		PANEL_DCS(0x0E, 0x91),
		PANEL_DCS(0x0F, 0x69),
		PANEL_DCS(0x95, 0xFF),
		PANEL_DCS(0x96, 0xFF),
		PANEL_DCS(0x9D, 0x0A),
		PANEL_DCS(0x9E, 0x0A),
		PANEL_DCS(0x69, 0x98),
		PANEL_DCS(0x75, 0xA2),
		PANEL_DCS(0x77, 0xB3),
		PANEL_DCS(0xFF, 0x24),
		PANEL_DCS(0xFB, 0x01),
		PANEL_DCS(0x91, 0x44),
		PANEL_DCS(0x92, 0x7A),
		PANEL_DCS(0x93, 0x1A),
		PANEL_DCS(0x94, 0x40),
		PANEL_DCS(0x9A, 0x08),
		PANEL_DCS(0x60, 0x96),
		PANEL_DCS(0x61, 0xD0),
		PANEL_DCS(0x63, 0x70),
		PANEL_DCS(0xC2, 0xCF),
		PANEL_DCS(0x9B, 0x0F),
		PANEL_DCS(0x9A, 0x08),
		PANEL_DCS(0x00, 0x03),
		PANEL_DCS(0x01, 0x03),
		PANEL_DCS(0x02, 0x03),
		PANEL_DCS(0x03, 0x03),
		PANEL_DCS(0x04, 0x03),
		PANEL_DCS(0x05, 0x03),
		PANEL_DCS(0x06, 0x22),
		PANEL_DCS(0x07, 0x06),
		PANEL_DCS(0x08, 0x00),
		PANEL_DCS(0x09, 0x1D),
		PANEL_DCS(0x0A, 0x1C),
		PANEL_DCS(0x0B, 0x13),
		PANEL_DCS(0x0C, 0x12),
		PANEL_DCS(0x0D, 0x11),
		PANEL_DCS(0x0E, 0x10),
		PANEL_DCS(0x0F, 0x0F),
		PANEL_DCS(0x10, 0x0E),
		PANEL_DCS(0x11, 0x0D),
		PANEL_DCS(0x12, 0x0C),
		PANEL_DCS(0x13, 0x04),
		PANEL_DCS(0x14, 0x03),
		PANEL_DCS(0x15, 0x03),
		PANEL_DCS(0x16, 0x03),
		PANEL_DCS(0x17, 0x03),
		PANEL_DCS(0x18, 0x03),
		PANEL_DCS(0x19, 0x03),
		PANEL_DCS(0x1A, 0x03),
		PANEL_DCS(0x1B, 0x03),
		PANEL_DCS(0x1C, 0x22),
		PANEL_DCS(0x1D, 0x06),
		PANEL_DCS(0x1E, 0x00),
		PANEL_DCS(0x1F, 0x1D),
		PANEL_DCS(0x20, 0x1C),
		PANEL_DCS(0x21, 0x13),
		PANEL_DCS(0x22, 0x12),
		PANEL_DCS(0x23, 0x11),
		PANEL_DCS(0x24, 0x10),
		PANEL_DCS(0x25, 0x0F),
		PANEL_DCS(0x26, 0x0E),
		PANEL_DCS(0x27, 0x0D),
		PANEL_DCS(0x28, 0x0C),
		PANEL_DCS(0x29, 0x04),
		PANEL_DCS(0x2A, 0x03),
		PANEL_DCS(0x2B, 0x03),
		PANEL_DCS(0x2F, 0x06),
		PANEL_DCS(0x30, 0x32),
		PANEL_DCS(0x31, 0x43),
		PANEL_DCS(0x33, 0x06),
		PANEL_DCS(0x34, 0x32),
		PANEL_DCS(0x35, 0x43),
		PANEL_DCS(0x37, 0x44),
		PANEL_DCS(0x38, 0x40),
		PANEL_DCS(0x39, 0x00),
		PANEL_DCS(0x3A, 0x01),
		PANEL_DCS(0x3B, 0x48),
		PANEL_DCS(0x3D, 0x93),
		PANEL_DCS(0xAB, 0x44),
		PANEL_DCS(0xAC, 0x40),
		PANEL_DCS(0x4D, 0x21),
		PANEL_DCS(0x4E, 0x43),
		PANEL_DCS(0x4F, 0x65),
		PANEL_DCS(0x50, 0x87),
		PANEL_DCS(0x51, 0x78),
		PANEL_DCS(0x52, 0x56),
		PANEL_DCS(0x53, 0x34),
		PANEL_DCS(0x54, 0x21),
		PANEL_DCS(0x55, 0x83),
		PANEL_DCS(0x56, 0x08),
		PANEL_DCS(0x58, 0x21),
		PANEL_DCS(0x59, 0x40),
		PANEL_DCS(0x5A, 0x09),
		PANEL_DCS(0x5B, 0x48),
		PANEL_DCS(0x5E, 0x00, 0x10),
		PANEL_DCS(0x5F, 0x00),
		PANEL_DCS(0x7A, 0x00),
		PANEL_DCS(0x7B, 0x00),
		PANEL_DCS(0x7C, 0x00),
		PANEL_DCS(0x7D, 0x00),
		PANEL_DCS(0x7E, 0x20),
		PANEL_DCS(0x7F, 0x3C),
		PANEL_DCS(0x80, 0x00),
		PANEL_DCS(0x81, 0x00),
		PANEL_DCS(0x82, 0x08),
		PANEL_DCS(0x97, 0x02),
		PANEL_DCS(0xC5, 0x10),
		PANEL_DCS(0xDA, 0x05),
		PANEL_DCS(0xDB, 0x01),
		PANEL_DCS(0xDC, 0x7A),
		PANEL_DCS(0xDD, 0x55),
		PANEL_DCS(0xDE, 0x27),
		PANEL_DCS(0xDF, 0x01),
		PANEL_DCS(0xE0, 0x7A),
		PANEL_DCS(0xE1, 0x01),
		PANEL_DCS(0xE2, 0x7A),
		PANEL_DCS(0xE3, 0x01),
		PANEL_DCS(0xE4, 0x7A),
		PANEL_DCS(0xE5, 0x01),
		PANEL_DCS(0xE6, 0x7A),
		PANEL_DCS(0xE7, 0x00),
		PANEL_DCS(0xE8, 0x00),
		PANEL_DCS(0xE9, 0x01),
		PANEL_DCS(0xEA, 0x7A),
		PANEL_DCS(0xEB, 0x01),
		PANEL_DCS(0xEE, 0x7A),
		PANEL_DCS(0xEF, 0x01),
		PANEL_DCS(0xF0, 0x7A),
		PANEL_DCS(0xFF, 0x25),
		PANEL_DCS(0xFB, 0x01),
		PANEL_DCS(0x05, 0x00),
		PANEL_DCS(0xF1, 0x10),
		PANEL_DCS(0x1E, 0x00),
		PANEL_DCS(0x1F, 0x09),
		PANEL_DCS(0x20, 0x46),
		PANEL_DCS(0x25, 0x00),
		PANEL_DCS(0x26, 0x09),
		PANEL_DCS(0x27, 0x46),
		PANEL_DCS(0x3F, 0x80),
		PANEL_DCS(0x40, 0x00),
		PANEL_DCS(0x43, 0x00),
		PANEL_DCS(0x44, 0x09),
		PANEL_DCS(0x45, 0x46),
		PANEL_DCS(0x48, 0x09),
		PANEL_DCS(0x49, 0x46),
		PANEL_DCS(0x5B, 0x80),
		PANEL_DCS(0x5C, 0x00),
		PANEL_DCS(0x5D, 0x01),
		PANEL_DCS(0x5E, 0x46),
		PANEL_DCS(0x61, 0x01),
		PANEL_DCS(0x62, 0x46),
		PANEL_DCS(0x68, 0x10),
		PANEL_DCS(0xFF, 0x26),
		PANEL_DCS(0xFB, 0x01),
		PANEL_DCS(0x00, 0xA1),
		PANEL_DCS(0x02, 0x31),
		PANEL_DCS(0x0A, 0xF2),
		PANEL_DCS(0x04, 0x28),
		PANEL_DCS(0x06, 0x30),
		PANEL_DCS(0x0C, 0x16),
		PANEL_DCS(0x0D, 0x0D),
		PANEL_DCS(0x0F, 0x00),
		PANEL_DCS(0x11, 0x00),
		PANEL_DCS(0x12, 0x50),
		PANEL_DCS(0x13, 0x56),
		PANEL_DCS(0x14, 0x57),
		PANEL_DCS(0x15, 0x00),
		PANEL_DCS(0x16, 0x10),
		PANEL_DCS(0x17, 0xA0),
		PANEL_DCS(0x18, 0x86),
		PANEL_DCS(0x22, 0x00),
		PANEL_DCS(0x23, 0x00),
		PANEL_DCS(0x19, 0x0D),
		PANEL_DCS(0x1A, 0x7F),
		PANEL_DCS(0x1B, 0x0C),
		PANEL_DCS(0x1C, 0xBF),
		PANEL_DCS(0x2A, 0x0D),
		PANEL_DCS(0x2B, 0x7F),
		PANEL_DCS(0x20, 0x00),
		PANEL_DCS(0x1D, 0x00),
		PANEL_DCS(0x1E, 0x78),
		PANEL_DCS(0x1F, 0x78),
		PANEL_DCS(0x2F, 0x03),
		PANEL_DCS(0x30, 0x78),
		PANEL_DCS(0x33, 0x78),
		PANEL_DCS(0x34, 0x66),
		PANEL_DCS(0x35, 0x11),
		PANEL_DCS(0x39, 0x10),
		PANEL_DCS(0x3A, 0x78),
		PANEL_DCS(0x3B, 0x06),
		PANEL_DCS(0xC8, 0x04),
		PANEL_DCS(0xC9, 0x84),
		PANEL_DCS(0xCA, 0x4E),
		PANEL_DCS(0xCB, 0x00),
		PANEL_DCS(0xA9, 0x50),
		PANEL_DCS(0xAA, 0x4F),
		PANEL_DCS(0xAB, 0x4D),
		PANEL_DCS(0xAC, 0x4A),
		PANEL_DCS(0xAD, 0x48),
		PANEL_DCS(0xAE, 0x46),
		PANEL_DCS(0xFF, 0x27),
		PANEL_DCS(0xFB, 0x01),
		PANEL_DCS(0xC0, 0x18),
		PANEL_DCS(0xC1, 0x00),
		PANEL_DCS(0xC2, 0x00),
		PANEL_DCS(0x56, 0x06),
		PANEL_DCS(0x58, 0x80),
		PANEL_DCS(0x59, 0x75),
		PANEL_DCS(0x5A, 0x00),
		PANEL_DCS(0x5B, 0x02),
		PANEL_DCS(0x5C, 0x00),
		PANEL_DCS(0x5D, 0x00),
		PANEL_DCS(0x5E, 0x20),
		PANEL_DCS(0x5F, 0x10),
		PANEL_DCS(0x60, 0x00),
		PANEL_DCS(0x61, 0x2E),
		PANEL_DCS(0x62, 0x00),
		PANEL_DCS(0x63, 0x01),
		PANEL_DCS(0x64, 0x43),
		PANEL_DCS(0x65, 0x2D),
		PANEL_DCS(0x66, 0x00),
		PANEL_DCS(0x67, 0x01),
		PANEL_DCS(0x68, 0x43),
		PANEL_DCS(0x98, 0x01),
		PANEL_DCS(0xB4, 0x03),
		PANEL_DCS(0x9B, 0xBD),
		PANEL_DCS(0xA0, 0x90),
		PANEL_DCS(0xAB, 0x1B),
		PANEL_DCS(0xBC, 0x0C),
		PANEL_DCS(0xBD, 0x28),
		PANEL_DCS(0xFF, 0x2A),
		PANEL_DCS(0xFB, 0x01),
		PANEL_DCS(0x22, 0x2F),
		PANEL_DCS(0x23, 0x08),
		PANEL_DCS(0x24, 0x00),
		PANEL_DCS(0x25, 0x65),
		PANEL_DCS(0x26, 0xF8),
		PANEL_DCS(0x27, 0x00),
		PANEL_DCS(0x28, 0x1A),
		PANEL_DCS(0x29, 0x00),
		PANEL_DCS(0x2A, 0x1A),
		PANEL_DCS(0x2B, 0x00),
		PANEL_DCS(0x2D, 0x1A),
		PANEL_DCS(0x64, 0x96),
		PANEL_DCS(0x65, 0x00),
		PANEL_DCS(0x66, 0x00),
		PANEL_DCS(0x6A, 0x96),
		PANEL_DCS(0x6B, 0x00),
		PANEL_DCS(0x6C, 0x00),
		PANEL_DCS(0x70, 0x92),
		PANEL_DCS(0x71, 0x00),
		PANEL_DCS(0x72, 0x00),
		PANEL_DCS(0xA2, 0x33),
		PANEL_DCS(0xA3, 0x30),
		PANEL_DCS(0xA4, 0xC0),
		PANEL_DCS(0xE8, 0x00),
		PANEL_DCS(0xFF, 0xF0),
		PANEL_DCS(0xFB, 0x01),
		PANEL_DCS(0x3A, 0x08),
		PANEL_DCS(0xFF, 0xD0),
		PANEL_DCS(0xFB, 0x01),
		PANEL_DCS(0x00, 0x33),
		PANEL_DCS(0x02, 0x77),
		PANEL_DCS(0x08, 0x01),
		PANEL_DCS(0x09, 0xBF),
		PANEL_DCS(0x28, 0x30),
		PANEL_DCS(0x2F, 0x33),
		PANEL_DCS(0xFF, 0x23),
		PANEL_DCS(0xFB, 0x01),
		PANEL_DCS(0x00, 0x80),
		PANEL_DCS(0x07, 0x00),
		PANEL_DCS(0xFF, 0x20),
		PANEL_DCS(0xFB, 0x01),
		PANEL_DCS(0x30, 0x00),
		PANEL_DCS(0xFF, 0x10),
		PANEL_DCS(0xB9, 0x01),
		PANEL_DCS(0xFF, 0x20),
		PANEL_DCS(0x18, 0x40),
		PANEL_DCS(0xFF, 0x10),
		PANEL_DCS(0xB9, 0x02),
		PANEL_DCS(0xFF, 0x10),
		PANEL_DCS(0xFB, 0x01),
		PANEL_DCS(0xBB, 0x13),
		PANEL_DCS(0x3B, 0x03, 0x96, 0x1A, 0x04, 0x04),
		PANEL_DCS(0x35, 0x00),
		PANEL_DCS(0x51, 0x0F, 0xFF),
		PANEL_DCS(0x53, 0x24),
		PANEL_DELAY(100),
		PANEL_DCS(0x11),
		PANEL_DELAY(200),
		PANEL_DCS(0x29),
		PANEL_DELAY(100),
		PANEL_END,
	},
};
