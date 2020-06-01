EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
NKRO_ENABLE = yes

CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SWAP_HANDS_ENABLE = no
BLUETOOTH_ENABLE = no
MIDI_ENABLE = no
UNICODE_ENABLE = no

SLEEP_LED_ENABLE = no
OLED_TIMEOUT = 60000
OLED_DRIVER_ENABLE = yes
RGB_MATRIX_ENABLE = WS2812

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
