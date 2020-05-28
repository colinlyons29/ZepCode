#include QMK_KEYBOARD_H
#include "version.h"

// Copyright (C) 2019  Colin Lyons
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD,
  HSV_172_255_255,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_215_255_128,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |  =   |           |   -  |   6  |   7  |   8  |   9  |   0  |  MO(1) |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' /LCmd |
 * |--------+------+------+------+------+------|  FN  |           |  FN  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Grv |  '"  | Ctrl | Left | Right|                                       |  Up  | Down |   [  |   ]  | TGL1 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.        ,-------------.
 *                                        | Menu |  Ins |       | PgUp |  __   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | LAlt |       | PgDn |        |      |
 *                                 | Space|Backsp|------|       |------|  Del   |Enter |
 *                                 |      |ace   | Esc  |       | Ctrl |        |      |
 *                                 `--------------------'       `----------------------'
 */
[0] = LAYOUT_ergodox(
  // left hand
  KC_ESCAPE,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_EQUAL,
  KC_TAB,       KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_LBRACKET,
  KC_CAPSLOCK,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,
  KC_LSHIFT,    KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_LGUI,
  KC_GRAVE,     KC_QUOTE,KC_LCTRL,KC_LEFT,KC_RIGHT,
                                      LALT_T(KC_APPLICATION),KC_INSERT,
                                                             KC_LALT,
                                      KC_SPACE,KC_BSPACE,LSFT_T(KC_ESCAPE),

  // right hand
  KC_MINUS,     KC_6,    KC_7,    KC_8,   KC_9,   KC_0,   MO(1),
  KC_RBRACKET,  KC_Y,    KC_U,    KC_I,   KC_O,   KC_P,   KC_BSLASH,
  KC_H,         KC_J,    KC_K,    KC_L,   LT(2,KC_SCOLON),LGUI_T(KC_QUOTE),
  KC_LGUI,      KC_N,    KC_M,    KC_COMMA,KC_DOT,LCTL_T(KC_SLASH),KC_RSHIFT,
  KC_UP,        KC_DOWN, KC_LBRACKET,KC_RBRACKET,TG(1),
  KC_PGUP,KC_UNDS,
  KC_PGDOWN,
  KC_RCTRL,KC_DELETE,KC_ENTER
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  LAlt   |   !  |   @  |   {  |   }  |   |  |  G   |           |      |   Up |   7  |   8  |   9  |   *  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LCtrl  |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |   TG2  |
 * |---------+------+------+------+------+------| Bksp |           |      |------+------+------+------+------+--------|
 * | LShift  |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |  Del   |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |  TG2  | TG3  |                                       |      |   0  | TG2  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |RGBTog|RGBTog|       |Animat| Anti |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright| Blue |       |Green |Hue+  |Hue-  |
 *                                 |ness+ |ness- |------|       |------|      |      |
 *                                 |      |      | Red  |       | Purp |      |      |
 *                                 `--------------------'       `--------------------'
 */
[1] = LAYOUT_ergodox(
  // left hand
  KC_ESCAPE,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F11,
  KC_LALT,      KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_G,
  KC_LCTRL,     KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,KC_GRAVE,
  KC_LSHIFT,    KC_PERC,  KC_CIRC,  KC_LBRACKET,KC_RBRACKET,KC_TILD,KC_BSPACE,
  KC_TRNS,KC_TRNS,KC_TRNS,TG(2),TG(3),
                                          RGB_TOG,    RGB_TOG,
                                          HSV_172_255_255,
                                          RGB_VAI,RGB_VAD,  HSV_0_255_255,

  // right hand
  KC_F12,   KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_TRNS,
  KC_TRNS,   KC_UP,    KC_7,     KC_8,     KC_9,     KC_KP_ASTERISK,KC_TRNS,
  KC_DOWN,   KC_4,     KC_5,     KC_6,     KC_PLUS,  TG(2),
  KC_TRNS,   KC_AMPR,  KC_1,     KC_2,     KC_3,     KC_BSLASH,KC_DELETE,
  KC_TRNS,   KC_0,     TG(2),    KC_EQUAL, KC_TRNS,
  RGB_MOD,    RGB_SLD,
  HSV_86_255_128,
  HSV_215_255_128,  RGB_HUI,RGB_HUD
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Version|      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |Accel0|Accel1|Accel2|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Down |       |      |Brwser|Brwser|
 *                                 | Lclk | Rclk |------|       |------| Fwd  |Back  |
 *                                 |      |      |  Up  |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[2] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MS_UP,   KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                  KC_TRNS,    KC_TRNS,
                                                              KC_MS_WH_UP,
                                                  KC_MS_BTN1, KC_MS_BTN2, KC_MS_WH_DOWN,

  // right hand
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
  KC_TRNS,      KC_TRNS,      KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRNS,      KC_TRNS,
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_MEDIA_PLAY_PAUSE,
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  KC_TRNS,  KC_TRNS,
  KC_AUDIO_VOL_UP,      KC_AUDIO_VOL_DOWN,      KC_AUDIO_MUTE,      KC_TRNS,      KC_TRNS,
  KC_TRNS,      KC_TRNS,
  KC_TRNS,
  KC_TRNS,      KC_WWW_BACK,      KC_WWW_FORWARD
),
/* Keymap 3: Soft Reset
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
 *                                 |      | Reset|------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[3] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS   ,KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,
                                KC_TRNS,    RESET,    KC_TRNS,

  // right hand
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,
  KC_TRNS,
  KC_TRNS,    KC_TRNS,    KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " Version 1.23 @ " QMK_VERSION);
        return false;
        case HSV_172_255_255:
          if (record->event.pressed) {
            #ifdef RGBLIGHT_ENABLE
              rgblight_enable();
              rgblight_mode(1);
              rgblight_sethsv(172,255,255);
            #endif
          }
          return false;
        case HSV_0_255_255:
          if (record->event.pressed) {
            #ifdef RGBLIGHT_ENABLE
              rgblight_enable();
              rgblight_mode(1);
              rgblight_sethsv(0,255,255);
            #endif
          }
          return false;
        case HSV_86_255_128:
          if (record->event.pressed) {
            #ifdef RGBLIGHT_ENABLE
              rgblight_enable();
              rgblight_mode(1);
              rgblight_sethsv(86,255,128);
            #endif
          }
          return false;
        case HSV_215_255_128:
          if (record->event.pressed) {
            #ifdef RGBLIGHT_ENABLE
              rgblight_enable();
              rgblight_mode(1);
              rgblight_sethsv(215,255,128);
            #endif
          }
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
void matrix_init_user(void) {
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

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
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
