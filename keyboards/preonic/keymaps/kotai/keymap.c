/*
.                                                                                                                           .
.                                                ▗▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄▖                                                      .
.                                                █   ▗▄▄▄▄▄▄▄▄▄▄▄▖   █                                                      .
.                                                █   █     ▄     █   █                                                      .
.                                                █   █ ▝▀▀▀█▀▀▀▘ █   █                                                      .
.                                                █   █  ▗▄▄█▄▄▖  █   █                                                      .
.                                                █   █  █     █  █   █                                                      .
.                                                █   █  ▝▀▀▀▀▀▘  █   █                                                      .
.                                                █   ▝▀▀▀▀▀▀▀▀▀▀▀▘   █                                                      .
.                                                █     ▄▖    ▄       █                                                      .
.                                                █    ▗█     █       █                                                      .
.                                                █   ▗▛█ ▀▀▀███▀▀▀   █                                                      .
.                                                █  ▗▛ █   ▗▌█▐▖     █                                                      .
.                                                █  ▀  █  ▗▛ █ ▜▖    █                                                      .
.                                                █     █ ▄▀  █  ▀▄   █                                                      .
.                                                █     █▀▘ ▀▀█▀▀ ▝▀  █                                                      .
.                                                █     ▀     ▀       █                                                      .
.                                                ▝▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀▘                                                      .
.                                                                                                                           .
.                                                 ┏┓ ┏┓ ┏┓ ┏┓ ┏┓ ╻ ┏┓                                                       .
.                                                 ┣┛ ┃  ┣┛ ┃┃ ┃┃ ┃ ┃                                                        .
.                                                 ╹  ╹  ┗┛ ┗┛ ╹╹ ╹ ┗┛                                                       .
.                                                                                                                           .
*/

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ D E F I N I T I O N S                                                                                                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌


#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _BASE,
  _AEB,
  _LOWER,
  _LOW_AE,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  AEB,
  MAKE_H,
  M_AE,
  M_UE,
  M_OE,
  M_EU,
  M_QUOTE,
  M_SQUOT,
  SNAP1,
  SNAP2,
  WMAIL,
  GMAIL,
  GIPHY,
  AE_MOD,
  AE_TRIM,
  AE_SLD,
  AE_ADJ,
  PRT_MAP,
  CD_QMK,
  OS_SWAP
};


// ╭───────────────────────────────────────────────────────────╮
// │ d e f i n e   m a c r o n a m e s                         │
// ╰───────────────────────────────────────────────────────────╯ 

#define BASE TO(_BASE)
#define AEB TG(_AEB)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)


// ╭───────────────────────────────────────────────────────────╮
// │ d e f i n e   s o u n d s                                 │
// ╰───────────────────────────────────────────────────────────╯ 

#ifdef AUDIO_ENABLE
  #define WINXP_SOUND W__NOTE(_DS6), Q__NOTE(_DS5), H__NOTE(_AS5), H__NOTE(_GS5), H__NOTE(_DS5), H__NOTE(_DS6), H__NOTE(_AS5)
  #define MAC_SOUND S__NOTE(_CS5), B__NOTE(_C5)
  #define GODZILLA_SOUND Q__NOTE(_F4), W__NOTE(_REST), W__NOTE(_REST), W__NOTE(_REST), Q__NOTE(_G4), Q__NOTE(_BF4), Q__NOTE(_G4), HD_NOTE(_D5), HD_NOTE(_D5), W__NOTE(_C5)
  #define RICK_R Q__NOTE(_F4), Q__NOTE(_G4), Q__NOTE(_BF4), Q__NOTE(_G4), HD_NOTE(_D5), HD_NOTE(_D5), W__NOTE(_C5), S__NOTE(_REST), Q__NOTE(_F4), Q__NOTE(_G4), Q__NOTE(_BF4), Q__NOTE(_G4), HD_NOTE(_C5), HD_NOTE(_C5), W__NOTE(_BF4), S__NOTE(_REST), Q__NOTE(_F4), Q__NOTE(_G4), Q__NOTE(_BF4), Q__NOTE(_G4), W__NOTE(_BF4), H__NOTE(_C5), H__NOTE(_A4), H__NOTE(_A4), H__NOTE(_G4), H__NOTE(_F4), H__NOTE(_F4), W__NOTE(_C5), W__NOTE(_BF4)

  float winxp_song[][2] = SONG(WINXP_SOUND);
  float mac_song[][2] = SONG(MAC_SOUND);
  float godzilla_song[][2] = SONG(RICK_R);
