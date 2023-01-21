#pragma once

/* #include "miryoku_babel/miryoku_layer_names.h" */
/* #include "miryoku_babel/miryoku_layer.h" */

#define LAYER_NAMES BASE, BUTTON, NAV, MOUSE, MEDIA, NUM, SYM, FUN
#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used
#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)

#define LAYER_BASE \
KC_SLSH,           KC_W,              KC_M,              KC_P,              KC_Q,              KC_Z,              KC_K,              KC_COMM,           KC_DOT,            KC_SCLN,           \
LGUI_T(KC_R),      LALT_T(KC_S),      LCTL_T(KC_N),      LSFT_T(KC_T),      KC_G,              KC_V,              LSFT_T(KC_H),      LCTL_T(KC_A),      LALT_T(KC_I),      LGUI_T(KC_O),      \
LT(BUTTON, KC_X),  ALGR_T(KC_C),      KC_F,              KC_D,              KC_B,              KC_J,              KC_L,              KC_U,           ALGR_T(KC_Y),     LT(BUTTON, KC_QUOT), \
U_NP,              U_NP,              LT(MEDIA, KC_ESC), LT(NAV, KC_SPC),   LT(MOUSE, KC_BSPC), LT(SYM, KC_ENT),   LT(NUM, KC_E),  LT(FUN, KC_TAB),   U_NP,              U_NP


#define LAYER_NAV \
RESET,             U_NA,              U_NA,              U_NA,              U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_CAPS,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           \
U_NA,              KC_ALGR,           U_NA,              U_NA,              U_NA,              KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_E,              KC_TAB,            U_NP,              U_NP


#define LAYER_MOUSE \
RESET,             U_NA,              U_NA,              U_NA,              U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           \
U_NA,              KC_ALGR,           U_NA,              U_NA,              U_NA,              U_NU,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN1,           KC_BTN3,           KC_BTN2,           U_NP,              U_NP

#define LAYER_MEDIA \
RESET,             U_NA,              U_NA,              U_NA,              U_NA,              RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              OUT_AUTO,          KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           \
U_NA,              KC_ALGR,           U_NA,              U_NA,              U_NA,              U_NU,              U_NU,              U_NU,              U_NU,              U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

#define LAYER_NUM \
KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           U_NA,              U_NA,              U_NA,              U_NA,              RESET,             \
KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           U_NA,              U_NA,              U_NA,              KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_DOT,            KC_0,              KC_MINS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define LAYER_SYM \
KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           U_NA,              U_NA,              U_NA,              U_NA,              RESET,             \
KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,           U_NA,              U_NA,              U_NA,              KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_LPRN,           KC_RPRN,           KC_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define LAYER_FUN \
KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,              U_NA,              U_NA,              U_NA,              RESET,             \
LAG(KC_1),       LAG(KC_2),       LAG(KC_3),       LAG(KC_4),               KC_SCRL,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
LSG(KC_1),       LSG(KC_2),       LSG(KC_3),       LSG(KC_4),               KC_PAUS,           U_NA,              U_NA,              U_NA,              KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define LAYER_BUTTON \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           KC_NO,             KC_NO,             KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NP,              U_NP,              KC_BTN2,           KC_BTN3,           KC_BTN1,           KC_BTN1,           KC_BTN3,           KC_BTN2,           U_NP,              U_NP
/* #if defined (MIRYOKU_CLIPBOARD_FUN) */
/*   #define U_RDO KC_AGIN */
/*   #define U_PST KC_PSTE */
/*   #define U_CPY KC_COPY */
/*   #define U_CUT KC_CUT */
/*   #define U_UND KC_UNDO */
/* #elif defined (MIRYOKU_CLIPBOARD_MAC) */
/*   #define U_RDO SCMD(KC_Z) */
/*   #define U_PST LCMD(KC_V) */
/*   #define U_CPY LCMD(KC_C) */
/*   #define U_CUT LCMD(KC_X) */
/*   #define U_UND LCMD(KC_Z) */
/* #elif defined (MIRYOKU_CLIPBOARD_WIN) */
/*   #define U_RDO C(KC_Y) */
/*   #define U_PST C(KC_V) */
/*   #define U_CPY C(KC_C) */
/*   #define U_CUT C(KC_X) */
/*   #define U_UND C(KC_Z) */
/* #else */
/*   #define U_RDO KC_AGIN */
/*   #define U_PST S(KC_INS) */
/*   #define U_CPY C(KC_INS) */
/*   #define U_CUT S(KC_DEL) */
/*   #define U_UND KC_UNDO */
/* #endif */
