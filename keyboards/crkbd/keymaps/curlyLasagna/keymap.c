#include QMK_KEYBOARD_H

extern uint8_t  is_master;
static uint32_t oled_timer = 0;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

/* LAYERS */
#define KC_LOW MO(LOWER)
#define KC_GAMER TG(GAME)
#define KC_RISE LT(RAISE, KC_CAPS)
#define KC_WEP MO(WEAPONS)

/* LHS MOD-TAPS */
#define KC_L0 LGUI_T(KC_SPC)
#define KC_L1 LCTL_T(KC_ESC)
#define KC_L2 LALT_T(KC_GRV)

/* RHS MOD-TAPS */
#define KC_R1 RCTL_T(KC_ENT)
#define KC_R2 RGUI_T(KC_RALT)

/* RGB */
#define KC_MODE RGB_MOD
#define KC_BRIGHT RGB_VAI
#define KC_HUE RGB_HUI
#define KC_SAT RGB_SAI

#define KC_RST RESET

/* DYNAMIC MACROS */
#define KC_RECF DM_REC1
#define	KC_RECS DM_REC2
#define	KC_PLYF DM_PLY1
#define	KC_PLYS	DM_PLY2
#define	KC_STOP DM_RSTP

enum layers {
	ROOT,
	LOWER,
	RAISE,
	GAME,
	WEAPONS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ROOT] = LAYOUT_kc(
	/*-------------------------------------------------------------------------*/
	TAB,    Q, 		W,		E, 		R,   	T, 	 		Y, 		U, 		I, 	  O,  	P, 	 	BSPC, 
	/*-------------------------------------------------------------------------*/
	L1,		A, 		S,  	D, 		F, 	 	G, 	 		H, 		J, 		K, 	  L,  	SCLN,	QUOT, 
	/*-------------------------------------------------------------------------*/
	LSFT,	Z, 		X,  	C, 		V, 	 	B, 	   		N, 		M, 		COMM, DOT, 	SLSH,	RSFT, 
	/*-------------------------------------------------------------------------*/
	L2, 	LOW, 	L0, 			        R1, 	RISE,	R2
	),
											
	[LOWER] = LAYOUT_kc(
	/*--------------------------------------------------------------------------*/
	GRV,  1,   	2,    3,    4,    5,    	 	6,    7,    8,    9,    0,   	DEL, 
	/*--------------------------------------------------------------------------*/
	TRNS, MUTE, VOLD, VOLU, MODE, BRIGHT,   LBRC, RBRC, BSLS, PSCR, BRK, 	INS, 
	/*--------------------------------------------------------------------------*/
	TRNS, MPRV, MPLY, MNXT, HUE,  SAT, 	   	MINS, EQL,  TRNS, TRNS, TRNS, TRNS, 
	/*--------------------------------------------------------------------------*/
										TRNS, TRNS, TRNS, 	 	TRNS, GAMER, TRNS
	),

	[RAISE] = LAYOUT_kc(
	/*--------------------------------------------------------------------------*/
	F1,   F2,   F3,   F4,   F5,   F6,   		F7,   F8,   F9,   F10,   F11,  F12, 
	/*--------------------------------------------------------------------------*/
	TRNS, RECF, RECS, PLYF, PLYS, STOP,			LEFT, DOWN, UP,   RGHT,  LEAD, TRNS, 
	/*--------------------------------------------------------------------------*/
	TRNS, RST, TRNS, CAPS,	TRNS, TRNS,  		HOME, PGDN, PGUP, END,   TRNS, TRNS, 
	/*--------------------------------------------------------------------------*/
										TRNS, TRNS, TRNS, 		TRNS, TRNS, TRNS
	),

	[GAME] = LAYOUT_kc(
	/*--------------------------------------------------------------------------*/
  TAB,  TRNS, TRNS, TRNS, TRNS, TRNS,     TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
	/*--------------------------------------------------------------------------*/
  LCTL, TRNS, TRNS, TRNS, TRNS, TRNS,     TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
	/*--------------------------------------------------------------------------*/
  LSFT, TRNS, TRNS, TRNS, TRNS, TRNS,     TRNS, TRNS, COMM, DOT,  TRNS, TRNS,
	/*--------------------------------------------------------------------------*/
                    LALT, WEP, 	SPC,      ENT,  NO, TRNS   
	),

	[WEAPONS] = LAYOUT_kc(
	/*--------------------------------------------------------------------------*/
    ESC,  1, 	  TRNS, 2,    3, 		4,       6,     7,   8, 	 9, 	0, 	 DEL,
	/*--------------------------------------------------------------------------*/
    4, 	 	TRNS, TRNS, TRNS, 5,    TRNS,    F1,    F2,  F3,  F4,  F5,  F6,
	/*--------------------------------------------------------------------------*/
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,    F7,    F8, 	F9,  F10, F11, F12,
	/*--------------------------------------------------------------------------*/
                      TRNS, TRNS, SPC,     TRNS, GAMER, TRNS 
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


void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_layer_state(void);
const char *read_keylog(void);
const char *read_keylogs(void);

//const char *read_timelog(void);
//const char *read_mode_icon(bool swap);
//const char *read_host_led_state(void);
//void set_timelog(void);
 
// Emote logos
//const char *gachi(void);
//const char *pogo(void);
//const char *kapp(void);

bool leader_succeed;
LEADER_EXTERNS();
void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
		leader_succeed = leading = false;
		leader_end();
		SEQ_TWO_KEYS(KC_C, KC_D) {
			SEND_STRING("vim ~/qmk_firmware/keyboards/crkbd/keymaps/curlyLasagna");
			leader_succeed = true;
		}
		SEQ_THREE_KEYS(KC_R, KC_S, KC_T) {
		  SEND_STRING("(cd /home/luis/qmk_firmware; make crkbd:curlyLasagna:dfu)");
		  leader_succeed = true;
		}
		SEQ_FOUR_KEYS(KC_R, KC_S, KC_T, KC_L) {
		  SEND_STRING("(cd /home/luis/qmk_firmware; make crkbd:curlyLasagna:dfu-split-left)");
		  leader_succeed = true;
		}
		SEQ_FOUR_KEYS(KC_R, KC_S, KC_T, KC_R) {
		  SEND_STRING("(cd /home/luis/qmk_firmware; make crkbd:curlyLasagna:avrdude-split-right)");
		  leader_succeed = true;
		}
	}
}

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM capslock_enabled[] = RGBLIGHT_LAYER_SEGMENTS (
	{6, 1, HSV_RED},
	{13, 1, HSV_RED},
	{14, 1, HSV_RED}
);

