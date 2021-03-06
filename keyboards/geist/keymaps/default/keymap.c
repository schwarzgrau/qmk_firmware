/*                                                                       ▐
.                                                                        ▟
.                                                                      ▁▟█            
.                                                                  ▁▂▄▇███            ▙
.                                                                ▝▀▀▀▀████            ██▄▂
.                                             ▝▀██████████ ██████████ ████ ██████████▀████▀▀▀▀ 
.                                               ████  ████ ████  ████ ████ ████  ████ ████
.                                               ████  ████ ████  ████ ▄▄▄▄ ████  ████ ████
.                                               █▓▓█  █▀▀  █▓▓█  █▓▓█ █▓▓█ █▓▓█  █▀▀  █▓▓█  
.                                               █▓▓█ ▄▄▄▄▄ █▓▓█▄▄███▀ ████ ▜███▄▄▄▄▄▂ █▓▓█
.                                               █▓██  ████ █▓██  ▄▄▂  ████  ▂▄▄  ████ █▓██  ▄▄▂
.                                               ████  ████ ████  ████ ████ ████  ████ ████  ████▀
.                                               ██▓█  █▓██ ██▓█  █▓██ ██▓█ ██▓█  █▓██ ██▓█  █▓██
.                                               █▓▒█  █▒▓█ █▓▒█  █▒▓█ █▓▓█ █▓▒█  █▒▓█ █▓▒█  █▒▓█  
.                                               █▒░█  █░▒█ █▒░█  █░▒█ █▒▒█ █▒░█  █░▒█ █▒░█  █░▒█ 
.                                             ▗ █▖ █▂▂█ ▗█ █▖ █▂▂█ ▗█ █▒▒█ █▖ █▂▂█ ▗█ █▖ █▂▂█  █ 
.                                         ░▒  ▓▄ ▀▙▄▄▄▄▟▀ ▄ ▀▙▄▄▄▄▟▀  █▒▒█  ▀▙▄▄▄▄▟▀ ▄ ▀▙▄▄▄▄▄▄█ ▒░ ░
.                                      ░ ░░░▒▓█▓█▄▄▄▄▄▄▄▄▓▓█▄▄▄▄▄▄▄▄█ █░░█ █▄▄▄▄▄▄▄▄██▓▄▄▄▄▄▄▄▄▄▄█▓▒▒░░ ░
.                                       ▁▁▁▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█░ █ ┳  ╹┳ ┳ ┳┏━━┳━┳ ┳━┳━┳┏━┓┳━━┓
.                                              ▔▔▔▔▀▀▀▀▀▀██▆▆▆▆▅▅▅▄▄▄▄▄  █ ┃  ┃┃ ┗┳┛┗━┓┣━┫ ┃ ┃ ┃┃ ┃┃  ┃
.                                                                ▔▔▔▔▀▀▀▙█ ┻━┛┻┻━┛┻ ┗━┛┗━┛ ┻ ┻ ┻┗━┛┻━━┛ 
.                                                                        ▀                                                                           
*/
#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#ifdef POINTING_DEVICE_ENABLE
  #include "analog.h"
  #include "pointing_device.h"
#endif

extern uint8_t is_master;

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ D E F I N I T I O N S                                                                                                                     ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌

// ╭───────────────────────────────────────────────────────────╮
// │ d e f i n e   l a y e r s                                 │
// ╰───────────────────────────────────────────────────────────╯ 

enum layer_number {
  _QWERTY = 0,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _TVP,
  _TVP2
};


// ╭───────────────────────────────────────────────────────────╮
// │ d e f i n e   k e y c o d e s                             │
// ╰───────────────────────────────────────────────────────────╯ 

enum custom_keycodes {
  BASE = SAFE_RANGE,
  QWERTY,
  COLEMAK,
  LOWER,
  RAISE,
  TVP,
  TVP2,
  MAKE_H,
  CD_QMK,
  MS_BTN1,
  WMAIL,
  GMAIL,
  SNAP1,
  SNAP2,
  GIPHY,
  OS_SWAP,
  T_TSNP,
  T_SSNP,
  T_UNDO,
  T_REDO,
  T_SOLO,
  T_IMARK,
  T_NKEY,
  T_DKEY,
  T_BMARK,
  T_SELECT,
  T_MOVE,
  T_TRSFM,
  T_WARP,
  T_DJV,
  T_TELE
};


// ╭───────────────────────────────────────────────────────────╮
// │ d e f i n e   m a c r o n a m e s                         │
// ╰───────────────────────────────────────────────────────────╯ 

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TVP TO(_TVP)
#define TVP2 MO(_TVP2)
#define MSFT_T MT(MOD_LSFT, KC_T)
#define MSFT_N MT(MOD_RSFT, KC_N)


// ╭───────────────────────────────────────────────────────────╮
// │ d e f i n e   s o u n d s                                 │
// ╰───────────────────────────────────────────────────────────╯ 

