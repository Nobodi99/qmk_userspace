// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

// Add accent layer for german umlaute
#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(EXTRA,  "Extra") \
MIRYOKU_X(TAP,    "Tap") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Mouse") \
MIRYOKU_X(MEDIA,  "Media") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun") \
MIRYOKU_X(ACC,    "Acc")

// Enable Unicode symbols with WinCompose
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE

// Enable pointing device modes
#define POINTING_DEVICE_MODES_ENABLE
#define POINTING_DEVICE_MODES_INVERT_Y
#define POINTING_CARET_DIVISOR_V 16
#define POINTING_CARET_DIVISOR_H 32

// Enable caps word when both shift keys are pressed
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define MIRYOKU_CLIPBOARD_WIN

#define AE_U XP(AUM, AUM_S)
#define OE_U XP(OUM, OUM_S)
#define UE_U XP(UUM, UUM_S)
#define SZ_U XP(ESZ, ESZ_S)

#define MIR_H LT(U_ACC, KC_H)
#define MIR_D LT(U_ACC, KC_D)

// Accent layer
#define MIRYOKU_ALTERNATIVES_ACC \
U_NP,              U_NP,              U_NP,             U_NP,               U_NP,              U_NP,              U_NP,             UE_U,               U_NP,              U_NP, \
AE_U,              U_NP,              SZ_U,             U_NP,               U_NP,              U_NP,              U_NP,             X(EUR),             U_NP,              OE_U, \
U_NP,              U_NP,              X(SNEK),          U_NP,               U_NP,              U_NP,              U_NP,             U_NP,               U_NP,              U_NP, \
U_NP,              U_NP,              U_NP,             U_NP,               U_NP,              U_NP,              U_NP,             U_NP,               U_NP,              U_NP

// Accent layer mapping
#define MIRYOKU_LAYERMAPPING_ACC MIRYOKU_MAPPING
#define MIRYOKU_LAYER_ACC MIRYOKU_ALTERNATIVES_ACC

// Mouse layer with dragscroll
#define MIRYOKU_LAYER_MOUSE \
U_NA,              U_NA,              U_NA,              PM_TG(PM_CRT),     U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NA,              KC_BTN2,           KC_BTN3,           KC_BTN1,           DRG_TOG,           DPI_MOD,           KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
OSM(MOD_LGUI),     OSM(MOD_LALT),     OSM(MOD_LCTL),     OSM(MOD_LSFT),     SNP_TOG,           DPI_RMOD,          KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_BTN3,           U_NP,              U_NP

#define MIRYOKU_LAYER_BASE \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              RSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),      \
LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              MIR_D,             KC_V,              KC_K,              MIR_H,             KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),\
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP
