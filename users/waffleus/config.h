/* Copyright 2021 @Itswaffle/@waffle#6666
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include "config_common.h"

#define IGNORE_MOD_TAP_INTERRUPT
#define PERSMISSVE_HOLD
#define TAPPING_TERM 150
#define LAYER_STATE_8BIT
#define USB_POLLING_INTERVAL_MS 1
#define TAPPING_TERM_PER_KEY

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10
//#define RGBLIGHT_LAYERS
#endif

#ifdef OLED_DRIVER_ENABLE
#define OLED_TIMEOUT 30000
#define OLED_FONT_H "users/waffleus/oledfonts.c"
#endif

#ifdef UNICODEMAP_ENABLE
#define UNICODE_SELECTED_MODES UC_WINC, UC_MAC, UC_LNX
#define UNICODE_CYCLE_PERSIST false
#endif

#ifdef MOUSEKEY_ENABLE
#define MOUSEKEY_DELAY 300
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 5
#endif

#ifdef AUTOSHIFT_ENABLE
#define AUTO_SHIFT_MODIFIERS
#define AUTO_SHIFT_TIMEOUT 170
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC
#endif

#ifdef SPLIT_KEYBOARD
#define EE_HANDS
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
#define BOOTMAGIC_LITE_ROW_RIGHT 4
#define BOOTMAGIC_LITE_COLUMN_RIGHT 0
#endif

#ifdef COMBO_ENABLE
#define COMBO_COUNT 16
#define COMBO_TERM 50
#endif

#ifdef KEYBOARD_crkbd_rev1_common
#define USE_SERIAL_PD2
#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 27
#define RGBLIGHT_LIMIT_VAL 155
#endif