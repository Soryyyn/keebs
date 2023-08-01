//
// Decide what to do depending if a key has been pressed or held.
//
// The bool in the callback is set to true if the key is being held.
// bool onPressAndHold(keyrecord_t *record, int (*action)(bool)) {
//     if (record->tap.count && record->event.pressed) {
//         action(false);
//     } else if (record->event.pressed) {
//         action(true);
//     }

//     return false;
// }

bool simpleOnPressAndHold(keyrecord_t *record, uint16_t onPressCode, uint16_t onHoldCode) {
    if (record->tap.count && record->event.pressed) {
        tap_code16(onPressCode);
    } else if (record->event.pressed) {
        tap_code16(onHoldCode);
    }

    return false;
}