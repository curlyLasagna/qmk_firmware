#include QMK_KEYBOARD_H

#define LOW MO(LOWER)
#define RISE MO(RAISE)
#define GCTL RCTL_T(KC_ENT)
#define SPCGUI LT(LOWER, KC_SPC)


enum layers {
	ROOT,
	LOWER,
	RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ROOT] = LAYOUT_ortho_4x12 (
		KC_TAB,  KC_Q,    KC_W, 	KC_E,   KC_R,   KC_T, 	 KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, 
		KC_ESC,  KC_A,    KC_S, 	KC_D,   KC_F,   KC_G, 	 KC_H, KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
		KC_LSFT, KC_Z,    KC_X, 	KC_C,   KC_V,   KC_B, 	 KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, 
		KC_LCTL, KC_LGUI, KC_LALT,  KC_INS,	SPCGUI, SPCGUI,  GCTL, RISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
	),
    
	[LOWER] = LAYOUT_ortho_4x12 (
		KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_GRV, 
		_______, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,   KC_LBRC, KC_RBRC,  KC_BSLS, KC_TRNS, KC_TRNS, KC_DEL, 
		KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,   KC_MINS, KC_EQL,   KC_TRNS, KC_PSCR, KC_BRK,  KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_HOME, KC_PGUP, KC_PGDN, KC_END
	),

	[RAISE] = LAYOUT_ortho_4x12 (
		_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
		RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   _______, _______, _______, KC_LEAD, _______, 
		_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,    KC_F12,  _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______
	)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case RCTL_T(KC_ENT):
			return TAPPING_TERM - 100;
            break;
        case LT(LOWER, KC_SPC):
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
