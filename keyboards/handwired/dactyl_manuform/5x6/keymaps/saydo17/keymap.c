/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define CTLDOT LCTL(KC_DOT)


enum custom_keycodes {
  ARW = SAFE_RANGE,
  PEQL,
  MEQL,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_GESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
     KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LALT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_EQL,
                      KC_LPRN,KC_RPRN,                                                       KC_LBRC, KC_RBRC,
                                      KC_ENT,KC_SPC,                        RAISE, KC_LSFT,
                                      KC_HOME, KC_LSFT,                     KC_DEL,  KC_END,
                                      LOWER, KC_LGUI,                       KC_MEH, XXXXXXX
  ),

  [_LOWER] = LAYOUT_5x6(

     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,_______,
     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,KC_PMNS,_______,
     _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_PPLS,_______,
     _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_PENT ,_______,
                     _______,KC_PSCR,                                                         KC_P0 , KC_PDOT,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),

  [_RAISE] = LAYOUT_5x6(
       _______, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       KC_MUTE,_______,KC_HOME ,KC_UP  ,KC_END ,KC_PGUP,                        _______,_______,_______,_______,_______,KC_F12 ,
       KC_VOLU,_______,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,                        KC_UNDS,_______,_______,_______,MEQL   ,_______,
       KC_VOLD,_______,_______,_______,_______,_______,                        KC_MINS,_______,_______,CTLDOT ,PEQL   ,ARW    ,
                       _______,_______,                                                       _______, _______,
                                               _______,_______,            _______,KC_MEH,
                                               _______,_______,        LCA(KC_END),_______,
                                               _______,_______,            _______,_______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case ARW:
         if (record->event.pressed) {
            SEND_STRING("=>");
            return false;
         }
         break;
      case PEQL:
         if(record->event.pressed){
            SEND_STRING("+=");
            return false;
         }
         break;
      case MEQL:
         if(record->event.pressed){
            SEND_STRING("-=");
            return false;
         }
         break;
  }
  return true;
}
