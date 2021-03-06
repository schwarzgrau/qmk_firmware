/*
.
.
.
.                                                                    ▐████▌
.                                                                    ██████
.                                                                   ████████
.                                                                  ▐████████▌
.                                                                  ████  ████
.                                                                 ████▌  ▐████
.                                                                ▐████    ████▌
.                                                                ████      ████
.                                                               ████▌      ▐████
.                                                              ▐████        ████▌
.                                                              ████          ████
.                                                             ████▌          ▐████
.                                                            ▐████            ████▌
.                                                            ████              ████
.                                                           ████▌              ▐████
.                                                          ▐████                ████▌
.                                                          ████       ████       ████
.                                                         ████        ████        ████
.                                                        ▐████████████████████████████▌
.                                                        ██████████████████████████████
.                                                       ████▌         ████         ▐████
.                                                      ▐████          ████          ████▌
.                                                      ████           ████           ████
.                                                     ████████████████████████████████████
.                                                    ▐████████████████████████████████████▌
.                                                                     ████
.                                                                     ████
.                                                                     ████
.                                                                     ████
.                                                                     ████
.                                                                     ████
.
*/

#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ D E F I N I T I O N S                                                                                                                     ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// █████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████

// ╭───────────────────────────────────────────────────────────╮
// │ d e f i n e   l a y e r s                                 │
// ╰───────────────────────────────────────────────────────────╯ 

#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

// ╭───────────────────────────────────────────────────────────╮
// │ d e f i n e   k e y c o d e s                             │
// ╰───────────────────────────────────────────────────────────╯ 

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MAKE_H,
  CD_QMK,
  M_AE,
  M_UE,
  M_OE,
  WURST,
  WMAIL,
  GMAIL,
  OSXSNP1,
  OSXSNP2,
  MU_TEST1,
  MU_TEST2,
  MU_TEST3
};

// ╭───────────────────────────────────────────────────────────╮
// │ d e f i n e   m a c r o n a m e s                         │
// ╰───────────────────────────────────────────────────────────╯ 

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)


// ╭───────────────────────────────────────────────────────────╮
// │ d e f i n e   s o u n d s                                 │
// ╰───────────────────────────────────────────────────────────╯ 

#ifdef AUDIO_ENABLE
  #define WINXP_SOUND W__NOTE(_DS6), W__NOTE(_REST), S__NOTE(_REST), Q__NOTE(_REST), Q__NOTE(_DS5), H__NOTE(_AS5), H__NOTE(_GS5), H__NOTE(_DS5), H__NOTE(_DS6), H__NOTE(_AS5)

  #define WINXP_SOUND2 W__NOTE(_D5), W__NOTE(_REST), S__NOTE(_D5) //macsound 
  #define WINXP_SOUND3 E__NOTE(_GS6), E__NOTE(_A6), W__NOTE(_REST), ED_NOTE(_E7), S__NOTE(_REST), ED_NOTE(_GS7),

  #define MAC_SOUND S__NOTE(_CS5), B__NOTE(_C5)
  #define AE_SOUND S__NOTE(_A5), E__NOTE(_A6), Q__NOTE(_DS5), E__NOTE(_A5), E__NOTE(_DS5)
  #define AE_SOUND2 E__NOTE(_CS6), Q__NOTE(_E6), H__NOTE(_D4), H__NOTE(_A4)

  float winxp_song[][2] = SONG(WINXP_SOUND);
  float winxp_song2[][2] = SONG(WINXP_SOUND2);
  float winxp_song3[][2] = SONG(WINXP_SOUND3);
  float mac_song[][2] = SONG(MAC_SOUND);
  float ae_song[][2] = SONG(AE_SOUND);
  float ae_song2[][2] = SONG(AE_SOUND2);
#endif // AUDIO


// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ K E Y M A P S                                                                                                                             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// █████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
. ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
. ┃ b a s e                                                   ┃
. ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
. ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓                   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
. ┃   GESC  ┃    1    ┃    2    ┃    3    ┃    4    ┃    5    ┃                   ┃    6    ┃    7    ┃    8    ┃    9    ┃    0    ┃    -    ┃
. ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
. ┃   TAB   ┃    Q    ┃    W    ┃    F    ┃    P    ┃    G    ┃                   ┃    J    ┃    L    ┃    U    ┃    Y    ┃    ;    ┃    \    ┃
. ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
. ┃  SShot  ┃    A    ┃    R    ┃    S    ┃    T    ┃    D    ┃                   ┃    H    ┃    N    ┃    E    ┃    I    ┃    O    ┃    "    ┃
. ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
. ┃  SHIFT  ┃    Z    ┃    X    ┃    C    ┃    V    ┃    B    ┣━━━━━━━━━┳━━━━━━━━━┫    K    ┃    M    ┃    ,    ┃    .    ┃    /    ┃  SHIFT  ┃
. ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  LOWER  ┃  RAISE  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
. ┃   CTL   ┃   ALT   ┃   VOL-  ┃   VOL+  ┃   CMD   ┃  SPACE  ┃         ┃         ┃  ENTER  ┃  BSPC   ┃  DELETE ┃    !    ┃    [    ┃    ]    ┃  
. ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛*/
[_BASE] = LAYOUT( 
//╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
   KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
   KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,                         KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSLS,
   KC_MUTE,  KC_A,     KC_R,     KC_S,     MSFT_T,   KC_D,                         KC_H,     MSFT_N,   KC_E,     KC_I,     KC_O,     KC_DQT,
   KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                         KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
   KC_LCTL,  KC_LALT,  KC_VOLD,  KC_VOLU,  KC_LGUI,  KC_SPC,   LOWER,    RAISE,    KC_ENT,   KC_BSPC,  KC_DEL,   KC_EXLM,  KC_LBRC,  KC_RBRC
  ),

