/*
make keycapsss/plaid_pad:schwarz

┏━━━━━━━━━━━━━━━━━━━━███━━━━━━━━━━┓
┃  _  ░░▓▓░░░░░░░░░░ ███  ●  ●    ┃
┃  ─  ▖   ▖   ▖   ▖        ──  ── ┃
┃  ▔  ▘▌▖ ▘▌▖ ▘▌▖ ▘▌▖ ● ▄▄ ▔▔▁▁▔▔ ┃
┃       ▘▌  ▘▌  ▘▌  ▘▌  ▀▀   ──   ┃
┃  ▁    ▄▄   ▄▄▄▄▄▄ ▄▄▄▄▄▄   ▄▄   ┃
┃ ▄▄▄ ▄████▄ ██████ ██████ ▄████▄ ┃
┃  ─   ▀██▀  ██████ ██████  ▀██▀  ┃
┃ ▄▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄▄ ┃
┃ ███ ██████ ██████ ██████ ██████ ┃
┃ ███ ██████ ██████ ██████ ██████ ┃
┃ ███ ▄▄▄▄▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄▄ ┃
┃ ███ ██████ ██████ ██████ ██████ ┃
┃ ███ ██████ ██████ ██████ ██████ ┃
┃ ███ ▄▄▄▄▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄▄ ┃
┃  ●  ██████ ██████ ██████ ██████ ┃
┃  ●  ██████ ██████ ██████ ██████ ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

.    P  L  A  I  D  -  P  A  D    .

*/

#include QMK_KEYBOARD_H
extern uint8_t is_master;

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ D E F I N I T I O N S                                            ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐██████████████████████████████████████████████████████████████████▌


// ╭──────────────────────────────╮
// │ d e f   l a y e r s          │
// ╰──────────────────────────────╯ 

#define _BASE 0
#define _AE 1
#define _AE2 2
#define _BLENDER 3


// ╭─────────────────────────────╮
// │ d e f  k e y c o d e s      │
// ╰─────────────────────────────╯ 

enum custom_keycodes {
  BASE = SAFE_RANGE,
  AE,
  AE2,
  BLEND,
  MAKE
};


// ╭──────────────────────────────╮
// │ d e f  m a c r o n a m e s   │
// ╰──────────────────────────────╯ 

#define BASE TO(_BASE)
#define AE TO(_AE)
#define AE2 MO(_AE2)
#define BLEND TO(_BLENDER)


// ╭──────────────────────────────╮
// │ d e f  c o m b o s           │
// ╰──────────────────────────────╯ 

enum combo_events {
  ZEHN_AE,
  PLSMNS_MAKE
};

const uint16_t PROGMEM zehn_combo[] = {KC_P1, KC_P0, COMBO_END};
const uint16_t PROGMEM plsmns_combo[] = {KC_PPLS, KC_PMNS, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ZEHN_AE] = COMBO_ACTION(zehn_combo),
  [PLSMNS_MAKE] = COMBO_ACTION(plsmns_combo)
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case ZEHN_AE:
      if (pressed) {
        layer_on(_AE);
      }
      break;

    case PLSMNS_MAKE:
      if (pressed) {
          SEND_STRING ("make keycapsss/plaid_pad:schwarz");
          register_code(KC_ENTER);
          unregister_code(KC_ENTER);
      }
      break;
  }
}

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ K E Y M A P S                                                    ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐██████████████████████████████████████████████████████████████████▌


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃ b a s e                       ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
  ┏━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┓
  ┃   *   ┃   +   ┃   -   ┃   /   ┃
  ┣━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━━━━┫
  ┃   7   ┃   8   ┃   9   ┃ ENTER ┃
  ┣━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━━━━┫
  ┃   4   ┃   5   ┃   6   ┃   .   ┃
  ┣━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━━━━┫
  ┃   1   ┃   2   ┃   3   ┃   0   ┃
  ┗━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┛
 */

[_BASE] = LAYOUT_ortho_4x4( 
   KC_PAST,KC_PPLS,KC_PMNS,KC_PSLS,
	 KC_P7,  KC_P8,  KC_P9,  KC_PENT,
	 KC_P4,  KC_P5,  KC_P6,  KC_PDOT,
	 KC_P1,  KC_P2,  KC_P3,  KC_P0
),
/*
  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄


  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃ a f t e r   e f f e c t s     ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
  ┏━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┓
  ┃ SHIFT ┃   [   ┃   ]   ┃       ┃
  ┣━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━━━━┫
  ┃   P   ┃   S   ┃   R   ┃   T   ┃
  ┣━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━━━━┫
  ┃  EASE ┃ EASEC ┃ SOLID ┃  SNAP ┃
  ┣━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━━━━┫
  ┃  MOD  ┃ CACHE ┃  SAVE ┃  RAM  ┃
  ┗━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┛
 */

