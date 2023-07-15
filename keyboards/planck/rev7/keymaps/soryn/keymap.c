/**
 * Soryn layout for the Planck keyboard (inspired by Deft layout) sd ssdfsdfsdf
 */

#include QMK_KEYBOARD_H

enum planck_layers { _QWERTY, _LOWER, _RAISE, _ADJUST };
enum planck_keycodes { QWERTY = SAFE_RANGE, BACKLIT };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define UML_AE RALT(KC_Q)
#define UML_OE RALT(KC_P)
#define UML_UE RALT(KC_Y)

/*
 * Tap-dance configuration.
 */
enum {
    TD_CP = SAFE_RANGE
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_CP] = ACTION_TAP_DANCE_DOUBLE(C(KC_C), C(KC_V)),
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  Q   |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |  A   |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |  Z   |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | CPC  |Lower |    Space    |Raise |Enter | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
     KC_ESC,    KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_TAB,    KC_A,    KC_S,       KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,       KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
    KC_LCTL, KC_LALT, KC_LGUI,  TD(TD_CP),   LOWER,  KC_SPC,  KC_SPC,   RAISE,   KC_ENT, KC_LEFT, KC_DOWN,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Del  | Alt1 | Alt2 | Alt3 | Alt4 |  (   |  )   | Num7 | Num8 | Num9 | Num0 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  `   |  \   |  =   |  -   |  <   |  >   | Num4 | Num5 | Num6 | Num. | NumL |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Num/ | Num* | Num- | Num+ |  [   |  ]   | Num1 | Num2 | Num3 | Pgup | Num= |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | NumE | Home | Pgdn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
     KC_DEL, A(KC_1), A(KC_2), A(KC_3), A(KC_4), S(KC_9), S(KC_0),   KC_P7,   KC_P8,   KC_P9,   KC_P0, _______,
    _______,  KC_GRV, KC_BSLS,  KC_EQL, KC_MINS,S(KC_COMM),S(KC_DOT),   KC_P4,   KC_P5,   KC_P6, KC_PDOT, KC_NUM,
    _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_LBRC, KC_RBRC,   KC_P1,   KC_P2,   KC_P3, KC_PGUP, KC_PEQL,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PENT, KC_HOME,KC_PGDN,  KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Ä  |   Ö  |   Ü  |      |      |      |      |      |      | Vol+ | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Play | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    _______,  UML_AE,  UML_OE,  UML_UE, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_MNXT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |Debug |      |      |      | RGB  | HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |Sleep |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    QK_BOOT, DB_TOGG, _______, _______, _______, RGB_TOG, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP
)

};
/* clang-format on */

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
