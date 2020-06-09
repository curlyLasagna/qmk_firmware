#include QMK_KEYBOARD_H

enum layers {
	ROOT,
	LOWER,
	RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ROOT] = LAYOUT_ortho_4x12(
			KC_TAB,  KC_Q,    KC_W, 	KC_E,    KC_R,      		KC_T,           KC_Y,              KC_U,     			 KC_I,     KC_O,    KC_P,    KC_DEL, 
			KC_LCTL, KC_A,    KC_S, 	KC_D,    KC_F,      		KC_G,           KC_H,              KC_J,     			 KC_K,     KC_L,    KC_SCLN, KC_LALT, 
			KC_LSFT, KC_Z,    KC_X, 	KC_C,    KC_V,      		KC_B,           KC_N,              KC_M,     			 KC_COMM,  KC_DOT,  KC_SLSH, KC_LEAD, 
			KC_LCTL, KC_NO,   KC_LGUI,  KC_LALT, LT(LOWER, KC_ESC), LSFT_T(KC_SPC), LGUI_T(KC_ENT),    LT(RAISE, KC_BSPC), 	 KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT
	),

	[LOWER] = LAYOUT_ortho_4x12(
			KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, 
			KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,  KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, KC_TRNS, KC_TRNS, 
			KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_BSPC, KC_TRNS, KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  RESET
	),

	[RAISE] = LAYOUT_ortho_4x12(
			KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  KC_TRNS, 
			KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT, KC_PSCR, KC_BRK,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  KC_TRNS, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS
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
    SEQ_TWO_KEYS(KC_D, KC_W) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com\n");
    }
  }
}


//const rgblight_segment_t PROGMEM lower[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0, 2, HSV_RED}
//);
//
//const rgblight_segment_t PROGMEM raise[] = RGBLIGHT_LAYER_SEGMENTS(
//    {6, 2, HSV_BLUE}
//);
//
//const rgblight_segment_t PROGMEM etc[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0, 12, HSV_YELLOW}
//);
//
//const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//		lower, 
//		raise, 
//		etc);
//
//void keyboard_post_init_user(void) {
//    // Enable the LED layers
//    rgblight_layers = rgb_layers;
//}
//
//layer_state_t layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(1, layer_state_cmp(state, LOWER));
//    rgblight_set_layer_state(2, layer_state_cmp(state, RAISE));
//    rgblight_set_layer_state(3, layer_state_cmp(state, ETC));
//    return state;
//}

//void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case KC_LEAD:
//            rgblight_blink_layer(leader_start ? 0 : 1, 1000);
//            break;
//		case KC_LEAD:
//			rgblight_blink_layer(leader_fail ? 0 : 1, 1000);
//
//    }
//}
