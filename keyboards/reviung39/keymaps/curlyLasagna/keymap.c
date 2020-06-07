#include QMK_KEYBOARD_H

enum layers {
	ROOT,
	LOWER,
	RAISE,
	ETC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ROOT] = LAYOUT_reviung39(
	KC_TAB,  		KC_Q, 	KC_W,	 KC_E, 	KC_R, 	KC_T, /*|*/	 KC_Y, 	KC_U, 	KC_I, 	 KC_O, 	 KC_P, 	  KC_DEL, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_LCTL, 		KC_A, 	KC_S, 	 KC_D, 	KC_F,	KC_G, /*|*/	 KC_H, 	KC_J, 	KC_K, 	 KC_L, 	 KC_SCLN, KC_LALT, 
	/*---------------------------------------------------------------------------------------------------------------*/
	OSM(MOD_LSFT), 	KC_Z, 	KC_X,  	 KC_C, 	KC_V, 	KC_B, /*|*/  KC_N, 	KC_M, 	KC_COMM, KC_DOT, KC_SLSH, LT(ETC, KC_LEAD), 
	/*---------------------------------------------------------------------------------------------------------------*/
									LT(LOWER, KC_ESC), LGUI_T(KC_SPC), LT(RAISE, KC_ENT)
	),
											
	[LOWER] = LAYOUT_reviung39(
	KC_GRV,  KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,    /*|*/ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS,  KC_TRNS, /*|*/ KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, KC_TRNS, KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MPRV, KC_MPLY, KC_MFFD, KC_TRNS, KC_TRNS, /*|*/ KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
												KC_TRNS, KC_TRNS, KC_BSPC
	),

	[RAISE] = LAYOUT_reviung39(
	KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,  /*|*/  KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,/*|*/  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_INS,  KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT,  KC_PSCR, KC_BRK, /*|*/  KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_PSCREEN,  KC_CAPS, 
	/*---------------------------------------------------------------------------------------------------------------*/
												KC_TAB, KC_TRNS, KC_TRNS
	),

	[ETC] = LAYOUT_reviung39(
	KC_TRNS, RGB_TOG, KC_MS_U, RGB_MOD, RGB_SAI, RGB_HUI, /*|*/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, RGB_VAI, KC_TRNS, /*|*/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_WH_D, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, /*|*/ KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
												KC_BTN1, KC_BTN2, KC_BTN3)
};

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
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
  }
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

/*const rgblight_segment_t PROGMEM lower[] = \
//RGBLIGHT_LAYER_SEGMENTS( \
//    {10, 10, HSV_CHARTREUSE} \
//);
//
//const rgblight_segment_t PROGMEM raise[] = \
//RGBLIGHT_LAYER_SEGMENTS( \
//    {10, 10, HSV_RED} \
//);
//
//const rgblight_segment_t PROGMEM etc[] = \
//RGBLIGHT_LAYER_SEGMENTS( \
//    {10, 10, HSV_MAGENTA} \
//);
//
//const rgblight_segment_t* const PROGMEM rgb_layers[] = \
//	RGBLIGHT_LAYERS_LIST( \
//			lower, \
//			raise, \
//			etc);
//
//layer_state_t layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(0, layer_state_cmp(state, LOWER));
//    rgblight_set_layer_state(1, layer_state_cmp(state, RAISE));
//    rgblight_set_layer_state(2, layer_state_cmp(state, ETC));
//    return state;
//}
*/
