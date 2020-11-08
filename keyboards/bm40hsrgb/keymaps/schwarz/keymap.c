/* Copyright 2020 tominabox1
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

enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  MAKE_H,
  M_AE,
  M_UE,
  M_OE,
  M_EU,
  SNAP1,
  SNAP2,
  WMAIL,
  GMAIL,
  AE_TRIM,
  PRT_MAP,
  CD_QMK
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ K E Y M A P S                                                                                                          ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 
   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   ┃ b a s e                                                   ┃
   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
   ┃   TAB   ┃    Q    ┃    W    ┃    E    ┃    R    ┃    T    ┃    Y    ┃    U    ┃    I    ┃    O    ┃    P    ┃    \    ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  GESC   ┃    A    ┃    S    ┃    D    ┃    F    ┃    G    ┃    H    ┃    J    ┃    K    ┃    L    ┃    ;    ┃    "    ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  SHIFT  ┃    Z    ┃    X    ┃    C    ┃    V    ┃    B    ┃    N    ┃    M    ┃    ,    ┃    .    ┃    /    ┃  SHIFT  ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃   DEL   ┃  CTRL   ┃   ALT   ┃   GUI   ┃  LOWER  ┃       SPACE       ┃  RAISE  ┃  BSPACE ┃    !    ┃  @VOL-  ┃  @VOL+  ┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */

[_BASE] = LAYOUT_planck_mit(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,  \
    KC_GESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, \
    KC_DEL,   KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,    KC_SPC,             RAISE,    KC_BSPC,  KC_EXLM,  KC_VOLD,  KC_VOLU  \
),

/* 
   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   ┃ l o w e r                                                 ┃
   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
   ┃  CAPSL  ┃    @    ┃    &    ┃   UP    ┃    #    ┃    {    ┃    }    ┃    +    ┃    7    ┃    8    ┃    9    ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  @AE    ┃    %    ┃  LEFT   ┃  DOWN   ┃  RIGHT  ┃    [    ┃    ]    ┃    -    ┃    4    ┃    5    ┃    6    ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃  PGUP   ┃         ┃  PGDWN  ┃    (    ┃    )    ┃    *    ┃    1    ┃    2    ┃    3    ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  SNAP1  ┃  SNAP2  ┃         ┃         ┃         ┃       ENTER       ┃         ┃    0    ┃    =    ┃  MUTE   ┃  PLAY   ┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */

[_LOWER] = LAYOUT_planck_mit(
    KC_CAPS,  KC_AT,    KC_AMPR,  KC_UP,    KC_HASH,  KC_LCBR,  KC_RCBR,  KC_PLUS,  KC_P7,    KC_P8,    KC_P9,    XXXXXXX,  \
    XXXXXXX,  KC_PERC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_LBRC,  KC_RBRC,  KC_MINS,  KC_P4,    KC_P5,    KC_P6,    XXXXXXX, \
    _______,  XXXXXXX,  KC_PGUP,  XXXXXXX,  KC_PGDN,  KC_LPRN,  KC_RPRN,  KC_ASTR,  KC_P1,    KC_P2,    KC_P3,    _______, \
    SNAP1,    SNAP2,    _______,  _______,  _______,  KC_ENT,             _______,  KC_P0,    KC_EQL,   KC_MUTE,  KC_MPLY  \
),

/* 
   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   ┃ r a i s e                                                 ┃
   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
   ┃  CAPSL  ┃         ┃         ┃   EU    ┃         ┃         ┃   YEN   ┃    Ü    ┃         ┃    Ö    ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃    Ä    ┃   SZ    ┃    $    ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃         ┃   CUE   ┃         ┃         ┃         ┃         ┃         ┃ @MACRO  ┃ @MACRO  ┃ @MACRO  ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃   WEB   ┃   GMX   ┃ @GIPHY  ┃         ┃         ┃       DELETE      ┃         ┃         ┃ @MACRO  ┃ @MACRO  ┃ @MACRO  ┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */
