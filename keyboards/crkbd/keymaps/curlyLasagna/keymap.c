#include QMK_KEYBOARD_H

enum layers {
	ROOT,
	LOWER,
	RAISE,
	ETC
};

extern uint8_t is_master;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ROOT] = LAYOUT(
	KC_ESC, 		KC_Q, 	KC_W,	 KC_E, 	KC_R, 	KC_T, /*|*/	 KC_Y, 	 KC_U, 	KC_I, 	 KC_O, 	 KC_P, 	  KC_BSPC, 
	/*---------------------------------------------------------------------------------------------------------------*/
	LCTL_T(KC_TAB), KC_A, 	KC_S, 	 KC_D, 	KC_F,	KC_G, /*|*/	 KC_H, 	 KC_J, 	KC_K, 	 KC_L, 	 KC_SCLN, LALT_T(KC_ENT), 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_LSFT, 		KC_Z, 	KC_X,  	 KC_C, 	KC_V, 	KC_B, /*|*/  KC_N, 	 KC_M, 	KC_COMM, KC_DOT, KC_SLSH, LT(ETC, KC_GRV), 
	/*---------------------------------------------------------------------------------------------------------------*/
				    KC_LCTL, MO(LOWER), SFT_T(KC_SPC),   /*|*/	 LGUI_T(KC_ENT), LT(RAISE, KC_BSPC), KC_LALT
	),
											
	[LOWER] = LAYOUT(
	KC_GRV,  KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,    /*|*/ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,  KC_TRNS, /*|*/ KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, KC_TRNS, KC_TRNS, 
	/*---------------------------------------------------------------------------------------------------------------*/
	KC_TRNS, KC_MPRV, KC_MPLY, KC_MFFD, KC_BSPC, KC_TRNS, /*|*/ KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
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
					KC_TRNS, KC_TRNS, KC_TRNS, 							KC_TRNS, KC_TRNS, KC_TRNS
	)
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the d#isplay
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

const char *read_mode_icon(bool swap);
const char *read_host_led_state(void);
void set_timelog(void);
const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display_arr, source->display_arr, sizeof(dest->display_arr))) {
    memcpy(dest->display_arr, source->display_arr, sizeof(dest->display_arr));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case ROOT:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<ROOT);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(LOWER);
        update_tri_layer_RGB(LOWER, RAISE, ETC);
      } else {
        layer_off(LOWER);
        update_tri_layer_RGB(LOWER, RAISE, ETC);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(RAISE);
        update_tri_layer_RGB(LOWER, RAISE, ETC);
      } else {
        layer_off(RAISE);
        update_tri_layer_RGB(LOWER, RAISE, ETC);
      }
      return false;
    case ETC:
        if (record->event.pressed) {
          layer_on(ETC);
        } else {
          layer_off(ETC);
        }
        return false;
  }
  return true;
}