#ifdef AUDIO_ENABLE
  #define WINXP_SOUND W__NOTE(_DS6), Q__NOTE(_DS5), H__NOTE(_AS5), H__NOTE(_GS5), H__NOTE(_DS5), H__NOTE(_DS6), H__NOTE(_AS5)
  #define MAC_SOUND S__NOTE(_CS5), B__NOTE(_C5)
  #define GODZILLA_SOUND Q__NOTE(_F4), Q__NOTE(_G4), Q__NOTE(_BF4), Q__NOTE(_G4), HD_NOTE(_D5), HD_NOTE(_D5), W__NOTE(_C5), S__NOTE(_REST)

  float winxp_song[][2] = SONG(WINXP_SOUND);
  float mac_song[][2] = SONG(MAC_SOUND);
  float godzilla_song[][2] = SONG(GODZILLA_SOUND);
#endif // AUDIO


// ╭───────────────────────────────────────────────────────────╮
// │ i n t   v a r s                                           │
// ╰───────────────────────────────────────────────────────────╯ 


bool int_press = false;
bool interrupt = false;
char int_code[24];
char int_replacement_code[24];
static uint16_t int_duration;
static uint16_t int_timer;


// ╭───────────────────────────────────────────────────────────╮
// │ j o y s t i c k   v a r s                                 │
// ╰───────────────────────────────────────────────────────────╯

bool l_analog = false;
bool r_analog = false;
bool u_analog = false;
bool d_analog = false;

int xPin = 2; //F4
int yPin = 3; //F5

int xOrigin, yOrigin;
int xOrigin_b, yOrigin_b;

int minAxisValue = 0;
int maxAxisValue = 1023;
int rstAxisValue = 512;

int savRange = 80;
int actRange = 100;

bool x_moved = false;
bool y_moved = false;

int maxCursorSpeed = 4;
int precisionSpeed = 1;

int xPolarity = 1;
int yPolarity = -1;

int cursorTimeout = 10;


// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ K E Y M A P S                                                                                                                             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 ┃ q w e r t y                                               ┃
 ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
 ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓                   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
 ┃   GESC  ┃    1    ┃    2    ┃    3    ┃    4    ┃    5    ┃                   ┃    6    ┃    7    ┃    8    ┃    9    ┃    0    ┃    =    ┃
 ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
 ┃   Tab   ┃    Q    ┃    W    ┃    E    ┃    R    ┃    T    ┃                   ┃    Y    ┃    U    ┃    I    ┃    O    ┃    ;    ┃    -    ┃
 ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
 ┃ CtlCaps ┃    A    ┃    S    ┃    D    ┃    F    ┃    G    ┣━━━━━━━━━┳━━━━━━━━━┫    H    ┃    J    ┃    K    ┃    L    ┃    P    ┃    "    ┃
 ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫   XXX   ┃  CLICK  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
 ┃ Shift[  ┃    Z    ┃    X    ┃    C    ┃    V    ┃    B    ┣━━━━━━━━━┻━━━━━━━━━┫    N    ┃    M    ┃    ,    ┃    .    ┃    /    ┃ Shift]  ┃
 ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┳━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
                               ┃   Alt   ┃   Cmd   ┃  LOWER  ┃  Space  ┃  Enter  ┃  RAISE  ┃  Bspace ┃   Del   ┃  
                               ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ */
[_QWERTY] = LAYOUT( 
//╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
   KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_SCLN,  KC_EQL, 
   KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     KC_P,     KC_DQT, 
SFT_T(KC_LBRC),KC_Z,   KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  MS_BTN1,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SFT_T(KC_RBRC), 
                                 KC_LALT,  KC_LGUI,  LOWER,    KC_SPC,   KC_ENT,   RAISE,    KC_BSPC,  KC_DEL
  ),
/*
  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄

 ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 ┃ c o l e m a k                                             ┃
 ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
 ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓                   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
 ┃   GESC  ┃    1    ┃    2    ┃    3    ┃    4    ┃    5    ┃                   ┃    6    ┃    7    ┃    8    ┃    9    ┃    0    ┃    =    ┃
 ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
 ┃   Tab   ┃    Q    ┃    W    ┃    F    ┃    P    ┃    G    ┃                   ┃    J    ┃    L    ┃    U    ┃    Y    ┃    ;    ┃    -    ┃
 ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
 ┃ CtlCaps ┃    A    ┃    R    ┃    S    ┃    T    ┃    D    ┣━━━━━━━━━┳━━━━━━━━━┫    H    ┃    N    ┃    E    ┃    I    ┃    O    ┃    "    ┃
 ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫   XXX   ┃  CLICK  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
 ┃ Shift[  ┃    Z    ┃    X    ┃    C    ┃    V    ┃    B    ┣━━━━━━━━━┻━━━━━━━━━┫    K    ┃    M    ┃    ,    ┃    .    ┃    /    ┃ Shift]  ┃
 ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┳━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
                               ┃   Alt   ┃   Cmd   ┃  LOWER  ┃  Space  ┃  Enter  ┃  RAISE  ┃  Bspace ┃   Del   ┃  
                               ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ */
