/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#define _______ KC_NO

// clang-format off
enum layers{
  MAC_BASE,
  WIN_BASE,
  MAC_FN1,
  WIN_FN1,
  FN2
};


enum custom_keycodes {
    FN2_IN = SAFE_RANGE,
    FN2_OUT,
    CINECO,
    CGOOGLE,
    CJUS,
    //LINECO,
    ENHE,
    ALINUX
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case FN2_IN:
        if (record->event.pressed) {
            led_matrix_enable();
            //led_matrix_mode(ENABLE_LED_MATRIX_SOLID);
            layer_on(FN2);
        } else {
            clear_keyboard();
        }
        break;
    case FN2_OUT:
        if (record->event.pressed) {
            led_matrix_disable();
            layer_off(FN2);
        } else {
            clear_keyboard();
        }
        break;
    case CGOOGLE:
        if (record->event.pressed) {
            SEND_STRING("fernando.real.cisneros@gmail.com");
        } else {
            clear_keyboard();
        }
        break;
    case CJUS:
        if (record->event.pressed) {
            SEND_STRING("fernando.real@empresas.justicia.es");
        } else {
            clear_keyboard();
        }
        break;
    case CINECO:
        if (record->event.pressed) {
            SEND_STRING("fernando.real@ineco.com");
        } else {
            clear_keyboard();
        }
        break;
    // case LINECO: //fernando.real{KC_TAB}Ineco2023.{KC_ENT}    SS_DELAY(msecs)
    //     if (record->event.pressed) {
    //         SEND_STRING("fernando.real"SS_TAP(X_TAB)"**********....."SS_TAP(X_ENT));
    //     } else {
    //         clear_keyboard();
    //     }
    //     break;

    case ALINUX:   //{+KC_LGUI}x{-KC_LGUI}x
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("x")SS_DELAY(100)"x");
        }
        break;
    }

    return true;
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
        //led_matrix_set_value(1, 200);
    } else {
        // Do something when Caps Word deactivates.
        //led_matrix_set_value(1, 0);
    }
}


///////// COMBOS

// falta el #define DE_UDIA KC_LBRC  Ü
enum combo_events {
  A_ACCENT,
  E_ACCENT,
  I_ACCENT,
  O_ACCENT,
  U_ACCENT,
  N_ACCENT,
  NN_ACCENT,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM a_accent[] = {KC_QUOT, KC_A, COMBO_END};
const uint16_t PROGMEM e_accent[] = {KC_QUOT, KC_E, COMBO_END};
const uint16_t PROGMEM i_accent[] = {KC_QUOT, KC_I, COMBO_END};
const uint16_t PROGMEM o_accent[] = {KC_QUOT, KC_O, COMBO_END};
const uint16_t PROGMEM u_accent[] = {KC_QUOT, KC_U, COMBO_END};
const uint16_t PROGMEM n_accent[] = {KC_QUOT, KC_N, COMBO_END};
const uint16_t PROGMEM nn_accent[] = {KC_SCLN, KC_N, COMBO_END};

combo_t key_combos[] = {
  [A_ACCENT] = COMBO_ACTION(a_accent),
  [E_ACCENT] = COMBO_ACTION(e_accent),
  [I_ACCENT] = COMBO_ACTION(i_accent),
  [O_ACCENT] = COMBO_ACTION(o_accent),
  [U_ACCENT] = COMBO_ACTION(u_accent),
  [N_ACCENT] = COMBO_ACTION(n_accent),
  [NN_ACCENT] = COMBO_ACTION(nn_accent),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case A_ACCENT:
      if (pressed) {
        SEND_STRING(SS_RALT("a"));
      }
      break;
  case E_ACCENT:
      if (pressed) {
        SEND_STRING(SS_RALT("e"));
      }
      break;
  case I_ACCENT:
      if (pressed) {
        SEND_STRING(SS_RALT("i"));
      }
      break;
  case O_ACCENT:
      if (pressed) {
        SEND_STRING(SS_RALT("o"));
      }
      break;
  case U_ACCENT:
      if (pressed) {
        SEND_STRING(SS_RALT("u"));
      }
      break;
  case NN_ACCENT:
  case N_ACCENT:
      if (pressed) {
        SEND_STRING(SS_RALT("n"));
      }
      break;

  }
}

/////////






const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[MAC_BASE] = LAYOUT_ansi_68(
     KC_CAPS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,        KC_MINS, KC_EQL,   KC_BSPC, KC_DEL,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,        KC_SCLN, KC_RBRC,  KC_BSLS, KC_HOME,
     KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     RALT(KC_N),  KC_QUOT,           KC_ENT,  KC_PGUP,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,     KC_RSFT, KC_UP,             KC_PGDN,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                       KC_RALT,  MO(WIN_FN1), _______, KC_LEFT,  KC_DOWN, KC_RGHT),

////////////// 0
[WIN_BASE] = LAYOUT_ansi_68(
     KC_CAPS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,        KC_MINS, KC_EQL,   KC_BSPC, KC_DEL,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,        KC_LBRC, KC_RBRC,  KC_BSLS, KC_HOME,
     KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,     KC_QUOT,           KC_ENT,  KC_PGUP,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,     KC_RSFT, KC_UP,             KC_PGDN,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                       KC_RALT,  MO(WIN_FN1), FN2_IN,  KC_LEFT,  KC_DOWN, KC_RGHT),

[MAC_FN1] = LAYOUT_ansi_68(
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,  _______,  _______,                                _______,                      _______,  _______,  _______,  _______,  _______,  _______),

///////////// 1
[WIN_FN1] = LAYOUT_ansi_68(
     CW_TOGG,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,   BL_STEP,  _______,
     ALINUX,   BT_HST1,  BT_HST2,  BT_HST3,  QK_BOOT,  _______,  _______,  _______,  CINECO,   _______,  _______,    _______,  _______,  _______,  KC_END,
     _______,  _______,  _______,  _______,  _______,  CGOOGLE,  _______,  CJUS,     _______,  _______,  RALT(KC_N), _______,            KC_PSCR,  KC_VOLU,
     _______,  _______,  _______,  _______,  _______,  BAT_LVL,  _______,  KC_MUTE,  _______,  _______,  _______,    _______,  KC_WSCH,            KC_VOLD,
     _______,  _______,  _______,                                _______,                      _______,  _______,    _______,  KC_WBAK,  KC_WREF,  KC_WFWD),

////////////// 2   BL_STEP    S(KC_SCLN) encima de la letra
[FN2] = LAYOUT_ansi_68(
     KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,       KC_F11,   KC_F12,   KC_BSPC, KC_DEL,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,         KC_SCLN,  KC_RBRC,  KC_BSLS, KC_HOME,
     KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     RALT(KC_N),   KC_QUOT,            KC_ENT,  KC_PGUP,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,      KC_RSFT,  KC_UP,             KC_PGDN,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                       KC_RALT,  _______,      FN2_OUT,  KC_LEFT,  KC_DOWN, KC_RGHT),
};

