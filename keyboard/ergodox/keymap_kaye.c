/*
Copyright 2016 Paul Williamson <squarefrog@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <util/delay.h>
#include "bootloader.h"
#include "keymap_common.h"


const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * Keymap 0: Default Workman Layer
     *
     * This is a general purpose Workman layout which should serve as a good
     * basis for your own custom layout. Mac users may want to swap the
     * position of the Alt and GUI keys.
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  Esc   |   1  |   2  |   3  |   4  |   5  |  ~   |           |      |   6  |   7  |   8  |   9  |   0  |   =    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  Tab   |   Q  |   D  |   R  |   W  |   B  | HOME |           | PgUp |   J  |   F  |   U  |   P  |   "  |   -    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | LCtrl  |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  | Enter  |
     * |--------+------+------+------+------+------| END  |           | PgDn |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |   /  | RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Left | Down |  Up  | Rght | LGui |                                       |   [  |   ]  |   \  |   ;   | +L2 |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |CpsLck| Del  |       | PgDn | PgUp |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | LAlt |       | RAlt |      |      |
     *                                 | BkSp | ~L1  |------|       |------|   :  | Space|
     *                                 |      |      | LCtrl|       | RCtrl|      |      |
     *                                 `--------------------'       `--------------------'
     */

    KEYMAP(
        // left hand
        ESC, 1,   2,   3,   4,   5,   GRV,
        TAB, Q,   D,   R,   W,   B,   HOME,
        FN3, A,   S,   H,   T,   G,
        LSFT,Z,   X,   M,   C,   V,   END,
        LEFT,DOWN,UP,  RGHT,FN5,
                                      CAPS,DEL,
                                           LALT,
                                 BSPC,FN1, LCTL,
                                 
        // right hand
             NO,  6,   7,   8,   9,   0,   EQL,
             PGUP,J,   F,   U,   P,   QUOT,MINS,
                  Y,   N,   E,   O,   I,   ENT,
             PGDN,K,   L,   COMM,DOT, SLSH,RSFT,
                       LBRC,RBRC,BSLS,SCLN,FN2,
        PGDN,PGUP,
        RALT,
        RCTL,FN4, SPC
    ),

    /*
     * Layer 1: Function keys
     *
     * This layer contains function keys, and media keys. Additionally, there
     * are QWERTY-style Vim arrow keys. I could never get used to Colemak's
     * rearranged Vim arrow placements.
     *
     * Most of the non-modifier keys are marked as NO, so it's immediately
     * obvious if you start typing on a secondary layer.
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | Teensy |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |  FN31  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   TRNS |      |      |      |      |      | TRNS |           | TRNS |      |      |      |      |      |  TRNS  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |   TRNS |      |      |      |      |      |------|           |------| Left | Down |  Up  | Right|      |  TRNS  |
     * |--------+------+------+------+------+------| +L2  |           |      |------+------+------+------+------+--------|
     * |   TRNS |      |      |      |      |      |      |           |      |      |      |      |      |      |  TRNS  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | TRNS | TRNS | Play |  RW  |  FF  |                                       | Mute | Vol- | Vol+ | TRNS | TRNS |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       | END  | HOME |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 | TRNS | TRNS |------|       |------| TRNS | TRNS |
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 `--------------------'       `--------------------'
     */

    KEYMAP(
        // left hand
        FN31,F1,  F2,  F3,  F4,  F5,  F11,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  FN2,
        TRNS,TRNS,MPLY,MPRV,MNXT,
                                      NO,  NO,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F12, F6,  F7,  F8,  F9,  F10, FN31,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                  LEFT,DOWN,UP,  RGHT,NO,  TRNS,
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
                       MUTE,VOLD,VOLU,TRNS,TRNS,
        END ,HOME,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    /*
    * Layer 2: Number Pad
    *
    * This layer has a number pad for quicker number entry. As with layer 1,
    * most of the non-modifier keys are marked as NO, so it's immediately
    * obvious if you start typing on a secondary layer.
    *
    * Inspired by Ben Blazak QWERTY num pad.
    * https://git.io/voIeY
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |   ESC  |      |      |      |      |      |      |           |      |      | NmLk |   /  |   *  |   -  | Bkspc  |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |   TRNS |      |      |      |      |      | TRNS |           | TRNS |      |   7  |   8  |   9  |   +  | Bkspc  |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |   TRNS |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   +  | Enter  |
    * |--------+------+------+------+------+------|      |           | -L0  |------+------+------+------+------+--------|
    * |   TRNS |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  | Enter| Enter  |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | TRNS | TRNS | LALT |      |      |                                       |   0  |   0  |   .  | Enter| Enter|
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       | TRNS | TRNS |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      | TRNS |       | TRNS |      |      |
    *                                 | Bkspc| TRNS |------|       |------| Enter|      |
    *                                 |      |      | TRNS |       | TRNS |      |      |
    *                                 `--------------------'       `--------------------'
    */

    KEYMAP(
        // left hand
        ESC, NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,TRNS,LALT,NO,  NO,
                                      NO,  NO,
                                           TRNS,
                                 BSPC,TRNS,  TRNS,
        // right hand
             NO,  NO,  NLCK,SLSH,PAST,PMNS,BSPC,
             TRNS,NO,  P7,  P8,  P9,  PPLS,BSPC,
                  NO,  P4,  P5,  P6,  PPLS,PENT,
             FN0, NO,  P1,  P2,  P3,  PENT,PENT,
                       P0,  P0,  PDOT,PENT,PENT,
        TRNS,TRNS,
        TRNS,
        TRNS,ENT, TRNS
    ),
};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    // Layer shifting
    [0] = ACTION_LAYER_SET(0, ON_PRESS),           // Switch to Layer 0
    [1] = ACTION_LAYER_MOMENTARY(1),               // Momentarily switch to layer 1
    [2] = ACTION_LAYER_SET(2, ON_PRESS),           // Switch to Layer 2
    [3] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),   // Send ESC when LCTRL is tapped
    [4] = ACTION_MODS_KEY(MOD_LSFT, KC_SCLN),      // Send : key
    [5] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_LGUI),  // XXX: Hack to send CMD key

    // Teensy
    [31] = ACTION_FUNCTION(TEENSY_KEY),
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}

