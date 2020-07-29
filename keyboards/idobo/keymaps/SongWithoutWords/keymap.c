/* Copyright 2018 Milton Griffin
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


enum Layer {
  BASE,
  SYMB,
  MDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
.--------------------------------------------------------------------------------------------------------------------------------------.
| Esc    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BSpace |
|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
| Tab    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | \      |
|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
| LShift | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | '      |
|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
| LCtrl  | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RShift |
|--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
| LCtrl  | `~     | '"     | LGui   | Alt    | Space  | L1     | L2     | L1     | Enter  | Left   | Down   | Up     | Right  | RCtrl  |
'--------------------------------------------------------------------------------------------------------------------------------------'
*/

[BASE] = LAYOUT_ortho_5x15(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH,
  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_GRV,  KC_QUOT, KC_LGUI, KC_LALT, KC_SPC,  MO(SYMB),MO(MDIA),MO(SYMB),KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_RCTL
),

/* SYMBOLS
 * .-----------------------------------------------------------------------------------------------------------------------------------------------------.
 * |         | F1      | F2      | F3      | F4      | F5      |         |         |         | F6      | F7      | F8      | F9      | F10     | Delete  |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         | <       | {       | \       | ~       |         |         |         | %       | @       | }       | >       | F11     | F12     |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         | '       | =       | -       | (       | +       |         |         |         | *       | )       | _       | /       | "       |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         | `       | ?       | #       | [       | |       |         |         |         | &       | ]       | $       | !       | ^       |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------------'
 */

[SYMB] = LAYOUT_ortho_5x15(

// .-----------------------------------------------------------------------------------------------------------------------------------------------------.
     _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , _______ , _______ , _______ , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_DEL  ,
// |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     _______ , _______ , KC_LT   , KC_LCBR , KC_BSLS , KC_TILDE, _______ , _______ , _______ , KC_PERC , KC_AT   , KC_RCBR , KC_GT   , KC_F11  , KC_F12  ,
// |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     _______ , KC_QUOT , KC_EQUAL, KC_MINUS, KC_LPRN , KC_PLUS , _______ , _______ , _______ , KC_ASTR , KC_RPRN , KC_UNDS , KC_SLSH , KC_DQUO , _______ ,
// |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     _______ , KC_GRV  , KC_QUES , KC_HASH , KC_LBRC , KC_PIPE , _______ , _______ , _______ , KC_AMPR , KC_RBRC , KC_DLR  , KC_EXLM , KC_CIRC , _______ ,
// |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
// '-----------------------------------------------------------------------------------------------------------------------------------------------------'
),


/* MEDIA
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG |        | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

[MDIA] = LAYOUT_ortho_5x15(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, \
  KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______, \
  KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______, \
  _______, _______, RGB_TOG, _______, RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, _______, _______, _______, _______  \
),
};

static bool g_keyDownEscape = false;
static bool g_keyDownBSpace = false;
static bool g_keyDownLCtrl  = false;
static bool g_keyDownRCtrl  = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  const bool pressed = record->event.pressed;

  switch (keycode) {
  case KC_ESC:
    g_keyDownEscape = pressed;
    break;
  case KC_BSPC:
    g_keyDownBSpace = pressed;
    break;
  case KC_LCTRL:
    g_keyDownLCtrl = pressed;
    break;
  case KC_RCTRL:
    g_keyDownRCtrl = pressed;
    break;
  }

  if (pressed) {
    switch (keycode) {
    case KC_ESC:
    case KC_BSPC:
    case KC_LCTRL:
    case KC_RCTRL:
      if (g_keyDownEscape && g_keyDownBSpace && g_keyDownLCtrl && g_keyDownRCtrl) {
        reset_keyboard();
        return false;
      }
    }
  }

  return true;
}
