/* Copyright 2019 gtips
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

#pragma once

// place overrides here
#define NO_ACTION_FUNCTION
#define NO_ACTION_MACRO
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
	#define NO_PRINT
#endif // !NO_PRINT

#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

/* One shot settings */
#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 500
/* Leader key */
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300

#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
	#define RGBLIGHT_LAYERS
	#define RGBLED_NUM 11
	#define RGBLIGHT_HUE_STEP 16
	#define RGBLIGHT_SAT_STEP 16
	#define RGBLIGHT_VAL_STEP 16
	#define RGBLIGHT_LIMIT_VAL 255 
	#define RGBLIGHT_SLEEP  
	/*== or choose animations ==*/
	#define RGBLIGHT_EFFECT_RAINBOW_MOOD
	#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	#define RGBLIGHT_EFFECT_STATIC_GRADIENT
	#define RGBLIGHT_EFFECT_ALTERNATING
	#define RGBLIGHT_EFFECT_SNAKE
	#define RGBLIGHT_EFFECT_KNIGHT
	#define RGBLIGHT_EFFECT_TWINKLE
	//#define RGBLIGHT_EFFECT_CHRISTMAS
	//#define RGBLIGHT_EFFECT_BREATHING

	/*== customize breathing effect ==*/
	/*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
	//   #define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
	/*==== use exp() and sin() ====*/
	//   #define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
	//   #define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
#endif
