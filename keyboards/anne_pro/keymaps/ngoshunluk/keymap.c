/* Copyright 2019 Michiel Visser
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

/* Default Anne Pro layout, windows style */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │ Esc │     │     │     │     │     │     │     │     │     │     │     │     │   Bksp   │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┌--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │ Tab    │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │     │     │   \   │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----└┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │ Capslock│ A(w)│ S(a)│ D(c)│ F(s)│  G  │  H  │ J(s)│ K(c)│ L(a)│ ;(w)│     │    Enter   │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----└┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴------------┤
 * │ LShift   │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  <  │  >  │  ?  │      RShift     │
 * ├------┬---┴-┬---┴--┬--┴-----┴-----┴-----┴-----┴-----┴--┬--┴-----┼-----┴┬-------┬--------┤
 * │ LCtl │ LAlt│Esc(1)│                                   │ Entr(2)│ Bsp  │RWin(4)│ RCtl   │
 * └------┴-----┴------┴-----------------------------------┴--------┴------┴-------┴--------┘
 */
  [0] = LAYOUT(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
      KC_CAPS, LGUI_T(KC_A),    LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,    KC_H,    RSFT_T(KC_J),    RCTL_T(KC_K),    RALT_T(KC_L),    RGUI_T(KC_SCLN), KC_QUOT,          KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,
      KC_LCTL, KC_LALT, LT(1, KC_ESC),                   KC_SPACE,                                    LT(2, KC_ENT), KC_BSPC,   LT(4, KC_RGUI),   KC_RCTL
  ),
/* Function and Nav
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │Reset│     │     │     │     │     │     │     │     │     │     │     │     │    L3    │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┌--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │        │ F12 │  F7 │ F8  │ F9  │ Prt │ Ins │ Home│ PUp │ PDwn│ End │     │     │       │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----└┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │ F11 │ F4  │ F5  │ F6  │ Scr │ Caps│Shift│ Ctrl│ Alt │ Win │     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----└┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴------------┤
 * │          │ F10 │ F1  │ F2  │ F3  │Pause│ Tab │ Left│ Down│ Up  │Right│                 │
 * ├------┬---┴-┬---┴--┬--┴-----┴-----┴-----┴-----┴-----┴--┬--┴-----┼-----┴┬-------┬--------┤
 * │      │     │      │                                   │ Enter  │ Bsp  │       │        │
 * └------┴-----┴------┴-----------------------------------┴--------┴------┴-------┴--------┘
 */
  [1] = LAYOUT(
      RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(3),
      XXXXXXX, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, KC_INS, KC_HOME, KC_PGUP, KC_PGDN, KC_END, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_F11, KC_F4, KC_F5, KC_F6, KC_SLCK, KC_CAPS, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,          XXXXXXX,
      XXXXXXX, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS, KC_TAB, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,                   XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                                     KC_ENT, KC_BSPC, XXXXXXX, XXXXXXX
  ),
/* Numbers and Symbols
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │     │     │     │     │     │     │     │     │     │     │     │     │     │          │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┌--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │        │  [  │  7  │  8  │  9  │  ]  │ Redo│Paste│ Copy│ Cut │ Undo│     │     │       │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----└┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │  ;  │  4  │  5  │  6  │  =  │  `  │Shift│ Ctrl│ Alt │ Win │     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----└┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴------------┤
 * │          │  \  │  1  │  2  │  3  │  -  │  /  │  ,  │     │     │     │                 │
 * ├------┬---┴-┬---┴--┬--┴-----┴-----┴-----┴-----┴-----┴--┬--┴-----┼-----┴┬-------┬--------┤
 * │      │     │  .   │                 0                 │        │      │       │        │
 * └------┴-----┴------┴-----------------------------------┴--------┴------┴-------┴--------┘
 */
  [2] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_AGIN, KC_PSTE, KC_COPY, KC_CUT, KC_UNDO, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, KC_GRV, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,          XXXXXXX,
      XXXXXXX, KC_BSLS, KC_1, KC_2, KC_3, KC_MINS, KC_SLSH, KC_COMM, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,
      XXXXXXX, XXXXXXX, KC_DOT,                   KC_0,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
/* Bluetooth
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │Back │  P1 │  P2 │  P3 │  P4 │     │     │     │     │     │     │     │     │          │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┌--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │        │  R1 │  R2 │  R3 │  R4 │     │     │     │     │     │     │     │     │       │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----└┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │  F1 │  F2 │  F3 │  F4 │     │     │     │     │     │     │     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----└┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴------------┤
 * │          │     │     │     │     │     │     │     │     │     │     │                 │
 * ├------┬---┴-┬---┴--┬--┴-----┴-----┴-----┴-----┴-----┴--┬--┴-----┼-----┴┬-------┬--------┤
 * │      │     │      │                                   │        │      │       │        │
 * └------┴-----┴------┴-----------------------------------┴--------┴------┴-------┴--------┘
 */
  [3] = LAYOUT(
      TG(3),   APB_HC1, APB_HC2, APB_HC3, APB_HC4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, APB_LGC, APB_OFF, APB_ON,  XXXXXXX,
      XXXXXXX, APB_HS1, APB_HS2, APB_HS3, APB_HS4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, APB_HD1, APB_HD2, APB_HD3, APB_HD4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,
      APB_HLQ, XXXXXXX, XXXXXXX,                   XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
/* RGB
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │     │     │     │     │     │     │     │     │     │     │     │     │     │          │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┌--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │        │     │     │     │ rgb │ rat │ brt │ mod │     │     │     │     │     │       │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----└┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │     │     │     │     │     │     │     │     │     │     │     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----└┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴------------┤
 * │          │     │     │     │     │     │     │     │     │     │     │                 │
 * ├------┬---┴-┬---┴--┬--┴-----┴-----┴-----┴-----┴-----┴--┬--┴-----┼-----┴┬-------┬--------┤
 * │      │     │      │                                   │        │      │       │        │
 * └------┴-----┴------┴-----------------------------------┴--------┴------┴-------┴--------┘
 */
  [4] = LAYOUT(
      XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, APL_RGB, APL_RAT, APL_BRT, APL_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};