#endif // AUDIO


bool AEmod = false;
bool capsSetMac = false;

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
   ┃  GESC   ┃    1    ┃    2    ┃    3    ┃    4    ┃    5    ┃    6    ┃    7    ┃    8    ┃    9    ┃    0    ┃  @ -    ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  TAB    ┃    Q    ┃    W    ┃    E    ┃    R    ┃    T    ┃    Y    ┃    U    ┃    I    ┃    O    ┃    ;    ┃    \    ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  MUTE   ┃    A    ┃    S    ┃    D    ┃    F    ┃    G    ┃    H    ┃    J    ┃    K    ┃    L    ┃    P    ┃    "    ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  SHIFT  ┃    Z    ┃    X    ┃    C    ┃    V    ┃    B    ┃    N    ┃    M    ┃    ,    ┃    .    ┃    /    ┃  SHIFT  ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  DEL    ┃  CTRL   ┃   ALT   ┃   GUI   ┃  LOWER  ┃  SPACE  ┃  ENTER  ┃  RAISE  ┃ BSPACE  ┃    !    ┃    [    ┃    ]    ┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */
[_BASE] = LAYOUT_preonic_grid( \
    KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS, \
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_SCLN,  KC_BSLS,  \
    KC_MUTE,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_P,     M_QUOTE, \
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  \
    KC_DEL,   KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,    KC_SPC,   KC_ENT,   RAISE,    KC_BSPC,  KC_EXLM,  KC_LBRC,  KC_RBRC  \
),

/* 
   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   ┃ a f t e r   e f f e c t s                                 ┃
   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
   ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  SHIFT  ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */
[_AEB] = LAYOUT_preonic_grid( \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    KC_LSFT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______  \
),

/* 
   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   ┃ l o w e r                                                 ┃
   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
   ┃  CAPSL  ┃   F1    ┃   F2    ┃   F3    ┃   F4    ┃   F5    ┃   F6    ┃   F7    ┃   F8    ┃   F9    ┃   F10   ┃   F11   ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  AEB    ┃    @    ┃    &    ┃   UP    ┃    #    ┃    {    ┃    }    ┃    +    ┃    7    ┃    8    ┃    9    ┃   F12   ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  MUTE   ┃    %    ┃  LEFT   ┃  DOWN   ┃  RIGHT  ┃    [    ┃    ]    ┃    -    ┃    4    ┃    5    ┃    6    ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃  PGUP   ┃         ┃  PGDWN  ┃    (    ┃    )    ┃    *    ┃    1    ┃    2    ┃    3    ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  SNAP2  ┃  SNAP1  ┃         ┃         ┃         ┃         ┃         ┃         ┃    0    ┃    =    ┃  MUTE   ┃  PLAY   ┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */
[_LOWER] = LAYOUT_preonic_grid( \
    KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  \
    AEB,      KC_AT,    KC_AMPR,  KC_UP,    KC_HASH,  KC_LCBR,  KC_RCBR,  KC_PLUS,  KC_P7,    KC_P8,    KC_P9,    KC_F12,  \
    KC_MUTE,  KC_PERC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_LBRC,  KC_RBRC,  KC_MINS,  KC_P4,    KC_P5,    KC_P6,    M_SQUOT, \
    _______,  XXXXXXX,  KC_PGUP,  XXXXXXX,  KC_PGDN,  KC_LPRN,  KC_RPRN,  KC_PAST,  KC_P1,    KC_P2,    KC_P3,    _______, \
    SNAP2,    SNAP1,    _______,  _______,  _______,  _______,  _______,  _______,  KC_P0,    KC_EQL,   KC_MUTE,  KC_MPLY  \
),

