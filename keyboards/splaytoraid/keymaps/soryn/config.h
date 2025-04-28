// Copyright 2024 Conor Burns (@Conor-Burns)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define VIAL_KEYBOARD_UID {0xCB, 0x00, 0x04, 0x00, 0x20, 0x04, 0xCA, 0xFE}
#define VIAL_UNLOCK_COMBO_ROWS { 5, 5 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 9 }

// Able to create 16 layers.
#define DYNAMIC_KEYMAP_LAYER_COUNT 16

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 180

// Turn of the backlight once the PC goes into sleep.
#define RGBLIGHT_SLEEP true

#define RETRO_TAPPING true

#define FORCE_NKRO true
