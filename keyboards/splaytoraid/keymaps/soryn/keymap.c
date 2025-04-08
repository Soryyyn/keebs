// Copyright 2024 Conor Burns (@Conor-Burns)
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NAVIGATION,
    _SYMBOLS,
    _NUMBERS,
    _FUNCTIONS
};

// Homerow mods
// Left side
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)
// Right side
#define GUI_SCLN RGUI_T(KC_SCLN)
#define ALT_L LALT_T(KC_L)
#define CTL_K RCTL_T(KC_K)
#define SFT_J RSFT_T(KC_J)

// Layer triggers
#define TAB_NAV LT(_NAVIGATION, KC_TAB)
#define ENT_SYM LT(_SYMBOLS, KC_ENT)
#define BSP_NUM LT(_NUMBERS, KC_BSPC)
#define DEL_FUN LT(_FUNCTIONS, KC_DEL)
#define TAB_NAV LT(_NAVIGATION, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_40(
                 KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
     KC_ESC,    GUI_A,    ALT_S,    CTL_D,    SFT_F,     KC_G,               KC_H,    SFT_J,    CTL_K,    ALT_L, GUI_SCLN,  KC_BSLS,
    KC_CAPS,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_QUOT,
                                  KC_RALT,  TAB_NAV,   KC_SPC,            ENT_SYM,  BSP_NUM,  DEL_FUN
  ),

  [_NAVIGATION] = LAYOUT_40(
              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_UNDO,  KC_PSTE,  KC_COPY,   KC_CUT, S(KC_UNDO),
    XXXXXXX,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  XXXXXXX,            KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,    XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,    XXXXXXX,  XXXXXXX,
                                  XXXXXXX,  XXXXXXX,  XXXXXXX,             KC_ENT,  KC_BSPC,   KC_DEL
  ),

  [_SYMBOLS] = LAYOUT_40(
             S(KC_LBRC), S(KC_7), S(KC_8),   S(KC_9),  S(KC_RBRC),        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX, S(KC_SCLN), S(KC_4), S(KC_5),   S(KC_6),   S(KC_EQL),        XXXXXXX,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX,
    XXXXXXX,  S(KC_GRV), S(KC_1), S(KC_2),   S(KC_3),  S(KC_BSLS),        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                S(KC_DOT),   S(KC_0),  S(KC_MINS),        XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [_NUMBERS] = LAYOUT_40(
              KC_LBRC,     KC_7,     KC_8,     KC_9,  KC_RBRC,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  KC_SCLN,     KC_4,     KC_5,     KC_6,   KC_EQL,            XXXXXXX,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX,
    XXXXXXX,   KC_GRV,     KC_1,     KC_2,     KC_3,  KC_BSLS,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                   KC_DOT,     KC_0,  KC_MINS,            XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [_FUNCTIONS] = LAYOUT_40(
               KC_F12,    KC_F7,    KC_F8,    KC_F9,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   KC_F11,    KC_F4,    KC_F5,    KC_F6,  XXXXXXX,            XXXXXXX,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX,
    XXXXXXX,   KC_F10,    KC_F1,    KC_F2,    KC_F3,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                   KC_APP,   KC_TAB,   KC_SPC,            XXXXXXX,  XXXXXXX,  XXXXXXX
  )
};


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAVIGATION] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SYMBOLS] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUMBERS] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
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
