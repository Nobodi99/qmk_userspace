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
    GER_AE = SAFE_RANGE,
    GER_OE,
    GER_UE,
    GER_EUR,
    GER_SZ
};

char *alt_codes[][2] = {
    {
		SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+0228 → ä
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_6)), // Alt+0196 → Ä
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_6)), // Alt+0246 → ö
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_4)), // Alt+0214 → Ö
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_2)), // Alt+0252 → ü
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_0)), // Alt+0220 → Ü
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+0252 → €
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_6)SS_TAP(X_KP_3)), // Alt+0220 → £
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_3)), // Alt+0252 → ß
        SS_LALT(SS_TAP(X_KP_7)SS_TAP(X_KP_8)SS_TAP(X_KP_3)SS_TAP(X_KP_8)), // Alt+0220 → ẞ
    },
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!record->event.pressed)
		return true;

    switch (keycode) {
		case GER_AE:
		case GER_OE:
		case GER_UE:
        case GER_EUR:
        case GER_SZ: {
			uint16_t index = keycode - GER_AE;
			uint8_t shift = get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));

			unregister_code(KC_LSFT);
			unregister_code(KC_RSFT);

			send_string(alt_codes[index][(bool)shift]);

			if (shift & MOD_BIT(KC_LSFT)) register_code(KC_LSFT);
			if (shift & MOD_BIT(KC_RSFT)) register_code(KC_RSFT);

			return false;
		}
		default:
			return true;
    }
}
