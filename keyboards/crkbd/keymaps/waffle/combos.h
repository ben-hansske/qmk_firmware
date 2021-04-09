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

enum combos {
  RU_ENT,
  GH_QUOT,
  VM_QUES,
  CM_DQUO,
  TY_COLN,
  BN_UNDS,
  FJ_MINS,
  DF_BTN1,
  JK_BTN2,
  VB_WHD,
  NM_WHU,
  SD_MSD,
  KL_MSU,
  XC_CLICK,
  RT_DEL,
  MACMD
};

const uint16_t PROGMEM ru_combo[] = {KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM vm_combo[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM cm_combo[] = {KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM ty_combo[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM bn_combo[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM click_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM mac_combo[] = {KC_Z, KC_P, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
[RU_ENT] = COMBO(ru_combo, KC_ENT),
[GH_QUOT] = COMBO(gh_combo, KC_QUOT),
[VM_QUES] = COMBO(vm_combo, KC_QUES),
[CM_DQUO] = COMBO(cm_combo, KC_DQUO),
[TY_COLN] = COMBO(ty_combo, KC_COLN),
[BN_UNDS] = COMBO(bn_combo, KC_UNDS),
[FJ_MINS] = COMBO(fj_combo, KC_MINS),
[DF_BTN1] = COMBO(df_combo, KC_BTN1),
[JK_BTN2] = COMBO(jk_combo, KC_BTN2),
[VB_WHD] = COMBO(vb_combo, KC_WH_D),
[NM_WHU] = COMBO(nm_combo, KC_WH_U),
[SD_MSD] = COMBO(sd_combo, KC_MS_D),
[KL_MSU] = COMBO(kl_combo, KC_MS_U),
[XC_CLICK] = COMBO_ACTION(click_combo),
[RT_DEL] = COMBO_ACTION(del_combo),
[MACMD] = COMBO_ACTION(mac_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case XC_CLICK:
        if (pressed) {
            register_code(KC_TAB);
            register_code(KC_ENT);
            unregister_code(KC_TAB);
            unregister_code(KC_ENT);
            register_code(KC_ENT);
            unregister_code(KC_ENT);
        }
        break;

    case RT_DEL:
        if (pressed) {
            SEND_STRING(SS_TAP(X_UP)SS_LCTL("a")"achoo"SS_TAP(X_ENT));
        }
        break;

    case MACMD:
        if (pressed) {
            default_layer_set(1UL << _QWERTY);
        }
        break;
  }
}