/* 
.┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
.┃ l o w e r                                                 ┃
.┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
.┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓                   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
.┃  RESET  ┃    F1   ┃    F2   ┃    F3   ┃    F4   ┃    F5   ┃                   ┃    F6   ┃    F7   ┃    F8   ┃    F9   ┃   F10   ┃   F11   ┃
.┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
.┃         ┃         ┃         ┃    UP   ┃    =    ┃    {    ┃                   ┃    }    ┃    +    ┃    7    ┃    8    ┃    9    ┃   F12   ┃
.┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
.┃         ┃         ┃   LEFT  ┃   DOWN  ┃  RIGHT  ┃    [    ┃                   ┃    ]    ┃    -    ┃    4    ┃    5    ┃    6    ┃    '    ┃
.┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
.┃         ┃         ┃   PUP   ┃         ┃  PGDWN  ┃    (    ┣━━━━━━━━━┳━━━━━━━━━┫    )    ┃    *    ┃    1    ┃    2    ┃    3    ┃         ┃
.┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫   PLAY  ┃ ADJUST  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
.┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃    0    ┃    =    ┃  MUTE   ┃  PLAY   ┃
.┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛*/
[_LOWER] = LAYOUT(
//╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
   KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11 ,
   XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UP,    KC_EQL,   KC_LCBR,                      KC_RCBR,  KC_PLUS,  KC_P7,    KC_P8,    KC_P9,    KC_F12,
   XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_LBRC,                      KC_RBRC,  KC_MINS,  KC_P4,    KC_P5,    KC_P6,    KC_QUOT,
   XXXXXXX,  XXXXXXX,  KC_PGUP,  XXXXXXX,  KC_PGDN,  KC_LPRN,                      KC_RPRN,  KC_PAST,  KC_P1,    KC_P2,    KC_P3,    _______,
   SNAP2,    SNAP1,    _______,  _______,  _______,  KC_MPLY,  _______,  ADJUST,   _______,  _______,  KC_P0,    KC_EQL,   KC_MUTE,  KC_MPLY  
  ),
  
/* 
.┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
.┃ r a i s e                                                 ┃
.┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
.┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓                   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
.┃         ┃    F1   ┃    F2   ┃    F3   ┃    F4   ┃    F5   ┃                   ┃    F6   ┃    F7   ┃    F8   ┃    F9   ┃   F10   ┃   F11   ┃
.┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
.┃         ┃         ┃         ┃   EU    ┃         ┃         ┃                   ┃   YEN   ┃    Ü    ┃         ┃    Ö    ┃         ┃         ┃
.┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
.┃         ┃    Ä    ┃    SZ   ┃         ┃         ┃         ┃                   ┃         ┃         ┃         ┃         ┃         ┃         ┃
.┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
.┃         ┃         ┃         ┃   CUE   ┃         ┃         ┣━━━━━━━━━┳━━━━━━━━━┫         ┃         ┃         ┃         ┃         ┃         ┃
.┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  ADJUST ┃         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
.┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃  
.┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
*/

[_RAISE] = LAYOUT(
  XXXXXXX,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11 ,
  XXXXXXX,   XXXXXXX,  XXXXXXX,  S(LALT(KC_2)),XXXXXXX,XXXXXXX,                    LALT(KC_Y),M_UE,    XXXXXXX,  M_OE,     XXXXXXX,  KC_F12 ,
  XXXXXXX,   M_AE,     LALT(KC_S),XXXXXXX, XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX ,
  XXXXXXX,   XXXXXXX,  XXXXXXX,  LALT(KC_C),XXXXXXX, XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX ,
  MU_TEST1,  MU_TEST2,  MU_TEST3,  XXXXXXX,  XXXXXXX,  XXXXXXX,  ADJUST,   _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),


  
[_ADJUST] = LAYOUT(
  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX ,
  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX ,
  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX ,
  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX ,
  XXXXXXX,   XXXXXXX,  AU_OFF,   AU_ON,    XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MU_ON,    MU_OFF
  )
  

  /*
[_TRNS] = LAYOUT(
  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX ,
  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX ,
  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX ,
  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX ,
  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),
  */
};


#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif


// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ M A C R O S                                                                                                                               ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

      case MAKE_H:
          if (record->event.pressed) {
            SEND_STRING ("make aplus:default");
            register_code(KC_ENTER);
            unregister_code(KC_ENTER);
          } 
          break;

      case CD_QMK:
          if (record->event.pressed) {
            SEND_STRING ("cd /Users/schwarygrau/qmk_firmware");
            register_code(KC_ENTER);
            unregister_code(KC_ENTER);
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

      case OSXSNP1:
          if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_LCMD("4"))); 
          }
          break;

      case OSXSNP2:
          if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL("4")))); 
          }
          break;

      case WMAIL:
          if (record->event.pressed) {
            SEND_STRING ("igit.igit@web.de");
          } 
          break;

      case WURST:
        if (record->event.pressed) {
          SEND_STRING ("wurst");
          register_code(KC_ENTER);
          unregister_code(KC_ENTER);
          } 
        break;

      case GMAIL:
          if (record->event.pressed) {
            SEND_STRING ("igit@gmx.de");
          }
        break;

      case MU_TEST1:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(winxp_song);
            #endif
          }
          break;

        case MU_TEST2:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(winxp_song2);
            #endif
          }
          break;

      case MU_TEST3:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(winxp_song3);
            #endif
          }
          break;
      }
  return true;
}