[_COLEMAK] = LAYOUT( 
//╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
   KC_GESC,  KC_1,     KC_2,     KC_3,     KC_3,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
   KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,                         KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_EQL, 
   KC_LCTL,  KC_A,     KC_R,     KC_S,     MSFT_T,   KC_D,                         KC_H,     MSFT_N,   KC_E,     KC_I,     KC_O,     KC_QUOT, 
SFT_T(KC_LBRC),KC_Z,   KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  MS_BTN1,  KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SFT_T(KC_RBRC), 
                                 KC_LALT,  KC_LGUI,  LOWER,    KC_SPC,   KC_ENT,   RAISE,    KC_BSPC,  KC_DEL
  ),
/*
  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
 
  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃ l o w e r                                                 ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  
  ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓                   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
  ┃  CAPSL  ┃    F1   ┃    F2   ┃    F3   ┃    F4   ┃    F5   ┃                   ┃    F6   ┃    F7   ┃    F8   ┃    F9   ┃   F10   ┃   F11   ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃         ┃         ┃         ┃   UP    ┃    =    ┃    {    ┃                   ┃    }    ┃    +    ┃    7    ┃    8    ┃    9    ┃   F12   ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃         ┃         ┃  LEFT   ┃  DOWN   ┃  RIGHT  ┃    [    ┣━━━━━━━━━┳━━━━━━━━━┫    ]    ┃    -    ┃    4    ┃    5    ┃    6    ┃    '    ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫   XXX   ┃  SNAP1  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃   TVP   ┃         ┃  PGUP   ┃         ┃  PGDWN  ┃    (    ┣━━━━━━━━━┻━━━━━━━━━┫    )    ┃    *    ┃    1    ┃    2    ┃    3    ┃         ┃
  ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┳━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
                                ┃  VDWN   ┃   VUP   ┃         ┃  PLAY   ┃         ┃         ┃    =    ┃    0    ┃  
                                ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ */
[_LOWER] = LAYOUT(
//╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
   KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
   XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UP,    KC_EQL,   KC_LCBR,                      KC_RCBR,  KC_PLUS,  KC_P7,    KC_P8,    KC_P9,    KC_F12, 
   XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_LBRC,                      KC_RBRC,  KC_MINS,  KC_P4,    KC_P5,    KC_P6,    KC_QUOT, 
   TVP,      XXXXXXX,  KC_PGUP,  XXXXXXX,  KC_PGDN,  KC_LPRN,  XXXXXXX,  SNAP1,    KC_RPRN,  KC_PAST,  KC_P1,    KC_P2,    KC_P3,    _______,    
                                 KC_VOLD,  KC_VOLU,  _______,  KC_MPLY,  _______,  _______,  KC_EQL,   KC_P0
  ),
/*
  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄

  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃ r a i s e                                                 ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
  ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓                   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
  ┃  CAPSL  ┃    F1   ┃    F2   ┃    F3   ┃    F4   ┃    F5   ┃                   ┃    F6   ┃    F7   ┃    F8   ┃    F9   ┃   F10   ┃   F11   ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃         ┃    !    ┃    @    ┃    #    ┃    $    ┃    %    ┃                   ┃    ˆ    ┃    &    ┃    Ü    ┃   YEN   ┃         ┃   F12   ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃   GMX   ┃    Ä    ┃         ┃    SZ   ┃         ┃    $    ┣━━━━━━━━━┳━━━━━━━━━┫         ┃         ┃   EU    ┃    £    ┃    Ö    ┃         ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫   XXX   ┃  SNAP2  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃   WEB   ┃         ┃         ┃   CUE   ┃         ┃         ┣━━━━━━━━━┻━━━━━━━━━┫         ┃         ┃         ┃ DM REC1 ┃ DM STOP ┃ DM PLY1 ┃
  ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┳━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
                                ┃  GIPHY  ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃  
                                ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ */
[_RAISE] = LAYOUT(
//╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
   KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11, 
   XXXXXXX,  XXXXXXX,  XXXXXXX,  S(LALT(KC_2)),XXXXXXX,XXXXXXX,                    XXXXXXX,  XXXXXXX,  RALT(KC_U), RALT(KC_Y),XXXXXXX, XXXXXXX, 
   GMAIL,    RALT(KC_A),XXXXXXX, LALT(KC_S), XXXXXXX, XXXXXXX,                     XXXXXXX,  XXXXXXX,  RALT(KC_5), XXXXXXX, RALT(KC_O), XXXXXXX,
   WMAIL,    XXXXXXX,  XXXXXXX,  RALT(KC_C), XXXXXXX, XXXXXXX, XXXXXXX,  SNAP2,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSLS,  XXXXXXX, 
                                 GIPHY,    XXXXXXX,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX
  ),
