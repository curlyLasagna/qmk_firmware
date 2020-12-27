#include QMK_KEYBOARD_H

#define	VTT LCA(KC_LGUI) 
#define LOW LT(LOWER, KC_SPC)
#define RSE LT(RAISE, KC_ENT)
#define EMAG TG(GAME)
#define WEP MO(WEAPONS)

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
		KC_LSFT, 	KC_Z,    KC_X, 	  KC_C,     KC_V, KC_B, 				KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, 	KC_RSFT, 
		KC_LCTL, 	KC_CAPS, KC_LGUI, KC_LALT,	LOW,  LOW, 					RSE,  RSE, 	KC_RALT, KC_RGUI, KC_RCTL, 	KC_APP
	),

	[LOWER] = LAYOUT_ortho_4x12 (,
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    		KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, 
		_______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, 		KC_LBRC,  KC_RBRC, KC_BSLS, _______, _______, KC_INS, 
		_______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, 		KC_MINS,  KC_EQL,  KC_PSCR, KC_BRK,  _______, _______, 
		_______, _______, _______, _______, _______, _______,       EMAG,     EMAG,    _______, _______, _______, _______
	),

	[RAISE] = LAYOUT_ortho_4x12 (
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   		_______, _______, _______, _______, _______, _______, 
		KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 		KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LEAD, RESET, 
		_______, _______, _______, _______, _______, _______,  		KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, 
		_______, KC_TRNS, _______, _______, _______, _______, 		_______, _______, _______, _______, _______, _______
	),

	[GAME] = LAYOUT_ortho_4x12 (
		KC_TAB,  		KC_Q,       KC_W, 	  KC_E,    KC_R,   KC_T,    KC_Y,     KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC, 
		KC_ESC, 		KC_A,       KC_S, 	  KC_D,    KC_F,   KC_G,    KC_H,     KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
		KC_LSFT, 		KC_Z,       KC_X, 	  KC_C,    KC_V,   KC_B,    KC_N,     KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, 
		KC_LCTL, 	    MO(RAISE),  KC_LALT,  WEP,     KC_SPC, KC_SPC,  KC_ENT,   KC_ENT,    _______, _______, _______, _______
	),

	[WEAPONS] = LAYOUT_ortho_4x12 (
		KC_1,    KC_2,    _______, KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_DEL, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, 
		_______, _______, _______, _______, _______, _______, EMAG,    EMAG, 	_______, _______, _______,  _______
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
      SEND_STRING("vim ~/qmk_firmware/keyboards/keebio/levinson/keymaps/curlyLasagna");
    }
    SEQ_THREE_KEYS(KC_R, KC_S, KC_T) {
      SEND_STRING("(cd ~/qmk_firmware && make keebio/levinson/rev3:curlyLasagna:dfu)");
    }
  }
}
