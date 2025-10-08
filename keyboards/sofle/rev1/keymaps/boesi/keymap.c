// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include <stdio.h>

enum sofle_layers {
    _BASE,
    _NUSY1,
    _NUSY2,
    _NUSY3,
    _VIM,
    _FN,
    _Template
};

enum custom_keycodes {
    KC_BASE = SAFE_RANGE
};

enum unicode_names {
    U_ß,
		U_L_0, U_L_1, U_L_2, U_L_3, U_L_4, U_L_5, U_L_6, U_L_7, U_L_8, U_L_9, U_L_P, U_L_M, U_L_E,
		U_U_0, U_U_1, U_U_2, U_U_3, U_U_4, U_U_5, U_U_6, U_U_7, U_U_8, U_U_9, U_U_P, U_U_M, U_U_E,
		U_FRAC, U_ALM_EQL
};

const uint32_t PROGMEM unicode_map[] = {
    [U_ß]   = 0x1E9E, // ẞ
		[U_L_0] = 0x2080, // ₀
		[U_L_1] = 0x2081, // ₁
		[U_L_2] = 0x2082, // ₂
		[U_L_3] = 0x2083, // ₃
		[U_L_4] = 0x2084, // ₄
		[U_L_5] = 0x2085, // ₅
		[U_L_6] = 0x2086, // ₆
		[U_L_7] = 0x2087, // ₇
		[U_L_8] = 0x2088, // ₈
		[U_L_9] = 0x2089, // ₉
		[U_L_P] = 0x208A, // ₊
		[U_L_M] = 0x208B, // ₋
		[U_L_E] = 0x208C, // ₌

		[U_U_0] = 0x2070, // ⁰
		[U_U_1] = 0x00B9, // ¹
		[U_U_2] = 0x00B2, // ²
		[U_U_3] = 0x00B3, // ³
		[U_U_4] = 0x2074, // ⁴
		[U_U_5] = 0x2075, // ⁵
		[U_U_6] = 0x2076, // ⁶
		[U_U_7] = 0x2077, // ⁷
		[U_U_8] = 0x2078, // ⁸
		[U_U_9] = 0x2079, // ⁹
		[U_U_P] = 0x207A, // ⁺
		[U_U_M] = 0x207B, // ⁻
		[U_U_E] = 0x207C, // ⁼
		[U_FRAC] = 0x2044, // ⁄
		[U_ALM_EQL] = 0x2248 // ≈
};

