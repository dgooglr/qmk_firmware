/* Copyright 2020 David Gulbrandsen
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
#include QMK_KEYBOARD_H
#include "keymap_nordic.h"
#include "keymap_norwegian.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    GMAIL = SAFE_RANGE,
    QMKURL,
    CUT,
    PASTE,
    DITTO
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | #    |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ø  |  Æ   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   UP |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | Alt  | Lower |Raise| Space| Space|bk spc|Enter |Left  | Down |Right |
 * `-----------------------------------------------------------------------------------'
    [_BASE] = LAYOUT(
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, NO_AA, 
		KC_HASH, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, NO_OSLH, NO_AE, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_ENT,
		KC_LCTL, KC_LGUI, KC_LALT, LOWER, RAISE, KC_SPC, KC_SPC, KC_BSPC, NO_MINS, KC_LEFT, KC_DOWN, KC_RGHT),
 */
    [_BASE] = LAYOUT(
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, NO_OSLH, NO_AE, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_ENT,
		KC_LCTL, KC_LGUI, KC_LALT, LOWER, RAISE, KC_SPC, KC_SPC, KC_BSPC, NO_MINS, KC_LEFT, KC_DOWN, KC_RGHT),
    /* Lower
 * ,-----------------------------------------------------------------------------------.
 * | @  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | Ø| Æ   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   UP |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | Alt  | Lower |Raise| Space| Space|bk spc|Enter |Left  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
    [_LOWER] = LAYOUT(
		NO_AT, KC_EXLM, NO_QUES, NO_QUO2, NO_DLR, NO_PLUS, NO_EQL, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, 
		KC_TAB, NO_SLSH, KC_PERC, NO_AMPR, NO_APOS, NO_LPRN, NO_RPRN, KC_4, KC_5, KC_6, KC_0, KC_PSCR, 
		KC_LSFT, NO_UNDS, KC_NO, KC_NO, KC_NO, NO_LBRC, NO_RBRC, KC_1, KC_2, KC_3, KC_UP, KC_TRNS, 
		KC_LCTL, KC_LGUI, KC_LALT, LOWER, RAISE, KC_SPC, KC_SPC, KC_DEL, KC_ENT, KC_LEFT, KC_DOWN, KC_RGHT),
    /* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | #    |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Æ  |  Ø   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   UP |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | Alt  | Lower |Raise| Space| Space|bk spc|Enter |Left  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
    [_RAISE] = LAYOUT(
		KC_ESC, CUT, PASTE, DITTO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_END, KC_F11, 
		KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, 
		NO_ASTR, KC_NO, GMAIL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLU, KC_MUTE, 
		KC_LCTL, KC_LGUI, KC_LALT, LOWER, RAISE, KC_SPC, KC_SPC, KC_BSPC, KC_MPLY, KC_MPRV, KC_VOLD, KC_MNXT)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GMAIL:
            if (record->event.pressed) {
                // when keycode GMAIL is pressed
                SEND_STRING("david.gulbrandsen"SS_ALGR("2")"gmail.com");

            } else {
                // when keycode GMAIL is released
            }
            break;    
        case CUT:
            if (record->event.pressed) {
                // when keycode CUT is pressed
                SEND_STRING( SS_LCTRL("c"));
            } else {
                // when keycode CUT is released
            }
            break;    
        case PASTE:
            if (record->event.pressed) {
                // when keycode PASTE is pressed
                SEND_STRING( SS_LCTRL("v"));
            } else {
                // when keycode PASTE is released
            }
            break;            
        case DITTO:
            if (record->event.pressed) {
                // when keycode CUT is pressed
                SEND_STRING(SS_LCTRL(SS_TAP(X_UP)));
            } else {
                // when keycode CUT is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