/*
  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄


  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃ a d j u s t                                               ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
  ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓                   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
  ┃  RESET  ┃  DEBUG  ┃         ┃         ┃         ┃         ┃                   ┃         ┃         ┃         ┃         ┃         ┃ QWERTY  ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃  MAKE   ┃         ┃         ┃         ┃         ┃         ┃                   ┃         ┃         ┃         ┃         ┃         ┃ COLEMAK ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃  CD QMK ┃         ┃         ┃         ┃         ┃         ┣━━━━━━━━━┳━━━━━━━━━┫         ┃         ┃         ┃         ┃         ┃         ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫   XXX   ┃         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃ OS SWAP ┃         ┃         ┃         ┃         ┃         ┣━━━━━━━━━┻━━━━━━━━━┫         ┃         ┃         ┃         ┃         ┃         ┃
  ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┳━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
                                ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃  
                                ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ */
[_ADJUST] = LAYOUT(
//╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
   RESET,    DEBUG,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QWERTY, 
   MAKE_H,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  COLEMAK,
   CD_QMK,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
   OS_SWAP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
                                 XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX
  ),
/*
  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄

 
  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃ t v p                                                     ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
  ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓                   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
  ┃         ┃         ┃ DJVlast ┃   DJV   ┃ DJVnext ┃ Mirror  ┃                   ┃         ┃         ┃         ┃         ┃         ┃         ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃   TAB   ┃  Flip   ┃  MarkIn ┃  Rotate ┃ MarkOut ┃ ShwSnap ┃                   ┃         ┃         ┃         ┃         ┃         ┃         ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃  TVP2   ┃ TG LgTa ┃  Left   ┃   Pan   ┃  Right  ┃  Play   ┣━━━━━━━━━┳━━━━━━━━━┫  TLGRM  ┃  BASE   ┃         ┃         ┃         ┃         ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫   XXX   ┃         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃  Shift  ┃ Fullscr ┃  Copy   ┃  Delete ┃  Paste  ┃IMark/Clr┣━━━━━━━━━┻━━━━━━━━━┫         ┃  NEXT   ┃  LAST   ┃         ┃         ┃         ┃
  ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┳━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
                                ┃Transform┃  Move   ┃  Select ┃Undo/Save┃ PLY/PSE ┃  MUTE   ┃  VOLUP  ┃  VOLDN  ┃  
                                ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ */
[_TVP] = LAYOUT(
//╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
   XXXXXXX,  XXXXXXX,  KC_PGUP,  T_DJV,    KC_PGDN,  KC_LBRC,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
   KC_TAB,   KC_W,     KC_I,     C(KC_LALT),KC_O,    T_SSNP,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
   TVP2,     C(KC_L),  KC_LEFT,  KC_LALT,  KC_RIGHT, KC_SPC,                       T_TELE,   BASE,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
   KC_LSFT,  KC_J,     C(KC_C),  KC_BSPC,  C(KC_V),  T_IMARK,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MNXT,  KC_MPRV,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
                                 T_TRSFM,  T_MOVE,   T_SELECT, T_UNDO,   KC_MPLY,  KC_MUTE,  KC_VOLU,  KC_VOLD
  ),
/*
  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄

 
  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃ t v p 2                                                   ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  
  ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓                   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
  ┃         ┃         ┃         ┃         ┃         ┃ Mirror2 ┃                   ┃         ┃         ┃         ┃         ┃         ┃         ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃         ┃         ┃  TgMin  ┃  RstRot ┃  TgMout ┃  Snap   ┃                   ┃         ┃         ┃         ┃         ┃         ┃         ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                   ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃   ---   ┃Solo/TgSk┃  LstK   ┃  NewK   ┃  NxtK   ┃  Enter  ┣━━━━━━━━━┳━━━━━━━━━┫         ┃         ┃         ┃         ┃         ┃         ┃
  ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫   XXX   ┃         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
  ┃         ┃  FSapp  ┃ CPY2bru ┃  DelHd  ┃ PSTinPL ┃BMark/Clr┣━━━━━━━━━┻━━━━━━━━━┫         ┃         ┃         ┃         ┃         ┃         ┃
  ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┳━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
                                ┃  Warp   ┃  PickL  ┃  BASE   ┃Redo/Sav1┃         ┃         ┃         ┃         ┃  
                                ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ */
[_TVP2] = LAYOUT(
//╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RBRC,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
   XXXXXXX,  XXXXXXX,  S(KC_I),  S(KC_HOME),S(KC_O), T_TSNP,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
   _______,  T_SOLO,   S(KC_LEFT),T_NKEY,  S(KC_RIGHT),KC_ENT,                     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
   XXXXXXX,  S(KC_J),  S(KC_C),  T_DKEY,   S(KC_V),  T_BMARK,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
                                 T_WARP,   KC_P,     BASE,     T_REDO,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  )

//▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄

};


// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ J O Y S T I C K   K E Y M A P S                                                                                                           ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌

