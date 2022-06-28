/* Copyright 2020 illness072
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "features/caps_word.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_caps_word(keycode, record)) { return false; }
  return true;
}

enum layer_names {
    _BASE,
    _GAME,
    _NAV,
    _NUM,
    _FUN
};

enum combos {
  JKL_RBRC,
  UIO_EQL,
  JIL_MINS,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM rbrc_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM mins_combo[] = {KC_J, KC_I, KC_L, COMBO_END};

combo_t key_combos[] = {
  [JKL_RBRC] = COMBO(rbrc_combo, KC_RBRC),
  [UIO_EQL] = COMBO(eql_combo, KC_EQL),
  [JIL_MINS] = COMBO(mins_combo, KC_MINS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                                    ,-------+-------+-------+-------+-------+-------.
     KC_F13,   KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                                      KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  , DF(0),
  //|-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
     KC_NO,   KC_A  , LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G  ,                    KC_H  , RSFT_T(KC_J),  RCTL_T(KC_K),  RALT_T(KC_L),  RGUI_T(KC_SCLN), DF(1),
  //`-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------'
              KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                                      KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,
  //        `-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------'
                                      KC_NO,  OSL(2), KC_SPC, KC_ESC,     KC_ENT, KC_BSPC, OSL(3), KC_NO
  //                                `-------+-------+-------+-------'    `-------+-------+-------+-------'
  ),

  [_GAME] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                                    ,-------+-------+-------+-------+-------+-------.
     KC_F13, KC_LSFT, KC_Q,  KC_NO,  KC_E,   KC_T,                                          KC_Y,   KC_U,   KC_I,   KC_O,   KC_P, DF(0),
  //|-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
     KC_NO, KC_LCTL, KC_A,    KC_W,   KC_D,   KC_F,                                        KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, DF(1),
  //`-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
              KC_LALT, KC_TAB, KC_S,   KC_R,   KC_G,                                       KC_LBRC, KC_QUOT, KC_DOWN, KC_UP, KC_NO,
  //        `-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------'
                                      KC_NO, OSL(2), KC_SPC, KC_ESC,      KC_ENT, KC_BSPC, OSL(3), KC_NO
  //                                `-------+-------+-------+-------'    `-------+-------+-------+-------'
  ),

  [_NAV] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                                    ,-------+-------+-------+-------+-------+-------.
      KC_F13 , KC_NO, LCTL(KC_TAB), KC_NO, LCTL(KC_T), KC_NO,                                KC_NO, KC_LSFT,KC_LCTL,KC_LALT,KC_LGUI,KC_NO ,
  //|-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
      KC_NO , KC_TAB, KC_LEFT,  KC_UP, KC_RGHT, LCTL(LSFT(KC_R)),                          KC_NO, KC_HOME,KC_PGUP,KC_END, KC_NO,  KC_NO ,
  //`-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------'
             KC_NO, LCTL(LSFT(KC_TAB)), KC_DOWN, LCTL(KC_W), KC_NO,                        KC_NO, KC_NO, KC_PGDN, KC_NO,  KC_NO,
  //        `-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------'
                                      KC_NO, KC_TRNS, KC_SPC, KC_ESC,     KC_ENT, KC_BSPC, KC_TRNS, KC_NO
  //                                `-------+-------+-------+-------'    `-------+-------+-------+-------'
  ),

  [_NUM] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                                    ,-------+-------+-------+-------+-------+-------.
      KC_F13, KC_TILD, KC_7,   KC_8,   KC_9,  KC_MINS,                                     KC_LPRN,KC_QUOT,KC_DQUO,KC_PSLS,KC_RPRN, KC_NO,
  //|-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
      KC_NO, KC_GRV,  KC_4,   KC_5,   LSFT_T(KC_6), KC_EQL,                               KC_SCLN, RSFT_T(KC_DOT), KC_COMM,KC_QUES,KC_EXLM, KC_NO,
  //`-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------'
             KC_0,   KC_1,   KC_2,   KC_3,  KC_BSLS,                                     KC_LBRC, KC_AT, KC_AMPR, KC_DLR, KC_RBRC,
  //        `-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------'
                                      KC_NO, KC_TRNS, KC_SPC, KC_ESC,     KC_ENT, KC_BSPC, OSL(4), KC_NO
  //                                `-------+-------+-------+-------'    `-------+-------+-------+-------'
  ),

  [_FUN] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                                    ,-------+-------+-------+-------+-------+-------.
      KC_F13, KC_F12,  KC_F7,  KC_F8,  KC_F9,  KC_NO,                                       KC_NO, KC_INS, KC_DEL, KC_NO,  KC_NO, KC_NO,
  //|-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
      KC_NO, KC_F11,  KC_F4,  KC_F5,  KC_F6, KC_NO,                                      KC_NO, KC_LSFT,KC_LCTL,KC_LALT, KC_LGUI,KC_NO,
  //`-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------'
             KC_F10,  KC_F1,  KC_F2,  KC_F3, KC_NO,                                        KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,
  //        `-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------'
                                      KC_NO, KC_TRNS, KC_SPC, KC_ESC,     KC_ENT, KC_BSPC, KC_TRNS, KC_NO
  //                                `-------+-------+-------+-------'    `-------+-------+-------+-------'
  )
};

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
