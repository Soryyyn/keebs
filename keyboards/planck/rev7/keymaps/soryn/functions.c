//
// After most things are setup with the keyboard, this step gets executed.
//
// Changes the unicode input mode to either macos or windows.
// void keyboard_post_init_user() {}

//
// Turn on adjust layer when holding down both raise and lower.
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUMBERS, _SYMBOLS, _ADJUST);
}

//
// Handle keypresses.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    os_variant_t detected_os = detected_host_os();

    switch (keycode) {
        //
        // Single copy/paste key.
        // Copy on tap / paste on hold.
        //
        // Also changes to command + <key> on macos.
        case COP_PAS:
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