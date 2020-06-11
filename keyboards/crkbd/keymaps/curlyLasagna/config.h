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


#define OLED_FONT_H "keyboards/crkbd/keymaps/curlyLasagna/glcdfont_laser.c"
#undef USE_IC2
#define USE_SERIAL_PD2

#ifdef OLED_DRIVER_ENABLE
#	 undef SSD1306OLED
#    define OLED_TIMEOUT 100000
#endif

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 2500

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250

#define MASTER_LEFT

#ifdef RGBLIGHT_ENABLE
	#undef RGBLED_NUM
	#define RGBLED_NUM 27
	#define RGBLIGHT_LIMIT_VAL 120
	#define RGBLIGHT_HUE_STEP 10
	#define RGBLIGHT_SAT_STEP 17
	#define RGBLIGHT_VAL_STEP 17
	#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	#define RGBLIGHT_EFFECT_RAINBOW_GRADIENT
	#define RGBLIGHT_EFFECT_RAINBOW_ALTERNATING
	#define RGBLIGHT_SLEEP  
#endif
