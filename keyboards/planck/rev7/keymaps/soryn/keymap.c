#include QMK_KEYBOARD_H
#include "os_detection.h"

enum layers {
    _BASE,
    _NUMBERS,
    _SYMBOLS,
    _ADJUST,
    _FN_KEYS
};

enum unicodes {
    L_AE,
    U_AE,
    L_OE,
    U_OE,
    L_UE,
    U_UE
};

const uint32_t unicode_map[] PROGMEM = {
    [L_AE]  = 0x00E4,  // ä
    [U_AE] = 0x00C4,  // Ä
    [L_OE]  = 0x00F6,  // ö
    [U_OE] = 0x00D6,  // Ö
    [L_UE]  = 0x00FC,  // ü
    [U_UE] = 0x00DC,  // Ü
};

// Umlauts with unicode.
#define U_AE XP(L_AE, U_AE)
#define U_OE XP(L_OE, U_OE)
#define U_UE XP(L_UE, U_UE)

#define NUMS MO(_NUMBERS)
#define SYMS MO(_SYMBOLS)
#define FN_KEYS OSL(_FN_KEYS)

// Copy/paste shortcut
#define MT_COPA LT(_BASE, KC_NO)

// Numbers layer mod-taps.
#define MT_P0SY LT(_SYMBOLS, KC_P0)

// Tap-dance keys.
enum {
    // Braces.
    TD_PARARENTHESES,
    TD_CURLY_BRACKETS,
    TD_SQUARE_BRACKETS,
};

// Tap-dance definitions.
tap_dance_action_t tap_dance_actions[] = {
    [TD_PARARENTHESES] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_CURLY_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_SQUARE_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};

#define TD_PARL TD(TD_PARARENTHESES)
#define TD_CURL TD(TD_CURLY_BRACKETS)
#define TD_SQBR TD(TD_SQUARE_BRACKETS)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  Q   |   W  |   E  |   R  |   T  |   Y  | U/Ü  |   I  | O/Ö  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  | A/Ä  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ;/:  | '/"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |  Z   |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | //?  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |CO/PA | NUMS |    Space    | SYMS |Enter | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
     KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
     KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_UP, KC_SLSH,
    KC_LCTL, KC_LALT, KC_LGUI, MT_COPA,    NUMS,  KC_SPC,  KC_SPC,    SYMS,  KC_ENT, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  7   |  8   |  9   |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  4   |  5   |  6   |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  1   |  2   |  3   | Pgup |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |0/SYM |      | Home | Pgdn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBERS] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______,   KC_P7,   KC_P8,   KC_P9, _______,  KC_DEL,
    _______,    U_AE,    U_OE,    U_UE, _______, _______, _______,   KC_P4,   KC_P5,   KC_P6, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   KC_P1,   KC_P2,   KC_P3, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______, _______, MT_P0SY, _______, KC_HOME, KC_PGDN,  KC_END
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

/* Function Keys
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN_KEYS] = LAYOUT_planck_grid(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |M-LCLI| M-UP |M-RCLI|      | RGB  | HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |M-LEFT|M-DOWN|M-RIGH|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |Debug |      |      |      |             |      |      |      |      |Sleep |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, RGB_TOG, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP
)

};
/* clang-format on */

//
// Turn on adjust layer when holding down both raise and lower.
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUMBERS, _SYMBOLS, _ADJUST);
}

//
// Handle keypresses.
//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    os_variant_t detected_os = detected_host_os();

    switch (keycode) {

        // Single copy/paste key.
        // Copy on tap / paste on hold.
        //
        // Also changes to command + <key> on macos.
        case MT_COPA:
            if (record->tap.count && record->event.pressed) {
                switch (detected_os) {
                    case OS_MACOS:
                        tap_code16(G(KC_C));
                        break;
                    default:
                        tap_code16(C(KC_C));
                        break;
                }
            } else if (record->event.pressed) {
                switch (detected_os) {
                    case OS_MACOS:
                        tap_code16(G(KC_V));
                        break;
                    default:
                        tap_code16(C(KC_V));
                        break;
                }
            }

            return false;
            break;
    }

    return true;
}