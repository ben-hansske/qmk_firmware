/* Copyright 2020 @wafflekeebs/@waffle#6666
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
#include <string.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return 1;
}

void render_wpm(void) {
    char wpm_string[5];
        oled_write_ln("WPM:", false);
        snprintf(wpm_string,
    sizeof(wpm_string), " %3d",
    get_current_wpm());
        oled_write(wpm_string, false);
};

void render_qmk_logo(void) {
    static const char PROGMEM font_qmk_logo[16] = {0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0};
    oled_write_P(font_qmk_logo, false);
};

void render_keyboard(void) {
    static const char PROGMEM font_keyboard[16] = {0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0};
    oled_write_P(font_keyboard, false);
};

void render_prompt(void) {
    bool blink = (timer_read() % 1000) < 500;
      if (layer_state_is(0)) {
          oled_write_ln_P(blink ? PSTR("> _ ") : PSTR(">     "), false);
      }
};

void render_mod_ctrl(void) { // ^
    static const char PROGMEM font_ctrl[3] = {0x93, 0x94, 0};
    oled_write_P(font_ctrl, false);
};

void render_mod_alt(void) { // ⌥
    static const char PROGMEM font_alt[3] = {0xb3, 0xb4, 0};
    oled_write_P(font_alt, false);
};

void render_mod_shift(void) { // ⇧
    static const char PROGMEM font_shift[3] = {0xd3, 0xd4, 0};
    oled_write_P(font_shift, false);
};

void render_mod_gui(void) { // win symbol
    static const char PROGMEM font_gui[3] = {0x95, 0x96, 0};
    oled_write_P(font_gui, false);
};

void render_mod_status(void) {
    bool blink = (timer_read() % 1000) < 500;
    uint8_t modifiers = get_mods() | get_oneshot_mods();
        if (modifiers & MOD_MASK_CTRL) {
            oled_write_ln_P(blink ? PSTR("$ ctl") : PSTR("$ _  "), false);
        } else if (modifiers & MOD_MASK_SHIFT) {
            oled_write_ln_P(blink ? PSTR("$ sft") : PSTR("$ _  "), false);
        } else if (modifiers & MOD_MASK_ALT) {
            oled_write_ln_P(blink ? PSTR("$ alt") : PSTR("$ _  "), false);
        } else if (modifiers & MOD_MASK_GUI) {
            oled_write_ln_P(blink ? PSTR("$ gui") : PSTR("$ _  "), false);
        } else {
            oled_write_ln_P(blink ? PSTR("$ _  ") : PSTR("$     "), false);
        }
}

/*void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("Lock:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("C"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    oled_write_P(PSTR("N"), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR("S"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}*/

/* almost working :c
void render_mod_status(void) {
    static uint8_t active_mods;
    static uint8_t active_oneshot_mods;
    active_mods = get_mods();
    active_oneshot_mods = get_oneshot_mods();
    char buf[20]={0};
    if((active_mods | active_oneshot_mods) & MOD_MASK_SHIFT) strncat(buf, "+shift", sizeof(buf)-1);
    if((active_mods | active_oneshot_mods) & MOD_MASK_CTRL) strncat(buf, "+ctrl", sizeof(buf)-1);
    if((active_mods | active_oneshot_mods) & MOD_MASK_ALT) strncat(buf, "+alt", sizeof(buf)-1);
    if((active_mods | active_oneshot_mods) & MOD_MASK_GUI) strncat(buf, "+gui", sizeof(buf)-1);
    strncat(buf, "                    ", sizeof(buf)-1);
    oled_write_ln(buf(), false);
}*/

void render_main(void) {
    oled_set_cursor(0, 0);
    render_wpm();
    oled_set_cursor(0, 3);
    render_qmk_logo();
    oled_set_cursor(0, 7);
    render_keyboard();
    oled_set_cursor(0, 10);
    render_prompt();
    oled_set_cursor(0, 12);
    render_mod_status();
}

void oled_task_user(void) {
    render_main();
}