char a_keys[7][4][24] = {
/*
.┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
.┃ q w e r t y                                      ┃
.┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
.                   ┏━━━━━━━━━━━┓
.                   ┃           ┃
.       ┏━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┓
.       ┃           ┃           ┃           ┃
.       ┗━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┛
.                   ┃           ┃
.                   ┗━━━━━━━━━━━┛
*/
[_QWERTY]  =  {
                        "up",
            "left",              "right",
                        "down"
            },
/*
.┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
.┃ c o l e m a k                                    ┃
.┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
.                   ┏━━━━━━━━━━━┓
.                   ┃PLAY/PAUSE ┃
.       ┏━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┓
.       ┃   LAST    ┃           ┃   NEXT    ┃
.       ┗━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┛
.                   ┃   MUTE    ┃
.                   ┗━━━━━━━━━━━┛
*/
[_COLEMAK]  =  {
                    SS_TAP(X_MPLY),
      SS_TAP(X_MRWD),            SS_TAP(X_MFFD),
                    SS_TAP(X_MUTE)
            },
/*
.┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
.┃ l o w e r                                        ┃
.┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
.                   ┏━━━━━━━━━━━┓
.                   ┃PLAY/PAUSE ┃
.       ┏━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┓
.       ┃   LAST    ┃           ┃   NEXT    ┃
.       ┗━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┛
.                   ┃   MUTE    ┃
.                   ┗━━━━━━━━━━━┛
*/
[_LOWER]  =  {
                    SS_TAP(X_MPLY),
      SS_TAP(X_MRWD),            SS_TAP(X_MFFD),
                    SS_TAP(X_MUTE)
            },
/*
.┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
.┃ r a i s e                                        ┃
.┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
.                   ┏━━━━━━━━━━━┓
.                   ┃     [     ┃
.       ┏━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┓
.       ┃     (     ┃           ┃     )     ┃
.       ┗━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┛
.                   ┃     ]     ┃
.                   ┗━━━━━━━━━━━┛
*/
[_RAISE]  =  {
                    SS_TAP(X_LBRC),
  SS_LSFT("9"),                       SS_LSFT("0"),
                    SS_TAP(X_RBRC)
            },
/*
.┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
.┃ t v p                                            ┃
.┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
.                   ┏━━━━━━━━━━━┓
.                   ┃ NewALayer ┃
.       ┏━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┓
.       ┃ DelLayer  ┃           ┃ DuplLayer ┃
.       ┗━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┛
.                   ┃ NewLayer  ┃
.                   ┗━━━━━━━━━━━┛
*/
[_TVP]  =  {
                    SS_LCTL("a"),
  SS_DOWN(X_LSFT) SS_TAP(X_BSPC) SS_UP(X_LSFT),              SS_LSFT("d"),
                   SS_LCTL("n")
            },
/*
.┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
.┃ t v p 2                                          ┃
.┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
.                   ┏━━━━━━━━━━━┓
.                   ┃           ┃
.       ┏━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┓
.       ┃           ┃           ┃           ┃
.       ┗━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┛
.                   ┃           ┃
.                   ┗━━━━━━━━━━━┛
*/
[_TVP2]  =  {
                        "up5",
            "left5",              "right5",
                        "down5"
            },
/*
.┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
.┃ a d j u s t                                      ┃
.┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
.                   ┏━━━━━━━━━━━┓
.                   ┃           ┃
.       ┏━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┓
.       ┃           ┃           ┃           ┃
.       ┗━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┛
.                   ┃           ┃
.                   ┗━━━━━━━━━━━┛
*/
[_ADJUST]  =  {
                        "up5",
            "left5",              "right5",
                        "down5"
            },
};


// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ O L E D                                                                                                                                   ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌


// ╭───────────────────────────────────────────────────────────╮
// │ d y n a m i c   m a c r o                                 │
// ╰───────────────────────────────────────────────────────────╯ 

char layer_state_str[24];
int base_layer = 1;
char p_text[24] = "$$$$$$$$";

int dmacro_num = 0;  
char dmacro_text[4][24] = { "", "RECORDING", "STOP RECORDING",  "PLAY RECORDING"};
static uint16_t dmacro_timer;

char my_print[48];

/*
// DYNMACRO RECORD ├─────────────────────────────────────────────────────────────┐
void dynamic_macro_record_start_user(void) {
      dmacro_num = 1;
    return;
}

// DYNMACRO STOP RECORDING ├─────────────────────────────────────────────────────┐
void dynamic_macro_record_end_user(int8_t direction) {
      dmacro_num = 2;
      dmacro_timer = timer_read();
    return; 
}

// DYNMACRO PLAY RECORDING ├─────────────────────────────────────────────────────┐
void dynamic_macro_play_user(int8_t direction) {
      dmacro_num = 3;
      dmacro_timer = timer_read();
    return; 
}

// PRINT IT ├────────────────────────────────────────────────────────────────────┐
const char *read_my_print(void) {
    snprintf(my_print, sizeof(my_print), "%s\n", p_text);
  return my_print;
}
*/