#define KC_KPAS KC_F14
#define KC_Ä    ALGR(KC_A)
#define KC_Ö    ALGR(KC_O)
#define KC_Ü    ALGR(KC_U)
#define KC_ß    ALGR(KC_S)
#define KC_EURO ALGR(KC_5)
#define KC_LDQT ALGR(KC_8)
#define KC_RDQT ALGR(KC_9)
#define KC_LSQT SAGR(KC_8)
#define KC_RSQT SAGR(KC_9)
#define KC_MPNT SAGR(KC_SCLN)
#define KC_PRGF SAGR(KC_S)
#define KC_DEGR ALGR(KC_SCLN)
#define KC_UL_0 UM(U_L_0)
#define KC_UL_1 UM(U_L_1)
#define KC_UL_2 UM(U_L_2)
#define KC_UL_3 UM(U_L_3)
#define KC_UL_4 UM(U_L_4)
#define KC_UL_5 UM(U_L_5)
#define KC_UL_6 UM(U_L_6)
#define KC_UL_7 UM(U_L_7)
#define KC_UL_8 UM(U_L_8)
#define KC_UL_9 UM(U_L_9)
#define KC_UL_P UM(U_L_P)
#define KC_UL_M UM(U_L_M)
#define KC_UL_E UM(U_L_E)
#define KC_UU_0 UM(U_U_0)
#define KC_UU_1 UM(U_U_1)
#define KC_UU_2 UM(U_U_2)
#define KC_UU_3 UM(U_U_3)
#define KC_UU_4 UM(U_U_4)
#define KC_UU_5 UM(U_U_5)
#define KC_UU_6 UM(U_U_6)
#define KC_UU_7 UM(U_U_7)
#define KC_UU_8 UM(U_U_8)
#define KC_UU_9 UM(U_U_9)
#define KC_UU_P UM(U_U_P)
#define KC_UU_M UM(U_U_M)
#define KC_UU_E UM(U_U_E)
#define KC_UFRA UM(U_FRAC)
#define KC_UAEQ UM(U_ALM_EQL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------------------.                       ,-----------------------------------------------------.
 * |        |    1   |    2   |    3   |    4   |    5   |                       |    6   |    7   |    8   |    9   |    0   |    ß   |
 * |--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
 * |  Tab   |    Q   |    W   | VIM/E  |    R   |    T   |                       |    Y   |    U   |    I   |    O   |    P   |    Ü   |
 * |--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
 * |   '"   |    A   |    S   |    D   |    F   |    G   |---------.   ,---------|    H   |    J   |    K   |    L   |    Ö   |    Ä   |
 * |--------+--------+--------+--------+--------+--------|   MUTE  |   |  LClck  |--------+--------+--------+--------+--------+--------|
 * |        |    Z   |    X   |    C   |    V   |    B   |---------|   |---------|    N   |    M   |   ,<   |   .>   |   ;:   |    ß   |
 * `-----------------------------------------------------/        /     \        \-----------------------------------------------------'
 *                |        |        |  BKSP  |        | / Space  /       \ Enter  \ |        |  DEL   |        |         |
 *                |  LGUI  |  LAlt  |  LCTR  |  NuSy1 |/ LSHIFT /         \ RSHIFT \|   FN   |  RCTR  |  RAlt  |   RGUI  |
 *                `--------------------------------------------'           '---------------------------------------------'
 */
[_BASE] = LAYOUT(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ß,
     KC_TAB,    KC_Q,  KC_W, LT(_VIM,KC_E), KC_R,   KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_Ü,
    KC_QUOT, GUI_T(KC_A), ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), KC_G,                            KC_H, SFT_T(KC_J), CTL_T(KC_K), ALT_T(KC_L),    KC_Ö,    KC_Ä,
    _______,        KC_Z,        KC_X,        KC_C,        KC_V, KC_B, KC_MUTE,       KC_MS_BTN1, KC_N,        KC_M,     KC_COMM,      KC_DOT, KC_SCLN, KC_ß,
    KC_LGUI, KC_LALT, LCTL_T(KC_BSPC), TT(_NUSY1), LSFT_T(KC_SPC),    RSFT_T(KC_ENT),  TT(_FN), RCTL_T(KC_DEL), KC_RALT, KC_RGUI
),
/* NumSym1
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   @  |   !  |   /  |   [  |   ]  |                    | Frac |   7  |   8  |   9  | Num* | XXXX |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ~   |   #  |   &  |   -  |   (  |   )  |-------.    ,-------| Num. |   4  |   5  |   6  | Num- | Num/ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   $  |   *  |   =  |   {  |   }  |-------|    |-------|   0  |   1  |   2  |   3  | Num+ | Mum= |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *            |      |      |      |      | /      /        \      \ |      |      |      |       |
 *            |      |      |      |      |/      /          \NuSy2 \| XXXX | NuSy3|      |       |
 *            `----------------------------------'            '-----------------------------------'
 */
