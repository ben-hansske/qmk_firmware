MCU = atmega32u4
#BOOTLOADER = nano-boot
#BOOTLOADER_SIZE = 512
BOOTLOADER = caterina
RGBLIGHT_ENABLE = no
AUDIO_ENABLE = no
OLED_DRIVER_ENABLE = yes
GRAVE_ESC_ENABLE = no
EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes
WPM_ENABLE = yes
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = yes
SPACE_CADET_ENABLE = no
UNICODE_ENABLE = no
UNICODEMAP_ENABLE = no
AUTO_SHIFT_ENABLE = no
SWAP_HANDS_ENABLE = no
CONSOLE_ENABLE = yes
COMBO_ENABLE = yes
BOOTMAGIC_ENABLE = no
TAP_DANCE_ENABLE = yes
POINTING_DEVICE_ENABLE = no
KEYLOGGER_ENABLE = yes
ifdef POINTING_DEVICE_ENABLE
	SRC += i2c_master.c
endif

ifeq ($strip $(WAFFLE)), yes)
    OPT_DEFS += -DWAFFLE
endif