int layerstate = 0;

layer_state_t layer_state_set_kb(layer_state_t state) {
  layerstate = get_highest_layer(state);
  switch (get_highest_layer(state)) {
    case _QWERTY:
      strcpy ( layer_state_str, "$$$$$$$$" );
      base_layer = 1;
      break;
    case _COLEMAK:
      strcpy ( layer_state_str, "$$$$$$$$" );
      base_layer = 1;
      break;
    case _LOWER:
      strcpy ( layer_state_str, "<<<<" );
      base_layer = 0;
      break;
    case _RAISE:
      strcpy ( layer_state_str, ">>>>>>>>>>>>" );
      base_layer = 0;
      break;
    case _TVP:
      strcpy ( layer_state_str, "%%%%%%%%" );
      base_layer = 0;
      break;
    case _TVP2:
      strcpy ( layer_state_str, "%%%%%%%%%%%%%%" );
      base_layer = 0;
      break;
    }
    if (dmacro_num < 1) {
      strcpy ( p_text, layer_state_str );
    }
  //return state;
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void matrix_scan_user(void) {

 // Joystick Directions 
 if(u_analog == true) {
      send_string(a_keys[layerstate][0]);
      u_analog = false;
   }

       if(l_analog == true) {
      send_string(a_keys[layerstate][1]);
      l_analog = false;
   }

       if(r_analog == true) {
      send_string(a_keys[layerstate][2]);
      r_analog = false;
   }

       if(d_analog == true) {
      send_string(a_keys[layerstate][3]);
      d_analog = false;
   }


   // Interrupted Press
   if(int_press) {
      if (timer_elapsed(int_timer) > int_duration) {
            send_string (int_replacement_code);
            #ifdef HAPTIC_ENABLE
              DRV_pulse(soft_bump);
            #endif // HAPTIC
            interrupt = true;
            int_press = false;
       } 
    }

    // DynMacroTimer
    if(dmacro_num > 0){
        if (timer_elapsed(dmacro_timer) < 3000) {
            strcpy ( p_text, dmacro_text[dmacro_num] );
          }
        else {
            if (dmacro_num == 1) {
                strcpy ( p_text, dmacro_text[1] );
              }
            else {
                strcpy ( p_text, layer_state_str );
                dmacro_num = 0;
              }
          }
      }
}


//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
//const char *read_logo(void);
//void set_keylog(uint16_t keycode, keyrecord_t *record);
//const char *read_keylog(void);
//const char *read_keylogs(void);
const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write(read_mode_icon(keymap_config.swap_lctl_lgui), false);
    oled_write(read_layer_state(), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_mode_icon(keymap_config.swap_lctl_lgui), false);
    oled_write(read_layer_state(), false);
  }
}
#endif // OLED_DRIVER_ENABLE


// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ J O Y S T I C K                                                                                                                           ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌

// MOUSE STUFF ├─────────────────────────────────────────────────────────────┐

#ifdef POINTING_DEVICE_ENABLE

    uint16_t lastCursor = 0;

    int axisCoordinate(int pin, int origin) {
      int direction;
      int distanceFromOrigin;
      int range;

      int position = analogRead(pin);

      if ((origin - 90) > position) {
        distanceFromOrigin = origin - position;
        range = origin - minAxisValue;
        direction = -1;
      } else if ((origin + 90) < position){
        distanceFromOrigin = position - origin;
        range = maxAxisValue - origin;
        direction = 1;
      } else {
        return 0;
      } 

      float percent = (float)distanceFromOrigin / range;
        int coordinate = (int)(percent * 100);
        if (coordinate < 0) {
          return 0;
        }
        else if (coordinate > 100) {
          return 100 * direction;
        }
        else {
          return coordinate * direction;
        }
    }

    int axisToMouseComponent(int pin, int origin, int maxSpeed, int polarity) {
      int coordinate = axisCoordinate(pin, origin);
      //print_decs(coordinate); println();
      if (coordinate == 0) {
        return 0;
      }
      else {
        float percent = (float)coordinate / 100;
            if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                return percent * precisionSpeed * polarity * (abs(coordinate) / 6);
            } else {
                return percent * maxCursorSpeed * polarity * (abs(coordinate) / 6);
            }
        }
    }



// FOR BOTH APPLICATIONS ├──────────────────────────────────────────────────────────┐

