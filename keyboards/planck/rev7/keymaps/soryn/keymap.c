#include QMK_KEYBOARD_H
#include "os_detection.h"

enum layers {
    _BASE,
    _LOWER,
    _NUMBERS,
    _SYMBOLS,
    _RAISE,
    _ADJUST,
    _FN_KEYS
};

#define LOWER MO(_LOWER)
#define NUMS MO(_NUMBERS)
#define SYMS MO(_SYMBOLS)
#define RAISE MO(_RAISE)
#define FN_KEYS OSL(_FN_KEYS)

#define UML_AE RALT(KC_Q)
#define UML_OE RALT(KC_P)
#define UML_UE RALT(KC_Y)

#define MT_COPA LT(0, KC_NO)

// Numbers layer mod-taps.
#define MT_P0SY LT(0, KC_P0)

// Tap-dance keys.
enum {
    TD_PARARENTHESES,
    TD_CURLY_BRACKETS,
    TD_SQUARE_BRACKETS
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
 * | Esc  |  Q   |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |  A   |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ;/:  | '/"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |  Z   |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | //?  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |CO/PA | NUMS |    Space    | SYMS |Enter | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
     KC_ESC,    KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_TAB,    KC_A,    KC_S,       KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,       KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
    KC_LCTL, KC_LALT, KC_LGUI,    MT_COPA,    NUMS,  KC_SPC,  KC_SPC,    SYMS,   KC_ENT, KC_LEFT, KC_DOWN,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      | -/_  |  <   |   >  | =/+  |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  $   |  @   |  [   |  (   |  {   |   }  |   )  |  ]   |  %   |  #   |  ^   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |  !   |  &   | \/|  |   *  |      |      | Pgup |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |FN-LAY| Home | Pgdn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, _______, _______, _______, KC_MINS, KC_LABK, KC_RABK, KC_EQL,  _______, _______, _______, KC_DEL,
    _______,  KC_DLR,   KC_AT, KC_LBRC, KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, KC_RBRC, KC_PERC, KC_HASH, KC_CIRC,
    _______, _______, _______, _______, KC_EXLM, KC_AMPR, KC_BSLS, KC_ASTR, _______, _______, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, FN_KEYS, KC_HOME, KC_PGDN,  KC_END
),

/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  *   |  -   |  {   |  }   |      |  7   |  8   |  9   |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  /   |  +   |  (   |  )   |      |  4   |  5   |  6   |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |  .   |  [   |  ]   |      |  1   |  2   |  3   | Pgup |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |0/SYM |      | Home | Pgdn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBERS] = LAYOUT_planck_grid(
    _______, _______, KC_PAST, KC_PMNS, KC_LCBR, KC_RCBR, _______,   KC_P7,   KC_P8,   KC_P9, _______,  KC_DEL,
    _______, _______, KC_PSLS, KC_PPLS, KC_LPRN, KC_RPRN, _______,   KC_P4,   KC_P5,   KC_P6, _______, _______,
    _______, _______, _______, KC_PDOT, KC_LBRC, KC_RBRC, _______,   KC_P1,   KC_P2,   KC_P3, KC_PGUP, _______,
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

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Ä  |   Ö  |   Ü  |      |      |      |      |      |      | Vol+ | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Play | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    _______,  UML_AE,  UML_OE,  UML_UE, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_MNXT
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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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

        //
        // Numpad 0 on and layer raise on hold.
        case MT_P0SY:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_P0);
            } else if (record->event.pressed) {
                layer_on(_RAISE);
            }

            return false;
            break;
    }

    return true;
}