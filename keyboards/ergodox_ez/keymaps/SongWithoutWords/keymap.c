#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    QWERTY,
    COLEMAK,
    SYMB,
    NAVI, // TODO
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  | BSpace |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| PrScr|           |      |------+------+------+------+------+--------|
 * | LCtrl  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L1  |  `~  |  '"  | LGui | Alt  |                                       | Left | Down |  Up  |Right | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Vol- | Vol+ |       | Prev |  Next  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Mute |       | Play |        |      |
 *                                 | Space|  L1  |------|       |------| L1     | Enter|
 *                                 |      |      | L2   |       | L2   |        |      |
 *                                 `--------------------'       `----------------------'
 */
[QWERTY] = LAYOUT_ergodox_pretty(
  KC_ESC,          KC_1,        KC_2,          KC_3,    KC_3,    KC_4,    KC_NO,                KC_NO,     KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,  KC_EQL,            KC_BSPC,
  KC_TAB,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_NO,                KC_NO,     KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,              KC_BSLASH,
  KC_LSFT,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                     KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,           KC_QUOT,
  KC_LCTRL,        KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_LCBR,              KC_NO,     KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,           KC_RSFT,
  MO(SYMB),        KC_GRV,      KC_QUOT,       KC_LGUI, KC_LALT,                                                    KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT,          MO(SYMB),

                                                               KC_VOLD,   KC_VOLU,              KC_MPRV,   KC_MNXT,
                                                                          KC_MUTE,              KC_MPLY,
                                                       KC_SPC, MO(SYMB),  MO(NAVI),             MO(NAVI),  MO(SYMB),  KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * Inspired by https://www.dialectical-computing.de/blog/blog/2017/01/29/a-better-coder-layout-for-the-ergodox-ez-keyboard/
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   Del  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |   <  |   {  |   \  |   ~  |      |           |      |   %  |   @  |   }  |   >  |  F11 |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   '  |   =  |   -  |   (  |   +  |------|           |------|   *  |   )  |   _  |   /  |   "  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   `  |   ?  |   #  |   [  |   |  |      |           |      |   &  |   ]  |   $  |   !  |   ^  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright| EPRM |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
  _______, _______, KC_LT,   KC_LCBR, KC_BSLS, KC_TILD, _______,     _______, KC_PERC, KC_AT,   KC_RBRC, KC_GT,   KC_F11,  KC_F12,
  _______, KC_QUOT, KC_EQL,  KC_MINS, KC_LPRN, KC_PLUS,                       KC_ASTR, KC_RPRN, KC_UNDS, KC_SLSH, KC_DQUO, _______,
  _______, KC_GRV,  KC_QUES, KC_HASH, KC_LBRC, KC_PIPE, _______,     _______, KC_AMPR, KC_RBRC, KC_DLR,  KC_EXLM, KC_CIRC, _______,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,

                                                RGB_VAD, RGB_VAI,     RGB_HUD, RGB_HUI,
                                                         RGB_TOG,     RGB_MOD,
                                       _______, _______, _______,     _______, _______, _______
),
/* Keymap 2: Navigation (TODO)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAVI] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, RESET,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