const rgblight_segment_t PROGMEM lower_enabled[] = RGBLIGHT_LAYER_SEGMENTS (
	{6, 1, HSV_PURPLE},	
	{13, 1, HSV_PURPLE},
	{14, 1, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM raise_enabled[] = RGBLIGHT_LAYER_SEGMENTS (
	{6, 1, HSV_TEAL},	
	{13, 1, HSV_TEAL},
	{14, 1, HSV_TEAL}
);

const rgblight_segment_t PROGMEM game_enabled[] = RGBLIGHT_LAYER_SEGMENTS (
	{6, 1, HSV_YELLOW},
	{13, 1, HSV_YELLOW},
	{14, 1, HSV_YELLOW}
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

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_master) 
        return OLED_ROTATION_180;  
    return rotation;
}

void suspend_power_down_keymap(void) {
    oled_off();
}

void suspend_wakeup_init_keymap(void) {
    oled_on();
}

char wpm[10];
const char *read_wpm(void) {
	snprintf(wpm, sizeof(wpm), "WPM: %d", get_current_wpm());
	return wpm;
}

void render_crkbd_logo(void){
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

// Render separator lines for oled display
void render_separator(void) {
	oled_write_ln_P(PSTR("((̲̅ ̲̅(̲̅C̲̅r̲̅a̲̅y̲̅o̲̅l̲̲̅̅a̲̅( ̲̅((>"), false);
}

// Render current layer state
void render_layer_state(void){
	// If you want to change the display of OLED, you need to change here
    switch (get_highest_layer(layer_state)){
        case ROOT:
            oled_write_ln_P(PSTR("BASED LAYER"), false);
            break;
        case LOWER:
            oled_write_ln_P(PSTR("LOWER LAYER"), false);
            break;
        case RAISE:
            oled_write_ln_P(PSTR("RAISED LAYER"), false);
            break;
        case GAME:
            oled_write_ln_P(PSTR("GAMER MODE"), false);
            break;
        case WEAPONS:
            oled_write_ln_P(PSTR("WEAPONS"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????????????????"), false);
    }
}

void oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > OLED_TIMEOUT) {
        oled_off();
        return;
    } else {
        oled_on();
		if (is_master) {
			render_crkbd_logo();
		} else {
			render_layer_state();
			oled_write_ln(read_keylogs(), false);
			oled_write_ln(read_wpm(), false);
			}
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		oled_timer = timer_read32();
		set_keylog(keycode, record);
		update_wpm(keycode);
	  }
	  return true;
}
#endif
