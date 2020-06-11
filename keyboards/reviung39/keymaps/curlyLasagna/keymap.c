#include QMK_KEYBOARD_H

enum layers {
	ROOT,
	LOWER,
	RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ROOT] = LAYOUT_reviung39(
	KC_TAB,  		KC_Q, 	KC_W,	 KC_E, 	KC_R, 	KC_T, /*|*/	 KC_Y, 	KC_U, 	KC_I, 	 KC_O, 	 KC_P, 	  KC_DEL, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_LCTL, 		KC_A, 	KC_S, 	 KC_D, 	KC_F,	KC_G, /*|*/	 KC_H, 	KC_J, 	KC_K, 	 KC_L, 	 KC_SCLN, KC_LALT, 
	/*---------------------------------------------------------------------------------------------------------------*/
	OSM(MOD_LSFT), 	KC_Z, 	KC_X,  	 KC_C, 	KC_V, 	KC_B, /*|*/  KC_N, 	KC_M, 	KC_COMM, KC_DOT, KC_SLSH, KC_LEAD, 
	/*---------------------------------------------------------------------------------------------------------------*/
									LT(LOWER, KC_ESC), LGUI_T(KC_SPC), LT(RAISE, KC_ENT)
	),
											
	[LOWER] = LAYOUT_reviung39(
	KC_GRV,  KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,    /*|*/ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    RGB_TOG, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, RGB_MOD,  RGB_VAI, /*|*/ KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, KC_TRNS, KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MPRV, KC_MPLY, KC_MFFD, RGB_HUI, RGB_SAI, /*|*/ KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
	/*---------------------------------------------------------------------------------------------------------------*/
												KC_TRNS, KC_TRNS, KC_BSPC
	),

	[RAISE] = LAYOUT_reviung39(
	KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,  /*|*/  KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, DM_REC1, DM_REC2, DM_PLY1,  DM_PLY2, DM_RSTP,/*|*/  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_INS,  KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT,  KC_PSCR, KC_BRK, /*|*/  KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_PSCREEN,  KC_CAPS, 
	/*---------------------------------------------------------------------------------------------------------------*/
												KC_TAB, KC_TRNS, KC_TRNS
	)
};

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
    //SEQ_THREE_KEYS(KC_Y, KC_I, KC_W) {
    //  SEND_STRING(SS_LCTL("a") SS_LSFT SS_LCTL("c"));
    //}
    SEQ_THREE_KEYS(KC_R, KC_S, KC_T) {
      SEND_STRING("cd /home/luis/qmk_firmware; make reviung39:curlyLasagna:dfu"SS_TAP(X_ENT));
    }
  }
}

dynamic_macro_record_start_user(void) {
	rgblight_mode_noeeprom()
}

dynamic_macro_record_end_user(1) {

}

dynamic_macro_record_end_user(-1) {

}

//void leader_start(void) {
//	rgblight_mode_noeeprom(14);	
//}
//
//
//void leader_end(void) {
//	if(did_leader_succeed) 
//		rgblight_mode_noeeprom(20);	
//	else 
//		rgblight_setrgb(255, 0, 0);
//}
