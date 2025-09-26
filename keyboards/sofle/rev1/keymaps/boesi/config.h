// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
/* #define IGNORE_MOD_TAP_INTERRUPT */
#undef  TAPPING_TERM
#define TAPPING_TERM 200
#undef  TAPPING_TOGGLE
#define TAPPING_TOGGLE 3
#define WPM_SAMPLE_PERIODS 50
#define PERMISSIVE_HOLD
/* #define CHORDAL_HOLD */
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_WINCOMPOSE
#define SPLIT_USB_DETECT
#define DEBOUNCE 10