/* 
   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   ┃ l o w   a e                                               ┃
   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
   ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃ ADJ/NUL ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃ SLD/SHP ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  SNAP1  ┃  SNAP2  ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */
[_LOW_AE] = LAYOUT_preonic_grid( \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  AE_ADJ,  \
    KC_LSFT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  AE_SLD, \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
    KC_F5,    KC_F6,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______  \
),

/* 
   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   ┃ r a i s e                                                 ┃
   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
   ┃  CAPSL  ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃         ┃   EU    ┃         ┃         ┃   YEN   ┃    Ü    ┃         ┃    Ö    ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  PLAY   ┃    Ä    ┃   SZ    ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃         ┃         ┃         ┃   CUE   ┃         ┃         ┃         ┃         ┃         ┃ DM REC1 ┃ DM STOP ┃ DM PLY1 ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃   WEB   ┃   GMX   ┃         ┃  GIPHY  ┃         ┃         ┃         ┃         ┃         ┃ DM REC2 ┃ DM STOP ┃ DM PLY2 ┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */
[_RAISE] = LAYOUT_preonic_grid( \
   KC_CAPS,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   \
   XXXXXXX,  XXXXXXX,  XXXXXXX,  M_EU,      XXXXXXX,  XXXXXXX,  LALT(KC_Y),M_UE,    XXXXXXX,  M_OE,     XXXXXXX,  XXXXXXX, \
   KC_MPLY,  M_AE,     RALT(KC_S),XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
   _______,  XXXXXXX,  XXXXXXX,  LALT(KC_C),XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DM_REC1,  DM_RSTP,  DM_PLY1, \
   WMAIL,    GMAIL,    _______,   GIPHY,    _______,  _______,  _______,  _______,  XXXXXXX,  DM_REC2,  DM_RSTP,  DM_PLY2  \
),

/* 
   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   ┃ a d j u s t                                               ┃
   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
   ┃  RESET  ┃  DEBUG  ┃   RGB   ┃ RGB MOD ┃  HUE+   ┃  SAT+   ┃ BRGTH+  ┃ SPEED+  ┃         ┃         ┃         ┃  PRINT  ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  MAKE   ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  CD QMK ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃  SHIFT  ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
   ┃ OS SWAP ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃ MUS ON  ┃ MUS OFF ┃
   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
 */
[_ADJUST] = LAYOUT_preonic_grid( \
   RESET,    DEBUG,    RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,   RGB_VAI,  RGB_SPI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  PRT_MAP, \
   MAKE_H,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
   CD_QMK,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
   _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
   OS_SWAP,  _______,  _______,  _______,  _______,  XXXXXXX,   XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  MU_ON,    MU_OFF  \
)
};



// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ M A C R O S                                                                                                                               ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌

static bool R_key = false;
static bool T_key = false;
static bool S_key = false;
static bool L_key = false;
static bool M_key = false;
static bool C_key = false;
static bool G_key = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t encoder_timer; 

  switch (keycode) {
      case LOWER:
            if (record->event.pressed) {
                if (AEmod) {
                  layer_on(_LOW_AE);
                }
              return true;
            }
            layer_off(_LOW_AE);
            break;

      case OS_SWAP: 
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  //WIN
                  PLAY_SONG(winxp_song);
                }
                else {
                  keymap_config.swap_lctl_lgui = false; //MAC
                  PLAY_SONG(mac_song);
                }
            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard();  // clear to prevent stuck keys    
            return false;
          }

      case KC_CAPS:
          if (record->event.pressed) {
            capsSetMac ^= 1;
            return true;
          }

      case AEB:
          if (record->event.pressed) {
            AEmod ^= 1;
            return true;
          }

    case AE_SLD:
          if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
              SEND_STRING(SS_LCTL("y"));                  //WIN
            } else {
              SEND_STRING(SS_LCMD("y"));                  //MAC
            }
          }          
          break;

      case AE_ADJ:
          if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
              SEND_STRING(SS_LALT(SS_LCTL("y")));         //WIN
            } else {
              SEND_STRING(SS_LALT(SS_LCMD("y")));         //MAC
            }
          }          
          break;

      case DM_REC1:
          if (record->event.pressed) {
            PLAY_SONG(mac_song);
            rgblight_mode(15);
            return true;
          }

      case DM_REC2:
          if (record->event.pressed) {
            PLAY_SONG(mac_song);
            rgblight_mode(15);
            return true;
          }

      case DM_RSTP:
          if (record->event.pressed) {
            PLAY_SONG(godzilla_song);
            rgblight_mode(1);
            return true;
          }

      case SNAP1:
          if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
              SEND_STRING(SS_LWIN(SS_TAP(X_PSCR)));         //WIN
            } else {
              SEND_STRING(SS_LSFT(SS_LCMD("4")));           //MAC
            }
          }
          break;

      case SNAP2:
          if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
              SEND_STRING(SS_LSFT(SS_LWIN("S")));           //WIN
            } else {
              SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL("4"))));  //MAC
            }
          }
          break;

      case MAKE_H:
          if (record->event.pressed) {
            SEND_STRING ("make preonic/rev3:kotai");
            tap_code(KC_ENTER);
          } 
          break;

      case CD_QMK:
          if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
              SEND_STRING("cd /Users/igiti/qmk_firmware"); //WIN
              tap_code(KC_ENTER); 
            } else {
              SEND_STRING("cd qmk_firmware");              //MAC
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
            if (keymap_config.swap_lctl_lgui) {
              SEND_STRING(SS_LALT("5"));                   //WIN
            } else {
              SEND_STRING(SS_LALT(SS_LSFT("2")));          //MAC
            }
          }
          break;

      case M_QUOTE:
          if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)));
            SEND_STRING(SS_TAP(X_SPACE));
          }
          break;

      case M_SQUOT:
          if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_QUOTE));
            SEND_STRING(SS_TAP(X_SPACE));
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

      case GIPHY:
          if (record->event.pressed) {
            SEND_STRING ("@gif ");
          } 
          break;

      case PRT_MAP:
          if (record->event.pressed) {
            SEND_STRING ("B A S E\n"
"\n"
"|  GESC   |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    |    -    |\n"
"\n"
"|  TAB    |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    |    =    |\n"
"\n"
"|  MUTE   |    A    |    S    |    D    |    F    |    G    |    H    |    J    |    K    |    L    |    ;    |    ''    |\n"
"\n"
"|  SHIFT  |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    ,    |    .    |    /    |  SHIFT  |\n"
"\n"
"|  DEL    |  CTRL   |   ALT   |   GUI   |  LOWER  |  SPACE  |  ENTER  |  RAISE  | BSPACE  | BSLASH  |    [    |    ]    |\n"
"\n"
"\n"
"L O W E R\n"
"\n"
"|  CAPSL  |   F1    |   F2    |   F3    |   F4    |   F5    |   F6    |   F7    |   F8    |   F9    |   F10   |   F11   |\n"
"\n"
"|         |         |         |   UP    |         |         |         |    +    |    7    |    8    |    9    |   F12   |\n"
"\n"
"|  MUTE   |         |  LEFT   |  DOWN   |  RIGHT  |         |         |    -    |    4    |    5    |    6    |         |\n"
"\n"
"|         |         |  PGUP   |         |  PGDWN  |         | AE TRIM |    *    |    1    |    2    |    3    |         |\n"
"\n"
"|         |         |         |         |         |    (    |    )    |    /    |    0    |    =    |  SNAP1  |  SNAP2  |\n"
"\n"
"\n"
"R A I S E\n"
"\n"
"|  CAPSL  |         |         |         |         |         |         |         |         |         |         |         |\n"
"\n"
"|         |         |         |   EU    |         |         |   YEN   |    UE   |         |    OE   |         |         |\n"
"\n"
"|  PLAY   |   AE    |   SZ    |         |         |         |         |         |         |         |         |         |\n"
"\n"
"|         |         |         |   CUE   |         |         |         |         |         |         |         |         |\n"
"\n"
"|         |         |         |         | SPECIAL |         |   AE    |         |         |         |   GMX   |   WEB   |\n"
"\n"
"\n"
"S P E C I A L\n"
"\n"
"|  RESET  | RGB TOG | RGB MOD | RGB HUI | RGB SAT | RGB BRI |         |         |         |         | WINDOWS | MAC OS  |\n"
"\n"
"|  MAKE   |         |         |         |         |         |         |         |         |         | MUS ON  | MUS OFF |\n"
"\n"
"|  CD QMK |         |         |         |         |         |         |         |         |         | DM STOP |         |\n"
"\n"
"|  SHIFT  |         |         |         |         |         |         |         |         |         | DM REC1 | DM PLY1 |\n"
"\n"
"|  PRINT  |         |         |         |         |         |         |         |         |         | DM REC2 | DM PLY2 |\n"
);
          } 
          break;

      case AE_TRIM:
          if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
              SEND_STRING(SS_LSFT(SS_LCTRL("x")));  //WIN
            } else {
              SEND_STRING(SS_LSFT(SS_LGUI("x")));  //MAC
            }
          }
          break;
       
      case KC_R:
        if (IS_LAYER_ON(_AEB)) {
            if(record->event.pressed) {
              encoder_timer = timer_read();
              R_key = true;
            } else {
              R_key = false;
              if (timer_elapsed(encoder_timer) < 500) {
                tap_code(KC_R);
              }
            }
            return false; // We handled this keypress
        }
  

      case KC_T:
        if (IS_LAYER_ON(_AEB)) {
            if(record->event.pressed) {
              encoder_timer = timer_read();
              T_key = true;
            } else {
              T_key = false;
              if (timer_elapsed(encoder_timer) < 500) {
                tap_code(KC_T);
              }
            }
            return false; // We handled this keypress
        }

      case KC_S:
        if (IS_LAYER_ON(_AEB)) {
            if(record->event.pressed) {
              encoder_timer = timer_read();
              S_key = true;
            } else {
              S_key = false;
              if (timer_elapsed(encoder_timer) < 500) {
                tap_code(KC_S);
              }
            }
            return false; // We handled this keypress
        }

      case KC_L:
        if (IS_LAYER_ON(_AEB)) {
            if(record->event.pressed) {
              encoder_timer = timer_read();
              L_key = true;
            } else {
              L_key = false;
              if (timer_elapsed(encoder_timer) < 500) {
                tap_code(KC_L);
              }
            }
            return false; // We handled this keypress
        }

      case KC_M:
        if (IS_LAYER_ON(_AEB)) {
            if(record->event.pressed) {
              encoder_timer = timer_read();
              M_key = true;
            } else {
              M_key = false;
              if (timer_elapsed(encoder_timer) < 500) {
                tap_code(KC_M);
              }
            }
            return false; // We handled this keypress
        }

      case KC_C:
        if (IS_LAYER_ON(_AEB)) {
            if(record->event.pressed) {
              encoder_timer = timer_read();
              C_key = true;
            } else {
              C_key = false;
              if (timer_elapsed(encoder_timer) < 500) {
                tap_code(KC_C);
              }
            }
            return false; // We handled this keypress
        }

      case KC_G:
        if (IS_LAYER_ON(_AEB)) {
            if(record->event.pressed) {
              encoder_timer = timer_read();
              G_key = true;
            } else {
              G_key = false;
              if (timer_elapsed(encoder_timer) < 500) {
                tap_code(KC_G);
              }
            }
            return false; // We handled this keypress
        }

      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50; 



