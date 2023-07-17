/**
 * Soryn layout for the Planck keyboard (inspired by Deft layout)
 */

#include QMK_KEYBOARD_H

enum planck_layers { _QWERTY, _LOWER, _RAISE, _ADJUST, _FN_KEYS };
enum planck_keycodes { QWERTY = SAFE_RANGE, BACKLIT };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define UML_AE RALT(KC_Q)
#define UML_OE RALT(KC_P)
#define UML_UE RALT(KC_Y)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc/~|  Q   |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |  A   |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ;/:  | '/"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |  Z   |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | //?  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | COPY |Lower |    Space    |Raise |Enter | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    QK_GESC,    KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_TAB,    KC_A,    KC_S,       KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,       KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
    KC_LCTL, KC_LALT, KC_LGUI,    C(KC_C),   LOWER,  KC_SPC,  KC_SPC,   RAISE,   KC_ENT, KC_LEFT, KC_DOWN,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Del  |      |      |      | -/_  |  <   |   >  | =/+  |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  $   |  @   |  [   |  (   |  {   |   }  |   )  |  ]   |  %   |  #   |  ^   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |  !   |  &   | \/|  |   *  |      |      | Pgup |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |PASTE |      |             |      |FN-LAY| Home | Pgdn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
     KC_DEL, _______, _______, _______, KC_MINS, KC_LABK, KC_RABK, KC_EQL,        _______, _______, _______, _______,
    _______,  KC_DLR,   KC_AT, KC_LBRC, KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN,       KC_RBRC, KC_PERC, KC_HASH, KC_CIRC,
    _______, _______, _______, _______, KC_EXLM, KC_AMPR, KC_BSLS, KC_ASTR,       _______, _______, KC_PGUP, _______,
    _______, _______, _______, C(KC_V), _______, _______, _______, _______, OSL(_FN_KEYS), KC_HOME, KC_PGDN,  KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Ä  |   Ö  |   Ü  |      |      |      |      |      |      | Vol+ | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | CUT  |      |             |      |      | Play | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    _______,  UML_AE,  UML_OE,  UML_UE, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_MPLY,
    _______, _______, _______, C(KC_X), _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_MNXT
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
    // Change lighting based on current upmost layer.
    switch (get_highest_layer(state)) {
        case _RAISE:
            rgblight_setrgb(26, 255, 210);
            break;
        case _LOWER:
            rgblight_setrgb(210, 26, 255);
            break;
        case _FN_KEYS:
            rgblight_setrgb(26, 210, 255);
            break;
        default: // for any other layers, or the default layer
            rgblight_setrgb (102, 26, 255);
            break;
    }

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
