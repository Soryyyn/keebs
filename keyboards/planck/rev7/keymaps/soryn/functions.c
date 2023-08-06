void fn_td_uml_ae (tap_dance_state_t *state, void *user_data) {
    // on single press
    if (state->count == 1) {
        tap_code16(KC_A);
        reset_tap_dance(state);
    }
    // on double press
    else if (state->count == 2) {
        // check if shift is pressed
        if(get_mods() & MOD_BIT(KC_LSFT)) {
            SEND_STRING("Ä");
        } else {
            SEND_STRING("ä");
        }
    }
}