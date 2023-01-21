#include QMK_KEYBOARD_H

#include "yuanw.h"
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif
enum layers { LAYER_NAMES };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE]   = U_MACRO_VA_ARGS(LAYOUT_miryoku_adept, LAYER_BASE),
  [NAV]    = U_MACRO_VA_ARGS(LAYOUT_miryoku_adept, LAYER_NAV),
  [MOUSE]  = U_MACRO_VA_ARGS(LAYOUT_miryoku_adept, LAYER_MOUSE),
  [MEDIA]  = U_MACRO_VA_ARGS(LAYOUT_miryoku_adept, LAYER_MEDIA),
  [NUM]    = U_MACRO_VA_ARGS(LAYOUT_miryoku_adept, LAYER_NUM),
  [SYM]    = U_MACRO_VA_ARGS(LAYOUT_miryoku_adept, LAYER_SYM),
  [FUN]    = U_MACRO_VA_ARGS(LAYOUT_miryoku_adept, LAYER_FUN),
  [BUTTON] = U_MACRO_VA_ARGS(LAYOUT_miryoku_adept, LAYER_BUTTON)
};

/* #if defined (MIRYOKU_KLUDGE_THUMBCOMBOS) */
/* const uint16_t PROGMEM thumbcombos_base_right[] = {LT(SYM, KC_ENT), LT(NUM, KC_BSPC), COMBO_END}; */
/* const uint16_t PROGMEM thumbcombos_base_left[] = {LT(NAV, KC_SPC), LT(MOUSE, KC_TAB), COMBO_END}; */
/* const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END}; */
/* const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN1, KC_BTN3, COMBO_END}; */
/* const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END}; */
/* const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END}; */
/*   #if defined (MIRYOKU_LAYERS_FLIP) */
/* const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END}; */
/*   #else */
/* const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END}; */
/*   #endif */
/* const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END}; */
/* combo_t key_combos[COMBO_COUNT] = { */
/*   COMBO(thumbcombos_base_right, LT(FUN, KC_DEL)), */
/*   COMBO(thumbcombos_base_left, LT(MEDIA, KC_ESC)), */
/*   COMBO(thumbcombos_nav, KC_DEL), */
/*   COMBO(thumbcombos_mouse, KC_BTN2), */
/*   COMBO(thumbcombos_media, KC_MUTE), */
/*   COMBO(thumbcombos_num, KC_DOT), */
/*   #if defined (MIRYOKU_LAYERS_FLIP) */
/*   COMBO(thumbcombos_sym, KC_RPRN), */
/*   #else */
/*   COMBO(thumbcombos_sym, KC_LPRN), */
/*   #endif */
/*   COMBO(thumbcombos_fun, KC_APP) */
/* }; */
/* #endif */
enum combos {
  FD_B,
  LU_J,
  MP_Q,
  KCOMM_Z,
  CTLCOMM_LCBR,
  CTLDOT_RCBR,
  CTLCOMM_LBRC,
  CTLDOT_RBRC,
};
const uint16_t PROGMEM b_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM j_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_M, KC_P, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_K, KC_COMM, COMBO_END};
const uint16_t PROGMEM lcbr_combo[] = {LCTL_T(KC_N), KC_COMM, COMBO_END};
const uint16_t PROGMEM rcbr_combo[] = {LCTL_T(KC_N), KC_DOT, COMBO_END};
const uint16_t PROGMEM lbrc_combo[] = {LALT_T(KC_S), KC_COMM, COMBO_END};
const uint16_t PROGMEM rbrc_combo[] = {LALT_T(KC_S), KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [FD_B] = COMBO(b_combo, KC_B),
  [LU_J] = COMBO(j_combo, KC_J),
  [MP_Q] = COMBO(q_combo, KC_Q),
  [KCOMM_Z] = COMBO(z_combo, KC_Z),
  [CTLCOMM_LCBR] =COMBO(lcbr_combo,KC_LCBR),
  [CTLDOT_RCBR] =COMBO(rcbr_combo,KC_RCBR),
  [CTLCOMM_LBRC] =COMBO(lbrc_combo,KC_LBRC),
  [CTLDOT_RBRC] =COMBO(rbrc_combo, KC_RBRC),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 #ifdef CONSOLE_ENABLE
uprintf("0x%04X,%u,%u,%u,%d,0x%02X,0x%02X,%u\n",
         keycode,
         record->event.key.row,
         record->event.key.col,
         layer_state|default_layer_state,
         record->event.pressed,
         get_mods(),
         get_oneshot_mods(),
         record->tap.count
         );
#endif
    return true;
}