[_RAISE] = LAYOUT_planck_mit(  
   KC_CAPS,  XXXXXXX,  XXXXXXX,   M_EU,     XXXXXXX,  XXXXXXX,  LALT(KC_Y),M_UE,    XXXXXXX,  M_OE,     XXXXXXX,  XXXXXXX, \
   XXXXXXX,  M_AE,     RALT(KC_S),KC_DLR,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
   _______,  XXXXXXX,  XXXXXXX,  LALT(KC_C),XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______, \
   WMAIL,    GMAIL,    _______,  _______,   _______,  KC_DEL,             _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX   \
),

/* 
   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   ┃ a d j u s t                                               ┃
   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
   ┃  RESET  ┃  DEBUG  ┃   RGB   ┃ RGB MOD ┃  HUE+   ┃  SAT+   ┃ BRGTH+  ┃ SPEED+  ┃   F7    ┃   F8    ┃   F9    ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  MAKE   ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃   F4    ┃   F5    ┃   F6    ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  QMK    ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃   F1    ┃   F2    ┃   F3    ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  WIN    ┃  MAC    ┃         ┃         ┃         ┃                   ┃         ┃   F10   ┃   F11   ┃   F12   ┃         ┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */
[_ADJUST] = LAYOUT_planck_mit(
    RESET,    DEBUG,    RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_SPI,   KC_F7,     KC_F8,    KC_F9,    _______,
    MAKE_H,   _______,  _______,  _______,  _______,  _______,  _______,  _______,   KC_F4,     KC_F5,    KC_F6,    _______,
    CD_QMK,   _______,  _______,  _______,  _______,  _______,  _______,  _______,   KC_F1,     KC_F2,    KC_F3,    _______,
    LCG_SWP,  LCG_NRM,  _______,  _______,  _______,  _______,            _______,   KC_F10,    KC_F11,   KC_F12,   _______
  )

};


static bool CGswap = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
      case LCG_SWP:
          if (record->event.pressed) {
            CGswap = true;
            return true;
          }

      case LCG_NRM:
          if (record->event.pressed) {
            CGswap = false;
            return true;
          }

      case DM_REC1:
          if (record->event.pressed) {
            return true;
          }

      case DM_REC2:
          if (record->event.pressed) {
            return true;
          }

      case DM_RSTP:
          if (record->event.pressed) {
            return true;
          }

      case SNAP1:
          if (record->event.pressed) {
            if (CGswap == false) {
              SEND_STRING(SS_LSFT(SS_LCMD("4")));           //MAC
            } else {
              SEND_STRING(SS_LWIN(SS_TAP(X_PSCR)));         //WIN
            }
          }
          break;

      case SNAP2:
          if (record->event.pressed) {
            if (CGswap == false) {
              SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL("4"))));  //MAC
            } else {
              SEND_STRING(SS_LSFT(SS_LWIN("S")));           //WIN
            }
          }
          break;

      case MAKE_H:
          if (record->event.pressed) {
            SEND_STRING ("make bm40hsrgb:schwarz");
            tap_code(KC_ENTER); 
          } 
          break;

      case CD_QMK:
          if (record->event.pressed) {
            if (CGswap == false) {
              SEND_STRING("cd qmk_firmware");              //MAC
              tap_code(KC_ENTER); 
            } else {
              SEND_STRING("cd /Users/igiti/qmk_firmware"); //WIN
              tap_code(KC_ENTER); 
            }
          } 
          break;

      case M_AE:
          if (record->event.pressed) {
            SEND_STRING(SS_LSFT("'")"a");  
          }
          break;

      case M_UE:
          if (record->event.pressed) {
            SEND_STRING(SS_LSFT("'")"u");  
          }
          break;

      case M_OE:
          if (record->event.pressed) {
            SEND_STRING(SS_LSFT("'")"o");  
          }
          break;

      case M_EU:
          if (record->event.pressed) {
            if (CGswap == false) {
              SEND_STRING(SS_LALT(SS_LSFT("2")));          //MAC
            } else {
              SEND_STRING(SS_LALT("5"));                    //WIN
            }
          }
          break;

      case WMAIL:
          if (record->event.pressed) {
            SEND_STRING ("igit.igit@web.de");
          } 
          break;

      case GMAIL:
          if (record->event.pressed) {
            SEND_STRING ("igit@gmx.de");
          } 
          break;

      }
    return true;
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}