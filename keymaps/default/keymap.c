#include QMK_KEYBOARD_H
#include "secrets.c"

enum macrocodes{
  UPDIR = SAFE_RANGE,
  SECRET,
  POSTFIX
};

// credit: https://getreuer.info/posts/keyboards/macros/index.html
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case UPDIR:  // Types ../ to go up a directory on the shell.
      if (record->event.pressed) {
        SEND_STRING("../");
      }
      return false;
    case SECRET: 
      if (record->event.pressed) {
        SEND_STRING(SECRET_STR);
      }
      return false;
    case POSTFIX:
      if (record->event.pressed) {
        SEND_STRING(POSTFIX_STR);
      }
      return false;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'
 *    |       Q       |       W       |       E       |       R       |       T       |       Y       |       U       |       I       |       O       |       P       |    
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|    
 *    |    CTRL/A     |     ALT/S     |     GUI/D     |    SHIFT/F    |       G       |       H       |    SHIFT/J    |     GUI/K     |     ALT/L     |    CTRL/;     |    
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|    
 *    |       Z       |       X       |       C       |       V       |       B       |       N       |       M       |       ,       |       .       |       /       |    
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|    
 *    |     KC_NO     |     KC_NO     |    [1]/ESC    |     [2]/SPC   |     [3]/TAB   |   [4]/ENTER   |   [5]/BKSPC   |    [6]/DEL    |     KC_NO     |     KC_NO     |    
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */
    [0] = LAYOUT(
        KC_Q,			KC_W,			KC_E,			KC_R,			KC_T,			KC_Y,			KC_U,			KC_I,			KC_O,			KC_P,			
        LCTL_T(KC_A),	LALT_T(KC_S),	LGUI_T(KC_D),	LSFT_T(KC_F),	KC_G,			KC_H,			RSFT_T(KC_J),	RGUI_T(KC_K),	RALT_T(KC_L),	RCTL_T(KC_SCLN),			
        KC_Z,			KC_X,			KC_C,			KC_V,			KC_B,			KC_N,			KC_M,			KC_COMM,		KC_DOT,			KC_SLSH,			
        KC_NO,			KC_NO,			LT(1,KC_ESC),	LT(2,KC_SPC),	LT(3,KC_TAB),	LT(4,KC_ENT),	LT(5,KC_BSPC),	LT(6,KC_DEL),	KC_NO,			KC_NO
    ),
 /*
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'  
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |   BOOTLOADER  |     
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|   
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|    
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |    
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|    
 *    |     KC_NO     |     KC_NO     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     KC_NO     |     KC_NO     |     
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */
    [1] = LAYOUT(
        SECRET,		    POSTFIX,		UPDIR,		    KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		QK_BOOT,			
        KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		
        KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		
        KC_NO,			KC_NO,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_NO,			KC_NO
    ),
 /*
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'  
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|   
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|    
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |    
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|     
 *    |     KC_NO     |     KC_NO     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     KC_NO     |     KC_NO     |     
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */
    [2] = LAYOUT(
        KC_EXLM,		KC_AT,			KC_HASH,		KC_DLR,			KC_ASTR,		KC_AMPR,		KC_LPRN,		KC_RPRN,		KC_MINS,		KC_EQL,			
        KC_LCTL,		KC_LALT,		KC_LGUI,		KC_LSFT,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		
        KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_LBRC,		KC_RBRC,		KC_BSLS,		KC_QUOT,		KC_GRV,			
        KC_NO,			KC_NO,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_NO,			KC_NO
    ),
 /*
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'  
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|   
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|    
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |    
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|    
 *    |     KC_NO     |     KC_NO     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     KC_NO     |     KC_NO     |     
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */
	[3] = LAYOUT(
        KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_PGUP,		KC_HOME,		KC_UP,			KC_END,			KC_PGDN,			
        KC_LCTL,		KC_LALT,		KC_LGUI,		KC_LSFT,		KC_TRNS,		KC_TRNS,		KC_LEFT,		KC_DOWN,		KC_RGHT,		KC_TRNS,		
        KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_INS,			
        KC_NO,			KC_NO,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_NO,			KC_NO
    ),
 /*
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'
 *    |       1       |       2       |       3       |       4       |       5       |       6       |       7       |       8       |       9       |       0       |    
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|    
 *    |      F1       |      F2       |      F3       |      F4       |      F5       |      F6       |      F7       |      F8       |      F9       |      F0       |    
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|    
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |      F11      |      F12      |    
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|   
 *    |     KC_NO     |     KC_NO     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     KC_NO     |     KC_NO     |     
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */			   
	[4] = LAYOUT(
        KC_TRNS,		KC_7,			KC_8,			KC_9,			KC_0,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		
        KC_TRNS,		KC_4,			KC_5,			KC_6,			KC_TRNS,		KC_TRNS,		KC_RSFT,		KC_RGUI,		KC_RALT,		KC_RCTL,			
        KC_TRNS,		KC_1,			KC_2,			KC_3,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		
        KC_NO,			KC_NO,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_NO,			KC_NO
    ),
 /*
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'  
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|   
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|    
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |    
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|    
 *    |     KC_NO     |     KC_NO     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     KC_NO     |     KC_NO     |     
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */
	[5] = LAYOUT(
        KC_TRNS,		KC_F9,			KC_F10,			KC_F11,			KC_F12,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		
        KC_TRNS,		KC_F5,			KC_F6,			KC_F7,			KC_F8,			KC_TRNS,		KC_RSFT,		KC_RGUI,		KC_RALT,		KC_RCTL,			
        KC_TRNS,		KC_F1,			KC_F2,			KC_F3,			KC_F4,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		
        KC_NO,			KC_NO,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_NO,			KC_NO
    ),
 /*
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'  
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|   
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|    
 *    |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |    
 *    |---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------|     
 *    |     KC_NO     |     KC_NO     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     xxxxx     |     KC_NO     |     KC_NO     |    
 *    `---------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */
	[6] = LAYOUT(
        RGB_TOG,		RGB_VAI,		RGB_HUI,		RGB_SAI,		RGB_SPI,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		
        RGB_MOD,		RGB_VAD,		RGB_HUD,		RGB_SAD,		RGB_SPD,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		
        RGB_RMOD,		KC_TRNS,		KC_TRNS,		LCG_NRM,		LCG_SWP,		RCG_SWP,		RCG_NRM,		KC_TRNS,		KC_TRNS,		KC_TRNS,		
        KC_NO,			KC_NO,			KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_NO,			KC_NO
    )
};
