// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x6(
        KC_NO,  KC_Q,               KC_W,               KC_E,               KC_R,                  KC_T,
        KC_NO,  MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F),    KC_G,
        KC_NO,  KC_Z,               KC_X,               KC_C,               KC_V,                  KC_B,
        KC_NO,  KC_NO,              KC_NO,              KC_ESCAPE,          TG(1),                 KC_SPACE
    ),
    [1] = LAYOUT_ortho_4x6(
        KC_NO,  KC_NO,              KC_NO,              KC_NO,              KC_NO,                 KC_NO,
        KC_NO,  MT(MOD_LGUI, KC_1), MT(MOD_LALT, KC_2), MT(MOD_LSFT, KC_3), MT(MOD_LCTL, KC_4),    KC_5,
        KC_NO,  KC_NO,              KC_NO,              KC_NO,              KC_NO,                 KC_NO,
        KC_NO,  KC_NO,              KC_NO,              KC_ESCAPE,          TG(1),                 KC_SPACE
    )
};
