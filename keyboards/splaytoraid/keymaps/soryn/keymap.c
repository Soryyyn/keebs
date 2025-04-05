// Copyright 2024 Conor Burns (@Conor-Burns)
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _SYMBOLS,
    _NUMBERS,
    _FUNCTIONS
};

// Homerow mods
// Left side
#define HRM_A MT(KC_LGUI, KC_A)
#define HRM_S MT(KC_LALT, KC_S)
#define HRM_D MT(KC_LCTL, KC_D)
#define HRM_F MT(KC_LSFT, KC_F)
// Right side
#define HRM_SC MT(KC_LGUI, KC_SCLN)
#define HRM_L MT(KC_LALT, KC_L)
#define HRM_K MT(KC_LCTL, KC_K)
#define HRM_J MT(KC_LSFT, KC_J)

// Layer triggers
#define ENT_SYM LT(_SYMBOLS, KC_ENT)
#define BSP_NUM LT(_NUMBERS, KC_BSPC)
#define DEL_FUN LT(_FUNCTIONS, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_40(
              KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    KC_ESC,   HRM_A,    HRM_S,    HRM_D,    HRM_F,    KC_G,               KC_H,     HRM_J,    HRM_K,    HRM_L,    HRM_SC,   KC_BSLS,
    KC_CAPS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_QUOT,
                                  KC_RALT,  KC_TAB,   KC_SPC,             ENT_SYM,  BSP_NUM,  DEL_FUN
  ),

  [_SYMBOLS] = LAYOUT_40(
              _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                  _______,  _______,  _______,            _______,  _______,  _______
  ),

  [_NUMBERS] = LAYOUT_40(
              KC_LBRC,     KC_7,     KC_8,     KC_9,  KC_RBRC,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  KC_SCLN,     KC_4,     KC_5,     KC_6,   KC_EQL,            XXXXXXX,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX,
    XXXXXXX,   KC_GRV,     KC_1,     KC_2,     KC_3,  KC_BSLS,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                   KC_DOT,     KC_0,  KC_MINS,            XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [_FUNCTIONS] = LAYOUT_40(
              _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                  _______,  _______,  _______,            _______,  _______,  _______
  )
};


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUMBERS] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SYMBOLS] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FUNCTIONS] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if(active) { tap_code(KC_MPLY); } else {  }
            break;
    }
    return true;
}
