// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum aerondight_layers {
    L_QWE,
    L_SYM,
    L_NUM,
    L_NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [L_QWE] = LAYOUT_ortho_4x10(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,       KC_Y,  KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,       KC_H,  RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), KC_SCLN,
        LGUI_T(KC_Z), KC_X,         KC_C,         KC_V,         KC_B,       KC_N,  KC_M,         KC_COMM,      KC_DOT, RGUI_T(KC_SLSH),
        KC_NO,      TO(L_NUM),  LT(L_NAV, KC_TAB), KC_SPC,      KC_NO,      KC_NO, KC_ENT,       KC_BSPC,      OSL(L_SYM),    KC_NO
    ),

    [L_SYM] = LAYOUT_ortho_4x10(
        KC_EXLM, KC_AT,   KC_HASH,           KC_DLR,    KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN,
        KC_UNDS, KC_LABK, KC_LBRC,           KC_LCBR,   KC_LPRN,     KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,  KC_COLN,
        KC_GRV,  KC_TILD, KC_MINS,           KC_PLUS,   KC_EQL,      KC_DQUO, KC_QUOT, KC_PIPE, KC_BSLS,  KC_SLSH,
        KC_NO,   TO(L_QWE), LT(L_NAV, KC_TAB), KC_SPC,  KC_NO,       KC_NO,   KC_ENT,  KC_BSPC, TO(L_QWE),KC_NO
    ),

    [L_NAV] = LAYOUT_ortho_4x10(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_INS,
        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_DEL,
        KC_LGUI, KC_NO,   KC_NO,   KC_NO,   KC_NO,      MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT,  KC_CAPS,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ESC,     KC_NO,   MS_BTN1, MS_BTN2, MS_BTN3,  KC_NO
    ),

    [L_NUM] = LAYOUT_ortho_4x10(
       KC_F1,   KC_F2,         KC_F3,         KC_F4,         KC_F5,     KC_F8, KC_F9,     KC_F10,  KC_F11,  KC_F12,
       KC_1,    LALT_T(KC_2),  LSFT_T(KC_3),  LCTL_T(KC_4),  KC_5,      KC_6,  KC_7,      KC_8,    KC_9,    KC_0,
       KC_LGUI, KC_NO,         KC_MINS,       KC_PLUS,       KC_EQL,    KC_F6, KC_F7,     KC_COMM, KC_DOT,  KC_RGUI,
       KC_NO,   TO(L_QWE), LT(L_NAV, KC_TAB), KC_SPC,        KC_NO,     KC_NO, KC_ENT,    KC_BSPC, TO(L_QWE),KC_NO
    ),
};

const uint16_t PROGMEM esc_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM boot_combo[] = {KC_HOME, KC_END, COMBO_END};

combo_t key_combos[] = {
  COMBO(esc_combo, KC_ESC),
  COMBO(boot_combo, QK_BOOT),
};