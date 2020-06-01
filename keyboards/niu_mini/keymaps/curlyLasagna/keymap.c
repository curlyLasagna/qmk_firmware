#include QMK_KEYBOARD_H

enum layers {
	ROOT,
	LOWER,
	RAISE,
	ETC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ROOT] = LAYOUT_planck_mit (
			KC_ESC,  		KC_Q,  KC_W, 	 KC_E,    KC_R,  KC_T,   KC_Y,  KC_U,     KC_I,     KC_O,    KC_P,    KC_BSPC, 
			LCTL_T(KC_TAB), KC_A,  KC_S, 	 KC_D,    KC_F,  KC_G,   KC_H,  KC_J,     KC_K,     KC_L,    KC_SCLN, LALT_T(KC_ENT), 
			KC_LSFT, 		KC_Z,  KC_X, 	 KC_C,    KC_V,  KC_B,   KC_N,  KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, LT(ETC, KC_GRV), 
			KC_LCTL, 		KC_TAB, KC_LGUI,  KC_LALT, MO(LOWER), LGUI_T(KC_SPC), 	  LT(RAISE, KC_ENT), KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT
	),

	[LOWER] = LAYOUT_planck_mit (
			KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, 
			KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,  KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, KC_TRNS, KC_TRNS, 
			KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_BSPC, KC_TRNS, KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
	),

	[RAISE] = LAYOUT_planck_mit (
			KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS, KC_TRNS, 
			KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT, KC_PSCR, KC_BRK,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL, KC_TRNS, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	// Mouse emulation
	[ETC] = LAYOUT_planck_mit (
			KC_TRNS, KC_BTN4, KC_MS_U, KC_BTN5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
			KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
			KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	)
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com\n");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}
