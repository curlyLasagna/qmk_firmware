#include QMK_KEYBOARD_H
extern uint8_t  is_master;
static uint32_t oled_timer = 0;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum layers {
	ROOT,
	LOWER,
	RAISE,
	GAME,
	WEAPONS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ROOT] = LAYOUT(
	KC_TAB, 		KC_Q, 	KC_W,	 KC_E, 	KC_R, 	KC_T, /*|*/	 KC_Y, 	 KC_U, 	KC_I, 	 KC_O, 	 KC_P, 	  KC_DEL, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_LCTL, 		KC_A, 	KC_S, 	 KC_D, 	KC_F,	KC_G, /*|*/	 KC_H, 	 KC_J, 	KC_K, 	 KC_L, 	 KC_SCLN, KC_LALT, 
	/*---------------------------------------------------------------------------------------------------------------*/
	OSM(MOD_LSFT), 	KC_Z, 	KC_X,  	 KC_C, 	KC_V, 	KC_B, /*|*/  KC_N, 	 KC_M, 	KC_COMM, KC_DOT, KC_SLSH, KC_GRV, 
	/*---------------------------------------------------------------------------------------------------------------*/
					KC_LGUI, LT(LOWER, KC_ESC), KC_SPC,   /*|*/	 	LGUI_T(KC_ENT), LT(RAISE, KC_BSPC), KC_LEAD
	),
											
	[LOWER] = LAYOUT(
	KC_GRV,  KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,    /*|*/ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    RGB_MOD, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, RGB_TOG,  RGB_VAI, /*|*/ KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, TG(GAME), KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MPRV, KC_MPLY, KC_MFFD, RGB_HUI, RGB_SAI, /*|*/ KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
	/*---------------------------------------------------------------------------------------------------------------*/
					KC_TRNS, KC_TRNS, KC_TRNS, 							KC_TRNS, KC_BSPC, KC_TRNS
	),

	[RAISE] = LAYOUT(
	KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,  /*|*/  KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, DM_REC1, DM_REC2, DM_PLY1,  DM_PLY2, DM_RSTP,/*|*/  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_INS,  KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT,  KC_PSCR, KC_BRK, /*|*/  KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_TRNS,  KC_CAPS, 
	/*---------------------------------------------------------------------------------------------------------------*/
					KC_TRNS, KC_TAB, KC_TRNS, 							KC_TRNS, KC_TRNS, KC_TRNS
	),

	[GAME] = LAYOUT(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
    KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                                  KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_NO,
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_TRNS,                               KC_PGUP, KC_PGDN, KC_NO, KC_NO, KC_NO, KC_NO,
                          KC_TAB, MO(WEAPONS), KC_SPC,              KC_ENT, TG(GAME), KC_NO
    ),

	[WEAPONS] = LAYOUT(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                              KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                               KC_7, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EEP_RST,
                              KC_TRNS, KC_TAB, KC_TRNS,             KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

LEADER_EXTERNS();

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

void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
		leading = false;
		leader_end();

		SEQ_ONE_KEY(KC_F) {
		  SEND_STRING("QMK is awesome.");
		}
		SEQ_THREE_KEYS(KC_Y, KC_I, KC_W) {
		  SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
		}
		SEQ_THREE_KEYS(KC_R, KC_S, KC_T) {
		  SEND_STRING("cd /home/luis/qmk_firmware; make crkbd:curlyLasagna:dfu" SS_TAP(X_ENT));
		}
	}
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_master) 
        return OLED_ROTATION_180;  

    return rotation;
}

char wpm[10];
const char *read_wpm(void) {
	snprintf(wpm, sizeof(wpm), "WPM: %d", get_current_wpm());
	decay_wpm();
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

void oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > OLED_TIMEOUT) {
        oled_off();
        return;
    } else {
        oled_on();
    }

    if (is_master) {
        render_crkbd_logo();
		//oled_write(kapp(), false );
    } else {
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_wpm(), false);
    }
}

void suspend_power_down_keymap(void) {
    oled_off();
}

void suspend_wakeup_init_keymap(void) {
    oled_on();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	oled_timer = timer_read32();
	if (record->event.pressed) {
		set_keylog(keycode, record);
		update_wpm(keycode);
	  }
	  return true;
}
#endif
