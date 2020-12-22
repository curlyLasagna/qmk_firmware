LINK_TIME_OPTIMIZATION_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
EXTRAKEY_ENABLE = yes       
RGBLIGHT_ENABLE = yes       
SPLIT_KEYBOARD = yes
BOOTLOADER = qmk-dfu
LAYOUTS = ortho_4x12
LEADER_ENABLE = yes
NKRO_ENABLE = yes            
MCU = atmega32u4

<<<<<<< HEAD
# DISABLED RULES
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
BOOTMAGIC_ENABLE = no      # Virtual DIP switch configuration
BLUETOOTH_ENABLE = no      # Enable Bluetooth with the Adafruit EZ-Key HID
SLEEP_LED_ENABLE = no      # Breathing sleep LED during USB suspend
MOUSEKEY_ENABLE = no       # Mouse keys
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
UNICODE_ENABLE = no        # Unicode
AUDIO_ENABLE = no          # Audio output on port C6
MIDI_ENABLE = no           # MIDI controls
=======
# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
>>>>>>> upstream/master

