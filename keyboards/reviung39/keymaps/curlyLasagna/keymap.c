#include QMK_KEYBOARD_H

#define KC_HKKB 	LCTL_T(KC_ESC)
#define KC_CTLZ 	LCTL_T(KC_Z)
#define KC_GUIX 	LGUI_T(KC_X)
#define KC_ALTC 	LALT_T(KC_C)

#define KC_LOW 		MO(LOWER)
#define KC_RISE 	LT(RAISE, KC_ENT)
#define KC_WEAP 	MO(WEAPONS)
#define KC_SPCG 	LGUI_T(KC_SPC)
#define KC_GAME 	TG(GAME)

#define KC_R0 		RALT_T(KC_COMM)
#define KC_R1 		RGUI_T(KC_DOT)
#define KC_R2 		RCTL_T(KC_SLSH)

#define KC_REC1 	DM_REC1
#define	KC_REC2 	DM_REC2
#define	KC_PLY1 	DM_PLY1
#define	KC_PLY2		DM_PLY2
#define	KC_STOP 	DM_RSTP

#define KC_MODE 	RGB_MOD
#define KC_BRIGHT RGB_VAI
#define KC_HUE 		RGB_HUI
#define KC_SAT 		RGB_SAI

enum layers {
	ROOT,
	LOWER,
	RAISE,
	GAME,
	WEAPONS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ROOT] = LAYOUT_kc(
	TAB, 	Q, 		W,	 	E, 		R, 		T, 		 /*|*/	Y, 		U,		I, 		O,  	P, 	  BSPC, 
	HKKB,	A, 		S, 	 	D, 		F,		G, 		 /*|*/	H, 		J,		K, 		L,  	SCLN, QUOT, 
	LSFT,	CTLZ, GUIX, ALTC, V, 		B, 		 /*|*/  N, 		M,		R0, 	R1, 	R2, 	RSFT,
																LOW, 		SPCG, RISE
	),
											
	[LOWER] = LAYOUT_kc(
	GRV,  1, 	  2,    3,    4,    5,    	/*|*/ 6,    7,    8,    9,    0,    DEL,
	TRNS, MUTE, VOLD, VOLU, MODE, BRIGHT, /*|*/ LBRC, RBRC, BSLS, PSCR, BRK, 	INS, 
	TRNS, MPRV, MPLY, MNXT, HUE, 	SAT, 		/*|*/ MINS, EQL,  TRNS, TRNS, TRNS, TRNS, 
																	TRNS, TRNS, GAME
	),

	[RAISE] = LAYOUT_kc(
	F1,   F2,   F3,   F4,    F5,   F6,   /*|*/  F7,   F8,   F9,   F10,   F11,   F12, 
	TRNS, REC1, REC2, PLY1,  PLY2, STOP, /*|*/  LEFT, DOWN, UP,   RGHT,  LEAD,  TRNS,
	TRNS, TRNS, TRNS, TRNS,  TRNS, TRNS, /*|*/ 	HOME, PGDN, PGUP, END,   TRNS,  TRNS, 
																	CAPS, TRNS, TRNS
	),

	[GAME] = LAYOUT_kc(
	TAB,	Q, 	W, 	E, 	R, 	T, /*|*/	Y, 	U, 	I, 	 O, 	 P, 	  BSPC, 
	LCTL,	A, 	S, 	D, 	F,	G, /*|*/	H, 	J, 	K, 	 L, 	 SCLN, QUOT, 
	LSFT, Z, 	X, 	C, 	V, 	B, /*|*/  N, 	M, 	COMM, DOT, SLSH, TRNS, 
											WEAP, SPC, ENT
	),

	[WEAPONS] = LAYOUT_kc(
	ESC,  1, 	  TRNS,    2,    	3,    TRNS, /*|*/ 	6,  7,   8,  9,   0,   DEL,
	4, 	 	TRNS, TRNS, 	 TRNS, 	5, 		TRNS, /*|*/ 	F1, F2,  F3, F4,  F5,  F6, 
	TRNS, TRNS, TRNS, 	 LALT, 	TRNS, TRNS, /*|*/ 	F7, F8,  F9, F10, F11, F12, 
																		TRNS, TRNS, GAME

	)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case LGUI_T(KC_SPC):
            return TAPPING_TERM + 100;
		case LCTL_T(KC_ESC):
		   	return TAPPING_TERM	- 50;
		case RSFT_T(KC_SLSH):
				return TAPPING_TERM - 100;
        default:
            return TAPPING_TERM;
	}
}

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
	SEQ_TWO_KEYS(KC_C, KC_D) {
	  SEND_STRING("vim ~/qmk_firmware/keyboards/reviung39/keymaps/curlyLasagna");
	}
    SEQ_THREE_KEYS(KC_R, KC_S, KC_T) {
      SEND_STRING("(cd ~/qmk_firmware; make reviung39:curlyLasagna:dfu)");
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
