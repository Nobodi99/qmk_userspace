// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "miryoku_babel/miryoku_layer_selection.h"
#include "miryoku_babel/miryoku_layer_list.h"

enum miryoku_layers {
#define MIRYOKU_X(LAYER, STRING) U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)

#if !defined (MIRYOKU_MAPPING)
  #define MIRYOKU_MAPPING LAYOUT_miryoku
#endif

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

#if defined (MIRYOKU_CLIPBOARD_FUN)
  #define U_RDO KC_AGIN
  #define U_PST KC_PSTE
  #define U_CPY KC_COPY
  #define U_CUT KC_CUT
  #define U_UND KC_UNDO
#elif defined (MIRYOKU_CLIPBOARD_MAC)
  #define U_RDO SCMD(KC_Z)
  #define U_PST LCMD(KC_V)
  #define U_CPY LCMD(KC_C)
  #define U_CUT LCMD(KC_X)
  #define U_UND LCMD(KC_Z)
#elif defined (MIRYOKU_CLIPBOARD_WIN)
  #define U_RDO C(KC_Y)
  #define U_PST C(KC_V)
  #define U_CPY C(KC_C)
  #define U_CUT C(KC_X)
  #define U_UND C(KC_Z)
#else
  #define U_RDO KC_AGIN
  #define U_PST S(KC_INS)
  #define U_CPY C(KC_INS)
  #define U_CUT S(KC_DEL)
  #define U_UND KC_UNDO
#endif

enum unicode_names {
    AUM,
    OUM,
    UUM,
    AUM_S,
    OUM_S,
    UUM_S,
    ESZ,
    ESZ_S,
    EUR,
    SNEK
};

const uint32_t PROGMEM unicode_map[] = {
    [AUM] = 0x00E4,
    [OUM] = 0x00F6,
    [UUM] = 0x00FC,
    [AUM_S] = 0x00C4,
    [OUM_S] = 0x00D6,
    [UUM_S] = 0x00DC,
    [ESZ] = 0x00DF,
    [ESZ_S] = 0x1E9E,
    [EUR] = 0x20AC,
    [SNEK] = 0x1F40D,
};

enum custom_keycodes {
    M1SFT = SAFE_RANGE,
    M2SFT,
    M3SFT,
    M1CTL,
    M2CTL,
    M3CTL
};

// Custom functions for macros

void register_mouse_with_shift(uint16_t keycode) {
    register_code(KC_LSFT);  // press the shift key
    send_keyboard_report();
    register_code(keycode);  // press the mouse key
}

void unregister_mouse_with_shift(uint16_t keycode) {
    unregister_code(keycode);  // press the shift key
    send_keyboard_report();
    unregister_code(KC_LSFT);  // press the mouse key
}

void register_mouse_with_ctrl(uint16_t keycode) {
    register_code(KC_LCTL);  // press the shift key
    send_keyboard_report();
    register_code(keycode);  // press the mouse key
}

void unregister_mouse_with_ctrl(uint16_t keycode) {
    unregister_code(keycode);  // press the shift key
    send_keyboard_report();
    unregister_code(KC_LCTL);  // press the mouse key
}

// Custom key macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M1SFT:
            if (record->event.pressed) {
                // when keycode M1SFT is pressed
                register_mouse_with_shift(KC_BTN1);
            } else {
                // when keycode M1SFT is released
                unregister_mouse_with_shift(KC_BTN1);
            }
            break;
        case M2SFT:
            if (record->event.pressed) {
                // when keycode M2SFT is pressed
                register_mouse_with_shift(KC_BTN2);
            } else {
                // when keycode M2SFT is released
                unregister_mouse_with_shift(KC_BTN2);
            }
            break;
        case M3SFT:
            if (record->event.pressed) {
                // when keycode M3SFT is pressed
                register_mouse_with_shift(KC_BTN3);
            } else {
                // when keycode M3SFT is released
                unregister_mouse_with_shift(KC_BTN3);
            }
            break;
        case M1CTL:
            if (record->event.pressed) {
                // when keycode M1SFT is pressed
                register_mouse_with_ctrl(KC_BTN1);
            } else {
                // when keycode M1SFT is released
                unregister_mouse_with_ctrl(KC_BTN1);
            }
            break;
        case M2CTL:
            if (record->event.pressed) {
                // when keycode M1SFT is pressed
                register_mouse_with_ctrl(KC_BTN2);
            } else {
                // when keycode M1SFT is released
                unregister_mouse_with_ctrl(KC_BTN2);
            }
            break;
        case M3CTL:
            if (record->event.pressed) {
                // when keycode M1SFT is pressed
                register_mouse_with_ctrl(KC_BTN3);
            } else {
                // when keycode M1SFT is released
                unregister_mouse_with_ctrl(KC_BTN3);
            }
            break;
    }
    return true;
}
