#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "extras.c"
#include "macros.h"
#include "unicodes.h"
#include "combos.h"
#include "tapdance.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
		QMKTD,   KC_Q,    KC_W,     KC_E,   KC_R,    KC_T,          KC_Y,   KC_U,     KC_I, KC_O,    KC_P,    GPSCR, KC_VOLU,
		ALT_TAB, SFA,     KC_S,     KC_D,   KC_F,    KC_G,          KC_H,   KC_J,     KC_K, SFL,    KC_BSPC, KC_MPLY,
		CP_PSTE, CTLTZ,   KC_X,     KC_C,   KC_V,    KC_B,         CLICK,  KC_N,     KC_M, KC_COMM, CTLDOT,  KC_SLSH, KC_VOLD,
		HAPSAD,  KC_LALT,                    KC_LGUI, LWRSPC,	      MO(2), KC_RGUI,                          KC_MPRV, KC_MNXT
    ),

    [1] = LAYOUT(
		DOCSTD,    KC_1,   KC_2,   KC_3,   KC_4,    KC_5,                  KC_6,       KC_7,       KC_8,      KC_9,     KC_0,   KC_VOLD,   KC_VOLU,
		WEEB,   KC_EXLM,   KC_AT,   KC_HASH,   KC_DLR,    KC_PERC,          KC_CIRC,   KC_AMPR,    KC_ASTR,   KC_LPRN,  SFPRN,   KC_BSLS,
		VIA,   CTLESC,   KC_TAB,   KC_CAPS,   KC_TILD,    KC_GRV,          KC_NO,   KC_LEFT,       KC_UP,   KC_DOWN,   CTLRGHT,   KC_SLSH,   KC_NLCK,
		XWIDE,   KC_LALT,                         KC_LGUI,    KC_TRNS,	        KC_SLSH,   KC_NOMODE,                                     KC_SCRIPT,   KC_BLOCKS
    ),

    [2] = LAYOUT(
		RESET,  KC_MINS,     KC_EQL,    KC_LBRC,   KC_RBRC,    KC_BSLS,          CG_NORM,   KC_ASUP,  KC_ASON,    UNIT,    UNIT2,      UNIT4,  UNIT3,
		UC_M_WC,  KC_UNDS,   KC_PLUS,   KC_LCBR,   KC_RCBR,    KC_PIPE,          CG_SWAP,   KC_ASDN, KC_ASOFF,   KC_TRNS,   KC_TRNS,   KC_TRNS,
		UC_M_MA,  KC_F1,     KC_F2,     KC_F3,   KC_F4,        KC_F5,            KC_F6,     KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_SLSH,  KC_NLCK,
		MAKE,  KC_LALT,                         KC_LGUI,    KC_SCLN,	         KC_TRNS,   KC_RGUI,                               KC_RALT,  KC_RCTL
    )
};