/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// #define SSD1306OLED

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

#define DYNAMIC_MACRO_NO_NESTING

#define FB_ERM_LRA 1
#define FB_BRAKEFACTOR 3 /* For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 */
#define FB_LOOPGAIN 1 /* For  Low:0, Medium:1, High:2, Very High:3 */

/* Please refer to your datasheet for the optimal setting for your specific motor. */
#define RATED_VOLTAGE 2
#define V_PEAK 2.8
#define V_RMS 2.0 
#define F_LRA 150 /* resonance freq */

#define B7_AUDIO
#define NO_MUSIC_MODE

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)
#endif
