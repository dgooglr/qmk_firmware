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
#include "davidg.h" // Includes Norwegian and custom keymaps

extern keymap_config_t keymap_config;

enum planck_layers {
  _BASE,
  _GAME,
  _LOWER,
  _RAISE,
  _FN,
  _SYSTEM
};

enum planck_keycodes {
  base = SAFE_RANGE,
  wntg
};

bool winkey_enabled = true;
bool gamemode_enabled = false;

/* Define mod keys */
#define game TG(_GAME)
#define lw MO(_LOWER)
#define ra MO(_RAISE)
#define fn MO(_FN)
#define rset RESET

#define ____ KC_TRNS
#define xxxx KC_NO

// UPPERCASE keycodes are handled by process_record_user() in the file 'brianoverby.c' from userspace

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_planck_grid(
        tab,  q,    w,    e,    r,    t,    y,    u,    i,    o,    p,    bspc,
        esc,  a,    s,    d,    f,    g,    h,    j,    k,    l,    SCLN, QUOT,
        LSFT, z,    x,    c,    v,    b,    n,    m,    COMM, DOT,  SLSH,  ent,
        lctl, fn,   lgui, lalt, lw,   spc,  spc,  ra,   left, up,   down,  rght
    ),

    [_GAME] = LAYOUT_planck_grid(
        n1,   q,    w,    e,    r,    t,    y,    u,    i,    o,    p,    bspc,
        ____, a,    s,    d,    f,    g,    h,    j,    k,    l,    SCLN, QUOT,
        ____, z,    x,    c,    v,    b,    n,    m,    COMM, DOT,  SLSH,  ent,
        ____, n4,   n3,   n2,   lw,   spc,  spc,  ra,   left, up,   down,  rght
    ),

    [_LOWER] = LAYOUT_planck_grid(
        tild, exlm,  at,hash, dlr,perc, circ, ampr, astr, lprn, rprn, bspc,
        ____, ____,____,____,____,____, xxxx, unds, plus, lcbr, rcbr, acut,
        ____, ____,____,____,____,____, xxxx, mins,  eql, lbrc, rbrc, ____,
        ____,   fn,lgui,lalt,____,____, ____, ____, bsls, pipe, xxxx, xxxx
    ),

    [_RAISE] = LAYOUT_planck_grid(
        grv,  n1,   n2,   n3,     n4,   n5,   n6,   n7,   n8,   n9,   n0, bspc,
        ____, n4,   n5,   n6,   xxxx, xxxx, xxxx,   n4,   n5,   n6, xxxx,  uml,
        ____, n7,   n8,   n9,   xxxx, xxxx, xxxx,   n1,   n2,   n3, xxxx, ____,
        ____, fn,   n0,   lalt, ____, ____, ____,   ra,   left, up, down,  rght
    ),

    [_FN] = LAYOUT_planck_grid(
        tab,  f1,   f2,   f3,   f4,   xxxx, xxxx, xxxx, ins,  xxxx, xxxx, aa,
        del,  f5,   f6,   f7,   f8,   xxxx, xxxx, xxxx, xxxx, xxxx, ae,   oe,
        ____, f9,   f10,  f11,  f12,  xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, del,
        ____, fn,   lgui, lalt, ____, ____, ____, ____, home, pgup, pgdn, end
    ),

    [_SYSTEM] = LAYOUT_planck_grid(
        xxxx, xxxx, wntg, xxxx, rset, xxxx, xxxx, xxxx, xxxx, xxxx, prnt, xxxx,
        xxxx, xxxx, xxxx, xxxx, xxxx, game, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
        xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, mute,  xxxx,
        xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, next, volu, vold, play
    )
};

/* Hold Lower + Raise to activate SYSTEM layer */
uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _SYSTEM);
  return state;
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case game:
      if (record->event.pressed) { // Toggle game mode
        gamemode_enabled = !gamemode_enabled;
      }
      return true;
      break;
    case wntg:
      if (record->event.pressed) { // Toggle Windows Key
        winkey_enabled = !winkey_enabled;
      }
      return false;
      break;
    case lgui: // Check if Windows Key is disabled 
      if (!winkey_enabled) {
        return false;
      } else {
        return true;
      }
      break;
    case tild: // Send TAB, when game mode is enabled else send ~ or `
    case grv:
      if(gamemode_enabled) {
        if (record->event.pressed) {
          register_code(KC_TAB);
        } else {
          unregister_code(KC_TAB);
        }
        return false;
      } else {
        return true;
      }
      break;
  }
  return true;
}
