#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "tap_dance.c"

enum layers {
    _BASE,
    _NUMBERS,
    _SYMBOLS,
    _ADJUST,
    _SPECIAL,
};

//
// Shorthand layers.
#define NUMS MO(_NUMBERS)
#define SYMS MO(_SYMBOLS)
#define SPECIAL OSL(_SPECIAL)

//
// Special keys.
#define SP_COPA LT(_BASE, KC_NO) // Copy / paste
#define SP_0SYM LT(_SYMBOLS, KC_0) // Symbol layer on hold / 0 on press.
#define SP_HYES MT(MOD_HYPR, KC_ESC) // Hyper on escape hold / normal escape on press (Hyper = CTRL & Shift & Alt & GUI)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * |Hy/Esc|  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   | ;/:  | '/"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |  Z   |  X   |  C   |  V   |  B   |  N   |  M   | ,/<  | ./>  |  Up  | //?  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |CO/PA |NUM/SY|    Space    | SYM  |Enter | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    SP_HYES,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
     KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_UP, KC_SLSH,
    KC_LCTL, KC_LALT, KC_LGUI, SP_COPA,    NUMS,  KC_SPC,  KC_SPC,    SYMS,  KC_ENT, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Numbers & Mouse emu.
 * ,-----------------------------------------------------------------------------------.
 * |PAGE-U| Home | M-U  | End  |SCRL-U|      |      |  7   |  8   |  9   |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |PAGE-D| M-L  | M-D  | M-R  |SCRL-D|      |      |  4   |  5   |  6   |L-CLCK|R-CLCK|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |SCRL-L|      |SCRL-R|      |      |      |  1   |  2   |  3   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |0/SYM |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBERS] = LAYOUT_planck_grid(
    KC_PGUP, KC_HOME, KC_MS_U,  KC_END, KC_WH_U, _______, _______,    KC_7,    KC_8,    KC_9, _______,  KC_DEL,
    KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______,    KC_4,    KC_5,    KC_6, KC_BTN1, KC_BTN2,
    _______, KC_WH_L, _______, KC_WH_R, _______, _______, _______,    KC_1,    KC_2,    KC_3, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, SP_0SYM, _______, _______, _______, _______
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      | `/~  |  *   | =/+  | {/}  |  &   |      |  F9  |  F10 |  F11 |  F12 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  $   |  %   | -/_  | (/)  | \/|  |      |  F5  |  F6  |  F7  |  F8  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  ^   |  @   |  #   | [/]  |  !   |      |  F1  |  F2  |  F3  |  F4  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT_planck_grid(
    _______,  KC_GRV, KC_ASTR,  KC_EQL, TD_CURL, KC_AMPR, _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
    _______,  KC_DLR, KC_PERC, KC_MINS, TD_PARL, KC_BSLS, _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,
    _______, KC_CIRC,   KC_AT, KC_HASH, TD_SQBR, KC_EXLM, _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | SPCL |      |      |      |      | RGB  | HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    SPECIAL, _______, _______, _______, _______, RGB_TOG, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Special (OSL)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |Debug |      |      |      |             |      |      |      |      |Sleep |
 * `-----------------------------------------------------------------------------------'
 */
[_SPECIAL] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP
)

};
/* clang-format on */

//
// Import QMK functions.
#include "functions.c"