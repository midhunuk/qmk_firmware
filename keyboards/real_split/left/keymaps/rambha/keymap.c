// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    ESC_TOGGLE = SAFE_RANGE,  // Define a custom keycode
};
bool is_tab_held = false;
uint16_t tab_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x6(
        KC_NO,  KC_Q,               KC_W,               KC_E,                KC_R,                  KC_T,
        KC_NO,  MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D),  MT(MOD_LCTL, KC_F),    KC_G,
        KC_NO,  KC_Z,               KC_X,               KC_C,                KC_V,                  KC_B,
        KC_NO,  KC_NO,              KC_NO,              ESC_TOGGLE,          LT(2, KC_TAB),         LT(1, KC_SPACE)
    ),
    [1] = LAYOUT_ortho_4x6(
        KC_NO,  KC_GRAVE,                       KC_7,               KC_8,                KC_9,                  KC_0,
        KC_NO,  MT(MOD_LGUI, KC_LEFT_BRACKET),  MT(MOD_LALT, KC_4), MT(MOD_LSFT, KC_5),  MT(MOD_LCTL, KC_6),    KC_RIGHT_BRACKET,
        KC_NO,  KC_BACKSLASH,                   KC_1,               KC_2,                KC_3,                  KC_EQUAL,
        KC_NO,  KC_NO,                          KC_NO,              ESC_TOGGLE,          LT(2, KC_TAB),         LT(1, KC_SPACE)
    ),
    [2] = LAYOUT_ortho_4x6(
        KC_NO,  KC_NO,       KC_NO,       KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE,
        KC_NO,  LCTL(KC_A),  LCTL(KC_S),  KC_NO,           LCTL(KC_F),        KC_NO,
        KC_NO,  LCTL(KC_Z),  LCTL(KC_X),  LCTL(KC_C),      LCTL(KC_V),        KC_NO,
        KC_NO,  KC_NO,       KC_NO,       ESC_TOGGLE,      LT(2, KC_TAB),     LT(1, KC_SPACE)
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_TOGGLE:
            if (record->event.pressed) {
                // Key press: start timer to detect if held
                tab_timer = timer_read();  
                is_tab_held = true;
            } else {
                // Key release: check if it was held long enough
                is_tab_held = false;  // Reset hold state
                if (timer_elapsed(tab_timer) < 200) {
                    // If released within 200ms, send escape
                    tap_code(KC_ESCAPE);
                } else {
                    // If held for more than 200ms, toggle Layer 1
                    layer_invert(1);
                }
            }
            return false;  // Skip further processing
    }
    return true;  // Process other keycodes normally
}