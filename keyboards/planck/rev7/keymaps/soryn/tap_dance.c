//
// Tap-dance declarations.
enum {
    TD_PARARENTHESES,
    TD_CURLY_BRACKETS,
    TD_SQUARE_BRACKETS,
};

//
// Tap-dance action definitions.
tap_dance_action_t tap_dance_actions[] = {
    [TD_PARARENTHESES] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_CURLY_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_SQUARE_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};

//
// Shorthand keycodes.
#define TD_PARL TD(TD_PARARENTHESES)
#define TD_CURL TD(TD_CURLY_BRACKETS)
#define TD_SQBR TD(TD_SQUARE_BRACKETS)