// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    DELETE_TOGGLE = SAFE_RANGE,  // Define a custom keycode
};
bool is_tab_held = false;
uint16_t tab_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x6(
        KC_Y,            KC_U,                 KC_I,                 KC_O,               KC_P,                       KC_NO,
        KC_H,            MT(MOD_RCTL, KC_J),   MT(MOD_RSFT, KC_K),   MT(MOD_LALT, KC_L), MT(MOD_RGUI, KC_SEMICOLON), KC_NO,
        KC_N,            KC_M,                 KC_COMMA,             KC_DOT,             KC_SLASH,                   KC_NO,
        LT(1, KC_ENTER), LT(2, KC_BACKSPACE),  DELETE_TOGGLE,        KC_NO,              KC_NO,                      KC_NO
    ),
    [1] = LAYOUT_ortho_4x6(
        KC_QUOTE,          KC_F9,                 KC_F10,               KC_F11,                 KC_F12,                 KC_NO,
        KC_LEFT,           MT(MOD_RCTL, KC_DOWN), MT(MOD_RSFT, KC_UP),  MT(MOD_LALT, KC_RIGHT), KC_RIGHT_GUI,           KC_NO,
        KC_MINUS,          KC_F1,                 KC_F2,                KC_F3,                  KC_F4,                  KC_NO,
        LT(1, KC_ENTER),   LT(2, KC_BACKSPACE),   DELETE_TOGGLE,        KC_NO,                  KC_NO,                  KC_NO
    ),
    [2] = LAYOUT_ortho_4x6(
        MS_BTN1,          MS_WHLD,               MS_WHLU,              MS_ACL0,                MS_ACL2,  KC_NO,
        MS_LEFT,          MT(MOD_RCTL, MS_DOWN), MT(MOD_RSFT, MS_UP),  MT(MOD_LALT, MS_RGHT),  MS_BTN3,  KC_NO,
        MS_BTN2,          KC_F5,                 KC_F6,                KC_F7,                  KC_F8,    KC_NO,
        LT(1, KC_ENTER),  LT(2, KC_BACKSPACE),   DELETE_TOGGLE,        KC_NO,                  KC_NO,    KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DELETE_TOGGLE:
            if (record->event.pressed) {
                // Key press: start timer to detect if held
                tab_timer = timer_read();  
                is_tab_held = true;
            } else {
                // Key release: check if it was held long enough
                is_tab_held = false;  // Reset hold state
                if (timer_elapsed(tab_timer) < 200) {
                    // If released within 200ms, send delete
                    tap_code(KC_DELETE);
                } else {
                    // If held for more than 200ms, toggle Layer 1
                    layer_invert(1);    
                }
            }
            return false;  // Skip further processing
    }
    return true;  // Process other keycodes normally
}