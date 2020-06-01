/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

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

#ifndef CONFIG_USER_H
#define CONFIG_USER_H
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xCB10
#define PRODUCT_ID      0x1156
#define DEVICE_VER      0x0300
#define MANUFACTURER    Keebio
#define PRODUCT         The Nyquist Keyboard
#define DESCRIPTION     Split 60 percent ortholinear keyboard

#define SOFT_SERIAL_PIN D0
#define MASTER_LEFT

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { F0, F5, D7, F6, F7 }
#define MATRIX_COL_PINS { F1, F4, B7, D2, D3, D4 }
#define SPLIT_HAND_PIN D5

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* ws2812 RGB LED */
#undef RGBLED_NUM
#define RGB_DI_PIN B4
#define RGBLIGHT_LAYERS
#define RGB_LAYER_BLINK
#define RGBLED_NUM 12
#define RGBLED_SPLIT { 6, 6 }

/* enabled animations*/
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_GRADIENT

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING 

#endif
