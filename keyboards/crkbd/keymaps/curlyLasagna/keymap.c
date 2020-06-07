#include QMK_KEYBOARD_H
#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t  is_master;

enum layers {
	ROOT,
	LOWER,
	RAISE,
	ETC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ROOT] = LAYOUT(
	KC_TAB, 		KC_Q, 	KC_W,	 KC_E, 	KC_R, 	KC_T, /*|*/	 KC_Y, 	 KC_U, 	KC_I, 	 KC_O, 	 KC_P, 	  KC_DEL, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_LCTL, 		KC_A, 	KC_S, 	 KC_D, 	KC_F,	KC_G, /*|*/	 KC_H, 	 KC_J, 	KC_K, 	 KC_L, 	 KC_SCLN, KC_LALT, 
	/*---------------------------------------------------------------------------------------------------------------*/
	OSM(MOD_LSFT), 	KC_Z, 	KC_X,  	 KC_C, 	KC_V, 	KC_B, /*|*/  KC_N, 	 KC_M, 	KC_COMM, KC_DOT, KC_SLSH, LT(ETC, KC_GRV), 
	/*---------------------------------------------------------------------------------------------------------------*/
		OSM(MOD_LCTL), LT(LOWER, KC_ESC), SFT_T(KC_SPC),  /*|*/	 	LGUI_T(KC_ENT), LT(RAISE, KC_BSPC), OSM(MOD_LALT)
	),
											
	[LOWER] = LAYOUT(
	KC_GRV,  KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,    /*|*/ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,  KC_TRNS, /*|*/ KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, KC_TRNS, KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MPRV, KC_MPLY, KC_MFFD, KC_LGUI, KC_LALT, /*|*/ KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
					KC_TRNS, KC_TRNS, KC_TRNS, 							KC_TRNS, KC_TRNS, KC_TRNS
	),

	[RAISE] = LAYOUT(
	KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,  /*|*/  KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,/*|*/  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_INS,  KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT,  KC_PSCR, KC_BRK, /*|*/  KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_TRNS,  KC_CAPS, 
	/*---------------------------------------------------------------------------------------------------------------*/
					KC_TRNS, KC_TAB, KC_TRNS, 							KC_TRNS, KC_TRNS, KC_TRNS
	),

	[ETC] = LAYOUT(
	KC_TRNS, RGB_TOG, KC_MS_U, RGB_MOD, RGB_SAI, RGB_HUI, /*|*/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, RGB_VAI, KC_TRNS, /*|*/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_WH_D, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, /*|*/ KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
					KC_TRNS, KC_TRNS, KC_MS_BTN1, 					KC_MS_BTN2, KC_TRNS, KC_TRNS
	)
};

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

#ifdef SSD1306OLED
// When add source files to SRC in rules.mk, you can use functions.

void set_keylog(uint16_t keycode, keyrecord_t *record);
void set_timelog(void);

const char *read_layer_state(void);
const char *read_logo(void);
const char *read_keylog(void);
const char *read_keylogs(void);
const char *read_timelog(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
void matrix_scan_user(void) {
	iota_gfx_task();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_master) {
        return OLED_ROTATION_180;  
    }
    return rotation;
}

char 
	wpm[10],

const char *read_wpm(void) {
	snprintf(wpm, sizeof(wpm), "\nWPM: %d", get_current_wpm());
	decay_wpm();
	return wpm;
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
		if(get_current_wpm() > 1)
    //matrix_write_ln(matrix, read_timelog());
    //matrix_write(matrix, read_logo());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
  } else {
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
	matrix_write_ln(matrix, read_wpm());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
	set_timelog();
	update_wpm(keycode);
#endif
  }
  return true;
}

