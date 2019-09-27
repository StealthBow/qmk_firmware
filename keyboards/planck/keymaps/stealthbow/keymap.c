/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _RAISE,
  _LOWER,
  _ADJUST,
  _MOUSE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOUSE MO(_MOUSE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  | Mouse|Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,  KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT},
  {KC_LCTL, KC_LGUI, KC_LALT, MOUSE, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   -  |   =  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   \  |      |      |      |      |      |      |   #  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  |      |  N/A |    Space    |  N/A | Home |Pg Dn |Pg Up | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______},
  {KC_LSFT, KC_NUBS, _______, _______, _______, _______, _______, _______, KC_NUHS, KC_LBRC, KC_RBRC, _______},
  {KC_LCTL, KC_LGUI, KC_LALT, _______, _______, KC_SPC,  KC_SPC,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  |      |  N/A |             |  N/A | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY},
  {KC_LCTL, KC_LGUI, KC_LALT, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |BCKLIT|BKLBrt|Mus Md|Aud on|Audoff|      |      |      |      |      |      | Reset|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Voice-|Voice+|Mus On|MusOff|MIDIon|MIDIof|TR_ON |TM_OFF|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | CapsL|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  |      |  N/A |             |  N/A |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {BL_STEP, BL_BRTG, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, _______,  _______, _______, _______, RESET},
  {MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______, _______},
  {KC_LCAP, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______},
  {KC_LCTL, KC_LGUI, KC_LALT, _______, _______, _______, _______, _______,  _______, _______, _______, _______}
},

/* Mouse (Mouse Keys)
 * ,-----------------------------------------------------------------------------------.
 * |MsMBtn|MsRBtn|Ms Up |MsLBtn|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |MsLeft|MsDown|Ms Rgt|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  |  N/A |  N/A |             |  N/A |MsWhlL|MsWhlD|MsWhlU|MsWhlR|
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = {
  {KC_BTN3, KC_BTN2, KC_MS_U, KC_BTN1, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_LCTL, KC_LGUI, KC_LALT, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R}
}


};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
  }
  return true;
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
