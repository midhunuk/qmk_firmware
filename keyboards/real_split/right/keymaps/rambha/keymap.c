// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x6(
        KC_Y,     KC_U,                 KC_I,                 KC_O,               KC_P,                       KC_NO,
        KC_H,     MT(MOD_RCTL, KC_J),   MT(MOD_RSFT, KC_K),   MT(MOD_RALT, KC_L), MT(MOD_RGUI, KC_SEMICOLON), KC_NO,
        KC_N,     KC_M,                 KC_COMMA,             KC_DOT,             KC_SLASH,                   KC_NO,
        KC_ENTER, KC_BACKSPACE,         MT(TG(1), KC_DELETE), KC_NO,              KC_NO,                      KC_NO
    ),
    [1] = LAYOUT_ortho_4x6(
        KC_F8,      KC_F9,                 KC_F10,               KC_F11,                 KC_F12,                 KC_NO,
        KC_LEFT,    MT(MOD_RCTL, KC_DOWN), MT(MOD_RSFT, KC_UP),  MT(MOD_RALT, KC_RIGHT), MT(MOD_RGUI, KC_MINUS), KC_NO,
        KC_F1,      KC_F2,                 KC_F3,                KC_F4,                  KC_F5,                  KC_NO,
        KC_ENTER,   KC_BACKSPACE,          MT(TG(1), KC_DELETE), KC_NO,                  KC_NO,                  KC_NO
    )
};