[_NUSY1] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,   KC_AT, KC_EXLM, KC_SLSH, KC_LBRC, KC_RBRC,                       KC_UFRA,    KC_7,    KC_8,    KC_9, KC_PAST, XXXXXXX,
  KC_TILD, KC_HASH, KC_AMPR, KC_MINS, KC_LPRN, KC_RPRN,                       KC_PDOT,    KC_4,    KC_5,    KC_6, KC_PMNS, KC_PSLS,
  _______,  KC_DLR, KC_ASTR,  KC_EQL, KC_LCBR, KC_RCBR, KC_MPLY,  KC_MS_BTN2,    KC_0,    KC_1,    KC_2,    KC_3, KC_PPLS, KC_PENT,
                    _______, _______, _______, _______, _______,  MO(_NUSY2), XXXXXXX, MO(_NUSY3), _______, _______
),
/* NumSym2
 * ,-----------------------------------------------------.                       ,-----------------------------------------------------.
 * |        |        |        |        |        |        |                       |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
 * |        |    `   |    °   |    ?   |    \   |    |   |                       |        |   ₇    |   ₈    |   ₉    |        |        |
 * |--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
 * |   ≈    |    %   |    ^   |    _   |    „   |    “   |---------.   ,---------|        |   ₄    |   ₅    |   ₆    |    ₋   |        |
 * |--------+--------+--------+--------+--------+--------|         |   |         |--------+--------+--------+--------+--------+--------|
 * |        |    €   |    ·   |    +   |    <   |    >   |---------|   |---------|    ₀   |   ₁    |   ₂    |   ₃    |    ₊   |    ₌   |
 * `-----------------------------------------------------/        /     \        \-----------------------------------------------------'
 *                |        |        |        |        | /        /       \        \ |        |        |        |        |
 *                |        |        |        |        |/        /         \        \|        |        |        |        |
 *                `--------------------------------------------'           '--------------------------------------------'
 */
[_NUSY2] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______,  KC_GRV, KC_DEGR, KC_QUES, KC_BSLS, KC_PIPE,                         _______, KC_UL_7, KC_UL_8, KC_UL_9, _______, _______,
    KC_UAEQ, KC_PERC, KC_CIRC, KC_UNDS, KC_LDQT, KC_RDQT,                         _______, KC_UL_4, KC_UL_5, KC_UL_6, KC_UL_M, _______,
    _______, KC_EURO, KC_MPNT, KC_PLUS,   KC_LT,   KC_GT, _______,       _______, KC_UL_0, KC_UL_1, KC_UL_2, KC_UL_3, KC_UL_P, KC_UL_E,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* NumSym3
 * ,-----------------------------------------------------.                       ,-----------------------------------------------------.
 * |        |        |        |        |        |        |                       |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                       |        |    ⁷   |    ⁸   |    ⁹   |        |        |
 * |--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
 * |        |    §   |        |        |   ‚    |   ‘    |---------.   ,---------|        |    ⁴   |    ⁵   |    ⁶   |    ⁻   |        |
 * |--------+--------+--------+--------+--------+--------|         |   |         |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |---------|   |---------|    ⁰   |    ¹   |    ²   |    ³   |    ⁺   |    ⁼   |
 * `-----------------------------------------------------/        /     \        \-----------------------------------------------------'
 *                |        |        |        |        | /        /       \        \ |        |        |        |        |
 *                |        |        |        |        |/        /         \        \|        |        |        |        |
 *                `--------------------------------------------'           '--------------------------------------------'
 */
[_NUSY3] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, KC_UU_7, KC_UU_8, KC_UU_9, _______, _______,
    _______, KC_PRGF, _______, _______, KC_LSQT, KC_RSQT,                         _______, KC_UU_4, KC_UU_5, KC_UU_6, KC_UU_M, _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, KC_UU_0, KC_UU_1, KC_UU_2, KC_UU_3, KC_UU_P, KC_UU_E,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* VIM
 * ,-----------------------------------------------------.                       ,-----------------------------------------------------.
 * |        |        |        |        |        |        |                       |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                       |        |        |        |        |        |        |
 * |--------+--ESC---+-Colon--+--------+--Enter-+--------|                       |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |---------.   ,---------|        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|         |   |         |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |---------|   |---------|        |        |        |        |        |        |
 * `-----------------------------------------------------/        /     \        \-----------------------------------------------------'
 *                |        |        |        |        | /        /       \        \ |        |        |        |        |
 *                |        |        |        |        |/        /         \        \|        |        |        |        |
 *                `--------------------------------------------'           '--------------------------------------------'
 */