void pointing_device_task(void) {
  
    if (IS_LAYER_ON(_QWERTY) || IS_LAYER_ON(_COLEMAK)) {                  //If base layer

          report_mouse_t currentReport;
          currentReport.x = 0;
          currentReport.y = 0;
          currentReport.h = 0;
          currentReport.v = 0;

          if (timer_elapsed(lastCursor) > cursorTimeout) {
                lastCursor = timer_read();
                currentReport.x = axisToMouseComponent(xPin, xOrigin, maxCursorSpeed, xPolarity);
                currentReport.y = axisToMouseComponent(yPin, yOrigin, maxCursorSpeed, yPolarity);
          }

          pointing_device_set_report(currentReport);
          pointing_device_send();

  } else {                                  //If not base layer

// KEYPRESSES ├────────────────────────────────────────────────────────────────────┐

        xOrigin_b = analogRead(xPin);
        yOrigin_b = analogRead(yPin);

        if (x_moved == false && y_moved == false) {   //if not yet moved

              if(xOrigin_b < rstAxisValue-actRange) {
                    l_analog = true;
                    x_moved = true;
                    //uprintf("left: %u\n", xOrigin_b);
              }

              if(xOrigin_b > rstAxisValue+actRange) {
                    r_analog = true;
                    x_moved = true;
                    //uprintf("right: %u\n", xOrigin_b);
              }

              if(yOrigin_b > rstAxisValue+actRange) {
                    u_analog = true;
                    y_moved = true;
                    //uprintf("up: %u\n", yOrigin_b);
              }

              if(yOrigin_b < rstAxisValue-actRange) {
                    d_analog = true;
                    y_moved = true;
                    //uprintf("down: %u\n", yOrigin_b);               
              }
        }

        if(xOrigin_b < (rstAxisValue+savRange) && xOrigin_b > (rstAxisValue-savRange)) {
              x_moved = false;
        }
                
        if(yOrigin_b < (rstAxisValue+savRange) && yOrigin_b > (rstAxisValue-savRange)) {
              y_moved = false;
        }

    } //If not base layer END
}     
                              

void matrix_init_kb(void) {
  timer_init();
  xOrigin = analogRead(xPin);
  yOrigin = analogRead(yPin);
}

#endif // POINTING


// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ F U N C T I O N S                                                                                                                         ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌


// ╭───────────────────────────────────────────────────────────╮
// │ i n t e r r u p t e d   p r e s s                         │
// ╰───────────────────────────────────────────────────────────╯ 

bool replace_on_hold_int(const char code[24], const char replacement_code[24], uint16_t duration, bool pressed) {
  if(pressed) {
      int_press = true;
      interrupt = false;
      strcpy (int_code, code);
      strcpy (int_replacement_code, replacement_code);
      int_duration = duration;
      int_timer = timer_read();
    }
  else {
      if(interrupt == false) {
        send_string (code);
        int_press = false;
      }
    }
  return false;
}


// ╭───────────────────────────────────────────────────────────╮
// │ t v p   s e l e c t i o n                                 │
// ╰───────────────────────────────────────────────────────────╯ 

bool t_djvplayer = false;

bool t_selection = false;
bool t_moved = false;
bool t_transform = false;

bool t_deselect_brush(void) {
  t_selection = false;
  t_moved = false;
  t_transform = false;
  #ifdef HAPTIC_ENABLE
    DRV_pulse(transition_rampdown_short_smooth1_50);
  #endif // HAPTIC
  SEND_STRING("d");
  SEND_STRING("b");
  return false;

}

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ M A C R O S                                                                                                                               ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌

