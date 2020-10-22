#include QMK_KEYBOARD_H

#define	VTT LCA(KC_LGUI) 
#define LOW MO(LOWER)
#define GUI LGUI_T(KC_SPC)
#define CTL RCTL_T(KC_ENT)
#define RSE LT(RAISE, KC_CAPS)
#define EMAG TG(GAME)
#define WEP MO(WEAPONS)
#define GDOT RGUI_T(KC_DOT)
#define RCOM RALT_T(KC_COMM)

enum layers {
	ROOT,
	LOWER,
	RAISE,
	GAME,
	WEAPONS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ROOT] = LAYOUT_ortho_4x12 (
		KC_TAB,  	KC_Q,    KC_W, 	  KC_E,     KC_R, KC_T, 				KC_Y, KC_U, KC_I,    KC_O,    KC_P,    	KC_BSPC, 
		KC_ESC, 	KC_A,    KC_S, 	  KC_D,     KC_F, KC_G, 				KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, 	KC_QUOT, 
		KC_LSFT, 	KC_Z,    KC_X, 	  KC_C,     KC_V, KC_B, 				KC_N, KC_M, RCOM, 	 GDOT,  	KC_SLSH, 	KC_RSFT, 
		KC_LCTL, 	KC_TILD, KC_LGUI, KC_LALT, 	LOW, 	GUI, 					CTL, 	RSE, 	KC_LEFT, KC_DOWN, KC_UP,  	KC_RGHT
	),

	[LOWER] = LAYOUT_ortho_4x12 (
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    		KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, 
		_______, KC_MUTE, KC_VOLD, KC_VOLU, RGB_MOD, RGB_VAI, 		KC_LBRC,  KC_RBRC, KC_BSLS, _______, KC_LEAD, KC_INS, 
		_______, KC_MPRV, KC_MPLY, KC_MNXT, RGB_HUI, RGB_SAI, 		KC_MINS,  KC_EQL,  KC_PSCR, KC_BRK,  _______, _______, 
		_______, 	 _______, _______, _______, _______, _______,   _______, 	EMAG, 	 KC_HOME, KC_PGDN, KC_PGUP, KC_END
	),

	[RAISE] = LAYOUT_ortho_4x12 (
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   		KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 
		_______, DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, DM_RSTP, 		KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, RESET, 
		_______, _______, _______, _______, _______, _______,  		KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, 
		_______, _______, _______, _______, _______, _______, 		_______, _______, _______, _______, _______, _______
	),

	[GAME] = LAYOUT_ortho_4x12 (
		KC_TAB,  		KC_Q,    KC_W, 	  KC_E,    KC_R,  KC_T,    KC_Y,     KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC, 
		KC_ESC, 		KC_A,    KC_S, 	  KC_D,    KC_F,  KC_G,    KC_H,     KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
		KC_LSFT, 		KC_Z,    KC_X, 	  KC_C,    KC_V,  KC_B,    KC_N,     KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_LEAD, 
		KC_LCTL, 	  RGB_TOG, KC_LGUI, KC_LALT, WEP, 	KC_SPC,  KC_ENT,   MO(RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
	),

	[WEAPONS] = LAYOUT_ortho_4x12 (
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_DEL, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, 
		_______, _______, _______, _______, _______, _______, _______, EMAG, 		KC_HOME, KC_PGDN, KC_PGUP, KC_END
	)
};

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

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_TWO_KEYS(KC_C, KC_D) {
      SEND_STRING("vim ~/qmk_firmware/keyboards/keebio/nyquist/keymaps/curlyLasagna");
    }
    SEQ_THREE_KEYS(KC_R, KC_S, KC_T) {
      SEND_STRING("(cd ~/qmk_firmware && make keebio/nyquist/rev3:curlyLasagna:dfu)");
    }
  }
}