[_VIM] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______,  KC_ESC, KC_COLN, _______,  KC_ENT, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
                   _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______
),
/* FN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | KPASS| Calc | XXXX | Pscr | ScrLk| Pause|                    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Sw-Inp| XXXX | XXXX | XXXX | Ins  | Caps |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Gui  | Alt  | Ctrl | Shift| Tab  |-------.    ,-------| Left | Down |  Up  | Right|  Tab | XXXX |
 * |------+------+------+------+------+------|  MUTE |    | RClck |------+------+------+------+------+------|
 * |      | XXXX | XXXX | XXXX | XXXX | Menu |-------|    |-------| HOME | PGDN | PGUP | End  | XXXX |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *            |      |      | BKSP |      | /Enter /        \Space \ |      | DEL  |      |      |
 *            | LGUI | LAlt | LCTR | XXXX |/Enter /          \Space \|  FN  | RCTR | RAlt | RGUI |
 *            `----------------------------------'            '------''---------------------------'
 */
[_FN] = LAYOUT(
  KC_KPAS, KC_CALC, XXXXXXX, KC_PSCR, KC_SCRL, KC_PAUS,                         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  UC_NEXT, XXXXXXX, XXXXXXX, XXXXXXX,  KC_INS, KC_CAPS,                         KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_TAB,                       KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_TAB, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_APP, KC_MPLY,  KC_MS_BTN2, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, _______,
                    _______, _______, _______, XXXXXXX, _______,     _______, _______, _______, _______, _______
),
/* Template
 * ,-----------------------------------------------------.                       ,-----------------------------------------------------.
 * |        |        |        |        |        |        |                       |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                       |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |---------.   ,---------|        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|         |   |         |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |---------|   |---------|        |        |        |        |        |        |
 * `-----------------------------------------------------/        /     \        \-----------------------------------------------------'
 *                |        |        |        |        | /        /       \        \ |        |        |        |        |
 *                |        |        |        |        |/        /         \        \|        |        |        |        |
 *                `--------------------------------------------'           '--------------------------------------------'
 */
[_Template] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
                   _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______
),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
	[_BASE]     = {ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
	[_NUSY1]    = {ENCODER_CCW_CW(KC_MFFD, KC_MRWD), ENCODER_CCW_CW(KC_MS_WH_RIGHT, KC_MS_WH_LEFT)},
	[_NUSY2]    = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
	[_NUSY3]    = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
	[_VIM]      = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
	[_FN]       = {ENCODER_CCW_CW(KC_MFFD, KC_MRWD), ENCODER_CCW_CW(KC_MS_WH_RIGHT, KC_MS_WH_LEFT)},
	[_Template] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
};
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current layer
    oled_write_ln_P(PSTR("Layer"), false);
     switch (get_highest_layer(layer_state)) {
         case _BASE:
             oled_write_ln_P(PSTR("Base"), false);
             break;
         case _FN:
            oled_write_ln_P(PSTR("Fn"), false);
            break;
        case _NUSY1:
            oled_write_P(PSTR("NuSy1"), false);
            break;
        case _NUSY2:
            oled_write_P(PSTR("NuSy2"), false);
            break;
        case _NUSY3:
            oled_write_P(PSTR("NuSy3"), false);
            break;
        case _VIM:
            oled_write_ln_P(PSTR("Vim"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
						break;
    }
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("-----"), false);
		char mode[] = "     ";
		switch (get_unicode_input_mode()) {
			case UNICODE_MODE_LINUX:
				mode[2] = 'L';
				break;
			case UNICODE_MODE_WINCOMPOSE:
				mode[2] = 'W';
				break;
			default:
				mode[2] = 'U';
				break;
		}
		/* How can I determine which side is master?
    if (is_swap_hands_on()) {
			mode[4] = '>';
    } else {
			mode[0] = '<';
    }
		*/
		oled_write_ln(mode, false);
    oled_write_ln_P(PSTR("-----"), false);
    char str[6];
    sprintf(str, "%5d", get_current_wpm());
    oled_write_ln(str, false);
    oled_write_ln_P(PSTR("-----"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(PSTR("C N S"), false);
    oled_write_P(PSTR(" "), led_usb_state.caps_lock);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(" "), led_usb_state.num_lock);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(" "), led_usb_state.scroll_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
            }
            return false;
    }
    return true;
}