report_mouse_t currentReport = {};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

      case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
            #ifdef HAPTIC_ENABLE
              DRV_pulse(pulsing_strong);
            #endif // HAPTIC
          } 
          break;

      case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
            #ifdef HAPTIC_ENABLE
              DRV_pulse(pulsing_strong);
            #endif // HAPTIC
          } 
          break;

      case OS_SWAP: 
          if (record->event.pressed) {
              if (!keymap_config.swap_lctl_lgui) {
                keymap_config.swap_lctl_lgui = true;  //WIN
                //PLAY_SONG(winxp_song);
                }
               else {
                 keymap_config.swap_lctl_lgui = false; //MAC
                 //PLAY_SONG(mac_song);
                }
          eeconfig_update_keymap(keymap_config.raw);
          clear_keyboard();  // clear to prevent stuck keys    
          return false;
          }

      case BASE:
          if (record->event.pressed) {
            layer_off(_TVP);
            #ifdef HAPTIC_ENABLE
              DRV_pulse(pulsing_strong);
            #endif // HAPTIC
          } 
          break;          

      case TVP:
          if (record->event.pressed) {
            #ifdef HAPTIC_ENABLE
              DRV_pulse(transition_hum);
            #endif // HAPTIC
            if (keymap_config.swap_lctl_lgui) {
                                                                    //WIN
            } else {
              SEND_STRING (SS_LSFT(SS_LALT(SS_LGUI("t"))));         //MAC
            }
          } 
          break;

      case MAKE_H:
          if (record->event.pressed) {
            SEND_STRING ("make geist:default");
            register_code(KC_ENTER);
            unregister_code(KC_ENTER);
            #ifdef AUDIO_ENABLE
              PLAY_SONG(godzilla_song);
            #endif
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

      case MS_BTN1:
      #ifdef POINTING_DEVICE_ENABLE
        if (record->event.pressed) {
          currentReport.buttons |= MOUSE_BTN1; //MOUSE_BTN1 is a const defined in report.h
          #ifdef HAPTIC_ENABLE
            DRV_pulse(sharp_tick1);
          #endif // HAPTIC
         } else {
          currentReport.buttons &= ~MOUSE_BTN1;
        }
        pointing_device_set_report(currentReport);
      #endif // POINTING
        return false;
        break;

      case T_TSNP:
        if (record->event.pressed) {
          #ifdef HAPTIC_ENABLE
            DRV_pulse(strong_click);
          #endif // HAPTIC
          SEND_STRING (SS_LSFT("f"));
        } else {
          //SEND_STRING ("j");
          }
          break;

      case T_SSNP:
        if (record->event.pressed) {
          SEND_STRING ("f");
        } else {
          SEND_STRING ("f");
          }
          break;

      case T_UNDO: { 
          return replace_on_hold_int("u", SS_LCTL("s"), 1000, record->event.pressed); 
        }

      case T_REDO: { 
          return replace_on_hold_int(SS_LSFT("u"), SS_LSFT("s"), 1000, record->event.pressed); 
        }

      case T_SOLO: { 
          return replace_on_hold_int("=", SS_LSFT("t"), 500, record->event.pressed); 
        }

      case T_IMARK: { 
          return replace_on_hold_int("m", SS_LSFT("m"), 1000, record->event.pressed); 
        }


      case T_NKEY: { 
          return replace_on_hold_int("k", SS_LSFT("k"), 1000, record->event.pressed); 
        }

      case T_DKEY: { 
          return replace_on_hold_int("g", SS_LSFT("g"), 1000, record->event.pressed); 
        }

      case T_BMARK: { 
          return replace_on_hold_int(SS_LCTL("b"), SS_LSFT("b"), 1000, record->event.pressed); 
        }

      case T_SELECT:
        if (record->event.pressed) {
          if( !t_selection ) {
            //SEND_STRING(SS_TAP(X_F19)); //hammerspoon indicator
            SEND_STRING ("h");
            #ifdef HAPTIC_ENABLE
              DRV_pulse(transition_rampup_short_smooth1_50);
            #endif // HAPTIC
            t_selection = true;
          }
          else {
            t_deselect_brush();
          }
        }
        break;

      case T_MOVE:
        if (record->event.pressed) {
          if( !t_moved ) {
            //SEND_STRING(SS_TAP(X_F20)); //hammerspoon indicator
            SEND_STRING (SS_LCTL("p"));
            t_moved = true;
          }
          else {
            t_deselect_brush();
          }
        }
        break;

      case T_TRSFM:
        if (record->event.pressed) {
          if( !t_transform ) {
            SEND_STRING (SS_LCTL("t"));
            t_transform = true;
          }
          else {
            SEND_STRING (SS_TAP(X_ENTER));
            t_deselect_brush();
          }
        }
        break;

      case T_WARP:
        if (record->event.pressed) {
            SEND_STRING (SS_LCTL("w"));
            t_transform = true;
          }
        break;

      case T_DJV:
        if (record->event.pressed) {
          if( !t_djvplayer ) {
            SEND_STRING (SS_LSFT(SS_LALT(SS_LGUI("d"))));
            t_djvplayer = true;
          }
          else {
            SEND_STRING (SS_LSFT(SS_LALT(SS_LGUI("t"))));
            t_djvplayer = false;
          }
        }
        break;

      case T_TELE:
          if (record->event.pressed) {
            SEND_STRING (SS_LSFT(SS_LALT(SS_LGUI("e"))));
            layer_off(_TVP);
            #ifdef HAPTIC_ENABLE
              DRV_pulse(pulsing_strong);
            #endif // HAPTIC
          }
        break;
      }
  return true;
}



/* ▐███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌
.
.
.                                                         ▆▆▆▆▆▆▆▆▆▆▆           ▆▆▆▆▆▆▆▆▆▆▆
.                                                            ▂▄▄▄▂                 ▂▄▄▄▂     
.                                                         ▗▟▀▘▁▄▁▝▀▙▖           ▗▟▀▘▁▄▁▝▀▙▖ 
.                                                        ▗▀ ▄█████▄ ▀▖         ▗▀ ▄█████▄ ▀▖ 
.                                                        █ █████████ █    █    █ █████████ █
.                                                        ▝▄ ▀█████▀ ▄▘    █    ▝▄ ▀█████▀ ▄▘
.                                                         ▝▜▄▖▔▀▔▗▄▛▘     █     ▝▜▄▖▔▀▔▗▄▛▘
.                                                            ▔▀▀▀▔        █        ▔▀▀▀▔
.                                                                         █         ▗▙ 
.                                                                         █        ▗██▙
.                                                                         █         ▀▀▘
.                                                                               
.                                                                      ▄▆███▆▄
.                                                                    ▗█▛▔   ▔▜█▖
.                                                                    ▀▀       ▀▀
.
.
.  ▐███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌
*/