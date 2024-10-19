// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │
     * ├───┼───┼───┼───┼───┼───┤
     * │Bsp│ A │ S │ D │ F │ G │
     * ├───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │
     * ├───┼───┼───┼───┼───┼───┤
     * │Ctl│App│GUI│Alt│Spc│Spc│
     * └───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_4x6(
        KC_Y,     KC_U,  KC_I,         KC_O,     KC_P,         KC_BSPC,
        KC_H,     KC_J,  KC_K,         KC_L,     KC_SEMICOLON, KC_G,
        KC_B,     KC_N,  KC_M,         KC_COMMA, KC_DOT,       KC_SLASH,
        KC_SPACE, MO(1), KC_RIGHT_GUI, KC_NO,    KC_NO,        KC_NO
    )
};