void encoder_update_user(uint8_t index, bool clockwise) {  

// LOWER | NEXT PREV TRACK
if (IS_LAYER_ON(_LOWER)) {
      if (clockwise) {
        tap_code(KC_MNXT);
      } else {
        tap_code(KC_MPRV);
      } 

// RAISE | VOLUME UP DOWN
  } else if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }

// AE R | ROTATE LAYER
  } else if (R_key) {
      if (clockwise) {
        tap_code(KC_PPLS);
      } else {
        tap_code(KC_PMNS);
      }

// AE T | TRANSPARENCY LAYER
  } else if (T_key) {
      if (clockwise) {
        register_code(KC_LCTRL);
        tap_code16(A(KC_PPLS));
        unregister_code(KC_LCTRL);
      } else {
        register_code(KC_LCTRL);
        tap_code16(A(KC_PMNS));
        unregister_code(KC_LCTRL);
      }

// AE S | SCALE LAYER
  } else if (S_key) {
      if (clockwise) {
        tap_code16(A(KC_PPLS));
      } else {
        tap_code16(A(KC_PMNS));
      }


// AE L | CHOOSE LAYER
  } else if (L_key) {
      if (clockwise) {
          if (!keymap_config.swap_lctl_lgui) {    //MAC
            tap_code16(G(KC_DOWN));
          } else {                                //WIN
            tap_code16(C(KC_DOWN));
          }
      } else {
          if (!keymap_config.swap_lctl_lgui) {    //MAC
            tap_code16(G(KC_UP));
          } else {                                //WIN
            tap_code16(C(KC_UP));
          }
      }

// AE M | BLEND MODE
  } else if (M_key) {
      if (clockwise) {
        tap_code16(S(KC_EQL));
      } else {
        tap_code16(S(KC_MINS));
      }

// AE C | COMP TAB 
  } else if (C_key) {
      if (clockwise) {
        register_code(KC_LSFT);
        tap_code16(A(KC_DOT));
        unregister_code(KC_LSFT);
      } else {
        register_code(KC_LSFT);
        tap_code16(A(KC_COMM));
        unregister_code(KC_LSFT);
      }

// AE G | MOVE KEYFRAMES
  } else if (G_key) {
      if (clockwise) {
        tap_code16(A(KC_RIGHT));
      } else {
        tap_code16(A(KC_LEFT));
      }

// AE | MOVE TIMELINE
  } else if (IS_LAYER_ON(_AEB)) {
      if (clockwise) {
        tap_code(KC_PGDN);
      } else {
        tap_code(KC_PGUP);
      }

  } else {
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
  }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case LOWER:
      return false;
    default:
      return true;
  }
}

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ L E D S                                                                                                                                   ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌


const rgblight_segment_t PROGMEM mac_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 1, HSV_ORANGE}
);

const rgblight_segment_t PROGMEM win_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 1, HSV_CYAN}
);

const rgblight_segment_t PROGMEM ae_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 9, 201, 154, 253}
);

const rgblight_segment_t PROGMEM capsl_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_RED}
);


// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    ae_layer,
    mac_layer,
    win_layer, 
    capsl_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _AEB));         // AE 
    rgblight_set_layer_state(1, layer_state_cmp(state, _ADJUST));      // MAC
    if (layer_state_cmp(state, _ADJUST)) {
        rgblight_set_layer_state(2, keymap_config.swap_lctl_lgui);      // WIN
      }
    if (!keymap_config.swap_lctl_lgui) {
      rgblight_set_layer_state(3, capsSetMac);
    }
    //return state;
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool led_update_user(led_t led_state) {
  if (keymap_config.swap_lctl_lgui) {
    rgblight_set_layer_state(3, led_state.caps_lock);
  }
    return true;
}