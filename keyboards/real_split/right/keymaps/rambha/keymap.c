// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x6(
        KC_Y,     KC_U,                 KC_I,               KC_O,               KC_P,                       KC_NO,
        KC_H,     MT(MOD_RCTL, KC_J),   MT(MOD_RSFT, KC_K), MT(MOD_RALT, KC_L), MT(MOD_RGUI, KC_SEMICOLON), KC_NO,
        KC_N,     KC_M,                 KC_COMMA,           KC_DOT,             KC_SLASH,                   KC_NO,
        KC_ENTER, TG(1),                KC_BACKSPACE,              KC_NO,              KC_NO,                      KC_NO
    ),
    [1] = LAYOUT_ortho_4x6(
        KC_NO,      KC_NO,              KC_NO,              KC_NO,              KC_NO,                 KC_NO,
        KC_6,       MT(MOD_RCTL, KC_7), MT(MOD_RSFT, KC_8), MT(MOD_RALT, KC_9), MT(MOD_RGUI, KC_0),    KC_NO,
        KC_NO,      KC_NO,              KC_NO,              KC_NO,              KC_NO,                 KC_NO,
        KC_ENTER,   TG(1),              KC_BACKSPACE,              KC_NO,              KC_NO,                 KC_NO
    )
};