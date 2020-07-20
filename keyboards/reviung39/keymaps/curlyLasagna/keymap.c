#include QMK_KEYBOARD_H

enum layers {
	ROOT,
	LOWER,
	RAISE,
	GAME,
	WEAPONS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ROOT] = LAYOUT_reviung39(
	KC_TAB,					KC_Q, 	KC_W,	 				KC_E, 				KC_R, KC_T, /*|*/	 KC_Y, 	KC_U, 	KC_I, 	 KC_O, 	 KC_P, 	  KC_BSPC, 
	/*---------------------------------------------------------------------------------------------------------------*/
	LCTL_T(KC_ESC),	KC_A, 	KC_S, 	 			KC_D, 				KC_F,	KC_G, /*|*/	 KC_H, 	KC_J, 	KC_K, 	 KC_L, 	 KC_SCLN, KC_QUOT, 
	/*---------------------------------------------------------------------------------------------------------------*/
	OSM(MOD_LSFT), 	KC_Z, 	LGUI_T(KC_X), LALT_T(KC_C), KC_V, KC_B, /*|*/  KC_N, 	KC_M, 	KC_COMM, KC_DOT, KC_SLSH, KC_LEAD, 
	/*---------------------------------------------------------------------------------------------------------------*/
																									MO(LOWER), LGUI_T(KC_SPC), LT(RAISE, KC_ENT)
	),
											
	[LOWER] = LAYOUT_reviung39(
	KC_GRV,  KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,    /*|*/ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, RGB_MOD, RGB_VAI, /*|*/ KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, KC_TRNS, KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MPRV, KC_MPLY, KC_MFFD, RGB_HUI, RGB_SAI, /*|*/ KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
	/*--------------------------------------------------------------------------------------------------------------*/
																								KC_TRNS, KC_TRNS, TG(GAME)
	),

	[RAISE] = LAYOUT_reviung39(
	KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,  /*|*/  KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, DM_REC1, DM_REC2, DM_PLY1,  DM_PLY2, DM_RSTP,/*|*/  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_INS,  KC_TRNS,
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT,  KC_PSCR, KC_BRK, /*|*/  KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_TRNS,  KC_CAPS, 
	/*---------------------------------------------------------------------------------------------------------------*/
																							KC_TRNS, KC_TRNS, KC_TRNS
	),

	[GAME] = LAYOUT_reviung39(
	KC_TAB,		KC_Q, 	KC_W,	 	KC_E, 	KC_R, KC_T, /*|*/	 KC_Y, 	KC_U, 	KC_I, 	 KC_O, 	 KC_P, 	  KC_BSPC, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_LCTL,	KC_A, 	KC_S, 	KC_D, 	KC_F,	KC_G, /*|*/	 KC_H, 	KC_J, 	KC_K, 	 KC_L, 	 KC_SCLN, KC_QUOT, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_LSFT, 	KC_Z, 	KC_X,  	KC_C, 	KC_V, KC_B, /*|*/  KC_N, 	KC_M, 	KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
																	MO(WEAPONS), KC_SPC, KC_ENT
	),

	[WEAPONS] = LAYOUT_reviung39(
	KC_ESC,  KC_1, 	  KC_TRNS,    KC_2,    KC_3,    KC_TRNS, /*|*/ KC_6,  KC_7,   KC_8,  KC_9,   KC_0,   KC_DEL,
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_4, 	 KC_TRNS, KC_TRNS, 		KC_TRNS, KC_5, 		KC_TRNS, /*|*/ KC_F1, KC_F2,  KC_F3, KC_F4,  KC_F5,  KC_F6, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_TRNS, KC_TRNS, 		KC_LALT, KC_TRNS, KC_TRNS, /*|*/ KC_F7, KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, 
	/*---------------------------------------------------------------------------------------------------------------*/
																							KC_TRNS, KC_TRNS, TG(GAME)
	)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case LGUI_T(KC_SPC):
            return TAPPING_TERM + 100;
		case LCTL_T(KC_ESC):
		   	return TAPPING_TERM	- 50;
        default:
            return TAPPING_TERM;
	}
}

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
	SEQ_TWO_KEYS(KC_C, KC_D) {
	  SEND_STRING("cd $HOME/qmk_firmware/keyboards/reviung39/keymaps/curlyLasagna");
	}
    SEQ_THREE_KEYS(KC_R, KC_S, KC_T) {
      SEND_STRING("cd $HOME/qmk_firmware; make reviung39:curlyLasagna:dfu");
    }
  }
}
#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM capslock_enabled[] = RGBLIGHT_LAYER_SEGMENTS (
	{10, 1, HSV_RED}
);

const rgblight_segment_t PROGMEM lower_enabled[] = RGBLIGHT_LAYER_SEGMENTS (
	{10, 1, HSV_PURPLE}	
);

const rgblight_segment_t PROGMEM raise_enabled[] = RGBLIGHT_LAYER_SEGMENTS (
	{10, 1, HSV_TEAL}	
);

const rgblight_segment_t PROGMEM game_enabled[] = RGBLIGHT_LAYER_SEGMENTS (
	{10, 1, HSV_YELLOW}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	capslock_enabled,
	lower_enabled,
	raise_enabled,
	game_enabled
);

void keyboard_post_init_user(void) {
	rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(LOWER, layer_state_cmp(state, LOWER));
	rgblight_set_layer_state(RAISE, layer_state_cmp(state, RAISE));
	rgblight_set_layer_state(GAME, layer_state_cmp(state, GAME));
	return state;
}

bool led_update_user(led_t led_state) {
	rgblight_set_layer_state(0, led_state.caps_lock);
	return true;
}
#endif

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//	switch(keycode) {
//		case LOWER:
//			if(record->event.pressed) {
//				layer_on(LOWER);	
//				update_tri_layer(LOWER, RAISE, ADJUST);
//			} else {
//				layer_off(LOWER);
//				update_tri_layer(LOWER, RAISE, ADJUST)
//			}
//			return false;
//			break;
//		case RAISE:
//			if(record->event.pressed) {
//				layer_on(RAISE);
//				update_tri_layer(LOWER, RAISE, ADJUST);
//			} else {
//				layer_off(LOWER);
//				update_tri_layer(LOWER, RAISE, ADJUST)
//			}
//			return false;
//			break;
//	}
//	return true;
//}

//dynamic_macro_record_start_user(void) {
//	rgblight_mode_noeeprom()
//}
//
//dynamic_macro_record_end_user(1) {
//
//}
//
//dynamic_macro_record_end_user(-1) {
//
//}

//void leader_start(void) {
//	rgblight_mode_noeeprom(RGB_MODE_SNAKE+5);	
//}
//
//
//void leader_end(void) {
//	if(did_leader_succeed) 
//		rgblight_mode_noeeprom(20);	
//	else 
//		rgblight_setrgb(255, 0, 0);
//}