[_AE] = LAYOUT_ortho_4x4( 
   KC_LSFT,KC_P8,  KC_P9,  KC_RSFT,
   KC_P,   KC_S,   KC_R,   KC_T,
   KC_F7,  KC_P2,  KC_P3,  KC_F5,
   AE2,    KC_PDOT,KC_PEQL,KC_PPLS
  ),

/*
  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃ a f t e r   e f f e c t s  2  ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
  ┏━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┓
  ┃   A   ┃   F   ┃   T   ┃   E   ┃
  ┣━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━━━━┫
  ┃   R   ┃   E   ┃   F   ┃   *   ┃
  ┣━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━━━━┫
  ┃   1   ┃   2   ┃   3   ┃   -   ┃
  ┣━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━━━━┫
  ┃   0   ┃   .   ┃   =   ┃ BASE  ┃
  ┗━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┛
 */

[_AE2] = LAYOUT_ortho_4x4( 
   KC_P7,  KC_P8,  KC_P9,  KC_RSFT,
   KC_P4,  KC_P5,  KC_P6,  KC_PAST,
   KC_P1,  KC_P2,  KC_P3,  KC_PMNS,
   RESET,  KC_PDOT,KC_PEQL,BASE
  ),
/*
  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄


  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃ b l e n d e r                 ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
  ┏━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┓
  ┃   B   ┃   L   ┃   E   ┃   N   ┃
  ┣━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━━━━┫
  ┃   D   ┃   E   ┃   6   ┃   *   ┃
  ┣━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━━━━┫
  ┃   1   ┃   2   ┃   3   ┃   -   ┃
  ┣━━━━━━━╋━━━━━━━╋━━━━━━━╋━━━━━━━┫
  ┃   0   ┃   .   ┃   =   ┃   +   ┃
  ┗━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┛
 */

[_BLENDER] = LAYOUT_ortho_4x4( 
   KC_P7,  KC_P8,  KC_P9,  KC_RSFT,
   KC_P4,  KC_P5,  KC_P6,  KC_PAST,
   KC_P1,  KC_P2,  KC_P3,  KC_PMNS,
   RESET,  KC_PDOT,KC_PEQL,KC_PPLS
  )

//▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄

};

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ E N C O D E R  K E Y M A P S                                     ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐██████████████████████████████████████████████████████████████████▌

char enc_map[4][4][24] = {
/*  
. ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
. ┃ b a s e                                      ┃
. ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
.
.     VOL -       VOL +    SCROLL-     SCROLL+
.      🡄          🡆         🡄          🡆
.          ▁▄▄▄▄▁                ▁▄▄▄▄▁                
.         ▟██████▙              ▟██████▙                     
.        ▐████████▌            ▐████████▌                    
.         ▜██████▛              ▜██████▛                      
.          ▔▀▀▀▀▔                ▔▀▀▀▀▔           
.               
*/
  [_BASE]  =  {
    SS_TAP(X__VOLDOWN), SS_TAP(X__VOLUP), SS_TAP(X_WH_D), SS_TAP(X_WH_U)
  },

/*  
. ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
. ┃ a f t e r  e f f e c t s                     ┃
. ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
.
.     last        next     tl -          tl +
.      🡄          🡆         🡄          🡆
.          ▁▄▄▄▄▁                ▁▄▄▄▄▁                
.         ▟██████▙              ▟██████▙                     
.        ▐████████▌            ▐████████▌                    
.         ▜██████▛              ▜██████▛                      
.          ▔▀▀▀▀▔                ▔▀▀▀▀▔           
.               
*/
  [_AE]  =  {
    SS_TAP(X_PGUP), SS_TAP(X_PGDN), SS_TAP(X_MINUS), SS_TAP(X_EQUAL)
  },
};


int layerstate = 0;

layer_state_t layer_state_set_user(layer_state_t state) {
  layerstate = get_highest_layer(state);
    switch (layerstate) {
    case _BASE:
      writePinLow(LED_GREEN);
      break;
    case _AE:
      writePinHigh(LED_GREEN);
      break;
    case _AE2:
      writePinHigh(LED_GREEN);
      break;
    case _BLENDER:
      break;
    }
  return state;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {         // First encoder - top left
    if (clockwise) {
      send_string(enc_map[layerstate][1]);
    } else {
      send_string(enc_map[layerstate][0]);
    }
  } else if (index == 1) {  // Second encoder - top right
    if (clockwise) {
      tap_code(KC_WH_D);
    } else {
      tap_code(KC_WH_U);
    }
  }
}


// Set led state during powerup
void keyboard_post_init_user(void) {
    writePinHigh(LED_RED);
}


// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ M A C R O S                                                                                                                               ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
// ▐███████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████▌


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
          case MAKE:
          if (record->event.pressed) {
            SEND_STRING ("make keycapsss/plaid_pad:schwarz");
            register_code(KC_ENTER);
            unregister_code(KC_ENTER);
          } 
          break;
      }
  return true;
}
