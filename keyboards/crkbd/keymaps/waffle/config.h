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

#define EE_HANDS
//#define MASTER_RIGHT
//#define MASTER_LEFT

#define USE_SERIAL_PD2
#define LAYER_STATE_8BIT
#define FELIX
#define BONGO
//#define NANOBOOT //nanoboot bootloader support
//#define RANDICT //this literally adds 8000 bytes to your compiled firmware

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLED_NUM 27
    #undef RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 5
    #define RGBLIGHT_SAT_STEP 5
    #define RGBLIGHT_VAL_STEP 17
    #define RGBLED_SPLIT
    #define RGBLIGHT_SLEEP
#endif

#ifdef MOUSEKEY_ENABLE
#define MOUSEKEY_DELAY 300
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 5
#endif

#ifdef BOOTMAGIC_ENABLE
// top left and top right
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
#define BOOTMAGIC_LITE_ROW_RIGHT 4
#define BOOTMAGIC_LITE_COLUMN_RIGHT 0
#endif

#ifdef OLED_DRIVER_ENABLE
#define OLED_TIMEOUT 10000
//#define SSD1306OLED
#define OLED_FONT_H "keyboards/crkbd/keymaps/waffle/glcdfont.c"
#endif

#define NANOBOOT
//#define RANDICT //this literally adds 8000 bytes to your compiled firmware

#ifdef UNICODEMAP_ENABLE
#define UNICODE_SELECTED_MODES UC_WINC, UC_MAC, UC_LNX
#define UNICODE_CYCLE_PERSIST false
#endif

#ifdef AUTOSHIFT_ENABLE
#define AUTO_SHIFT_MODIFIERS
#define AUTO_SHIFT_TIMEOUT 170
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC
#endif

#ifndef NO_DEBUG
#define NO_DEBUG
#endif

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_TERM 150

#ifdef COMBO_ENABLE
  #define COMBO_COUNT 17
  #define COMBO_TERM 50
#endif


