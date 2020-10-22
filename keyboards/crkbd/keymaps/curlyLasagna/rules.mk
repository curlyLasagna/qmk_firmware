# If you want to change the display of OLED, you need to change here
		
SRC +=  ./lib/keylogger.c \
				./lib/layer_state_reader.c \
				#./lib/glcdfont.c \
				#./lib/mode_icon_reader.c \
				#./lib/host_led_state_reader.c \
				#./lib/rgb_state_reader.c

OLED_DRIVER_ENABLE = yes
OLED_TIMEOUT = 50000

LTO_ENABLE = yes
EXTRAKEY_ENABLE = yes
NKRO_ENABLE = yes
LEADER_ENABLE = yes

RGBLIGHT_ENABLE = yes
WPM_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes

CONSOLE_ENABLE = no
AUDIO_ENABLE = no
COMMAND_ENABLE = no
SWAP_HANDS_ENABLE = no
BLUETOOTH_ENABLE = no
MIDI_ENABLE = no
UNICODE_ENABLE = no
BACKLIGHT_ENABLE = no
AUTO_SHIFT_ENABLE = no
KEY_LOCK_ENABLE = no
TERMINAL_ENABLE = no
MOUSEKEY_ENABLE = no
