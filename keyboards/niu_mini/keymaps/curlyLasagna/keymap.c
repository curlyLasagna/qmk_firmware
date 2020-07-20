#include QMK_KEYBOARD_H

enum layers {
	ROOT,
	LOWER,
	RAISE,
	GAME,
	WEAPONS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ROOT] = LAYOUT_planck_mit (
			KC_TAB,  		KC_Q,    KC_W, 	  KC_E,    KC_R,  	    KC_T,    KC_Y,     KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC, 
			LCTL_T(KC_ESC),	KC_A,    KC_S, 	  KC_D,    KC_F,  	    KC_G,    KC_H,     KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
			OSM(MOD_LSFT), 	KC_Z,    KC_X, 	  KC_C,    KC_V,  	    KC_B,    KC_N,     KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, 
			KC_LCTL, 	    KC_LEAD, KC_LGUI, KC_LALT, MO(LOWER), 	LGUI_T(KC_SPC),    MO(RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
	),

	[LOWER] = LAYOUT_planck_mit (
			KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    				KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, 
			KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, 				KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, 
			KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, 				KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 			KC_TRNS, 			 KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
	),

	[RAISE] = LAYOUT_planck_mit (
			KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   				KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, 
			KC_TRNS, DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, DM_RSTP, 				KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS, KC_TRNS, 
			KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT, KC_PSCR, KC_BRK,  				KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL, KC_CAPS, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  		    KC_TRNS, 			 KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, TG(GAME)
	),

	[GAME] = LAYOUT_planck_mit (
			KC_TAB,  		KC_Q,    KC_W, 	  KC_E,    KC_R,  	    KC_T,    KC_Y,     KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC, 
			KC_ESC, 		KC_A,    KC_S, 	  KC_D,    KC_F,  	    KC_G,    KC_H,     KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
			KC_LSFT, 		KC_Z,    KC_X, 	  KC_C,    KC_V,  	    KC_B,    KC_N,     KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, 
			KC_LCTL, 	    KC_LEAD, KC_LGUI, KC_LALT, MO(WEAPONS), 	KC_SPC,    		   MO(RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
	),

	[WEAPONS] = LAYOUT_planck_mit (
			KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    				KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 				KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 				KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 			KC_TRNS, 			 TG(GAME), KC_HOME, KC_PGDN, KC_PGUP, KC_END
	)
};

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_SPC):
            return TAPPING_TERM + 100;
        case LCTL_T(KC_ESC):
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;

	}
}
#endif

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      SEND_STRING("QMK is awesome.");
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }
    SEQ_TWO_KEYS(KC_C, KC_D) {
      SEND_STRING("cd ~/qmk_firmware/keyboards/niu_mini/keymaps/curlyLasagna");
    }
    SEQ_THREE_KEYS(KC_R, KC_S, KC_T) {
      SEND_STRING("cd ~/qmk_firmware; make niu_mini:curlyLasagna:dfu");
    }
  }
}
