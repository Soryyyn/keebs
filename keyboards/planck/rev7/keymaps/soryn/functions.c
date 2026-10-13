//
// Turn on adjust layer when holding down both raise and lower.
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUMBERS, _SYMBOLS, _ADJUST);
}

//
// OS mode: `Auto` follows the detected host OS, `Mac` / `Win` force it.
enum os_modes {
    OS_MODE_AUTO,
    OS_MODE_MAC,
    OS_MODE_WIN,
    OS_MODE_COUNT,
};

static uint8_t os_mode = OS_MODE_AUTO;

//
// Unknown hosts are treated as Mac, everything that isn't Apple as Windows.
static bool is_mac_os(os_variant_t os) {
    return os == OS_MACOS || os == OS_IOS || os == OS_UNSURE;
}

static bool is_mac(void) {
    switch (os_mode) {
        case OS_MODE_MAC:
            return true;
        case OS_MODE_WIN:
            return false;
        default:
            return is_mac_os(detected_host_os());
    }
}

//
// Flash all LEDs on OS detection (Auto mode) or when cycling the OS mode:
// blue = Mac, green = Win, white = back to Auto.
#define OS_FLASH_DURATION 600

static bool     os_flash_active = false;
static uint32_t os_flash_timer;
static uint8_t  os_flash_r, os_flash_g, os_flash_b;

static void os_flash(uint8_t r, uint8_t g, uint8_t b) {
    os_flash_r      = r;
    os_flash_g      = g;
    os_flash_b      = b;
    os_flash_timer  = timer_read32();
    os_flash_active = true;
}

static void os_flash_for(bool mac) {
    if (mac) {
        os_flash(0, 0, 160);
    } else {
        os_flash(0, 160, 0);
    }
}

bool process_detected_host_os_user(os_variant_t os) {
    if (os_mode == OS_MODE_AUTO) {
        os_flash_for(is_mac_os(os));
    }
    return true;
}

bool rgb_matrix_indicators_user(void) {
    if (os_flash_active) {
        if (timer_elapsed32(os_flash_timer) > OS_FLASH_DURATION) {
            os_flash_active = false;
        } else {
            rgb_matrix_set_color_all(os_flash_r, os_flash_g, os_flash_b);
        }
    }
    return true;
}

//
// Send the matching shortcut for the active OS.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case HOST_LOCK:
            tap_code16(is_mac() ? LCTL(LGUI(KC_Q)) : LGUI(KC_L));
            return false;
        case HOST_SHTA:
            tap_code16(is_mac() ? LSG(KC_4) : LSG(KC_S));
            return false;
        case HOST_SHTT:
            tap_code16(is_mac() ? LSG(KC_5) : LSG(KC_R));
            return false;
        case HOST_CYC:
            os_mode = (os_mode + 1) % OS_MODE_COUNT;
            if (os_mode == OS_MODE_AUTO) {
                os_flash(160, 160, 160);
            } else {
                os_flash_for(is_mac());
            }
            return false;
    }
    return true;
}
