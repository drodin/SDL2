/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997-2010 Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Sam Lantinga
    slouken@libsdl.org
*/
#include "SDL_config.h"

#include <android/log.h>

#include "../../events/SDL_events_c.h"

#include "SDL_androidkeyboard.h"


void Android_InitKeyboard()
{
    SDLKey keymap[SDL_NUM_SCANCODES];

    /* Add default scancode to key mapping */
    SDL_GetDefaultKeymap(keymap);
    SDL_SetKeymap(0, keymap, SDL_NUM_SCANCODES);
}

static SDL_ScanCode Android_Keycodes[] = {
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_UNKNOWN */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_SOFT_LEFT */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_SOFT_RIGHT */
    SDL_SCANCODE_AC_HOME, /* AKEYCODE_HOME */
    SDL_SCANCODE_AC_BACK, /* AKEYCODE_BACK */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_CALL */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_ENDCALL */
    SDL_SCANCODE_0, /* AKEYCODE_0 */
    SDL_SCANCODE_1, /* AKEYCODE_1 */
    SDL_SCANCODE_2, /* AKEYCODE_2 */
    SDL_SCANCODE_3, /* AKEYCODE_3 */
    SDL_SCANCODE_4, /* AKEYCODE_4 */
    SDL_SCANCODE_5, /* AKEYCODE_5 */
    SDL_SCANCODE_6, /* AKEYCODE_6 */
    SDL_SCANCODE_7, /* AKEYCODE_7 */
    SDL_SCANCODE_8, /* AKEYCODE_8 */
    SDL_SCANCODE_9, /* AKEYCODE_9 */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_STAR */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_POUND */
    SDL_SCANCODE_UP, /* AKEYCODE_DPAD_UP */
    SDL_SCANCODE_DOWN, /* AKEYCODE_DPAD_DOWN */
    SDL_SCANCODE_LEFT, /* AKEYCODE_DPAD_LEFT */
    SDL_SCANCODE_RIGHT, /* AKEYCODE_DPAD_RIGHT */
    SDL_SCANCODE_SELECT, /* AKEYCODE_DPAD_CENTER */
    SDL_SCANCODE_VOLUMEUP, /* AKEYCODE_VOLUME_UP */
    SDL_SCANCODE_VOLUMEDOWN, /* AKEYCODE_VOLUME_DOWN */
    SDL_SCANCODE_POWER, /* AKEYCODE_POWER */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_CAMERA */
    SDL_SCANCODE_CLEAR, /* AKEYCODE_CLEAR */
    SDL_SCANCODE_A, /* AKEYCODE_A */
    SDL_SCANCODE_B, /* AKEYCODE_B */
    SDL_SCANCODE_C, /* AKEYCODE_C */
    SDL_SCANCODE_D, /* AKEYCODE_D */
    SDL_SCANCODE_E, /* AKEYCODE_E */
    SDL_SCANCODE_F, /* AKEYCODE_F */
    SDL_SCANCODE_G, /* AKEYCODE_G */
    SDL_SCANCODE_H, /* AKEYCODE_H */
    SDL_SCANCODE_I, /* AKEYCODE_I */
    SDL_SCANCODE_J, /* AKEYCODE_J */
    SDL_SCANCODE_K, /* AKEYCODE_K */
    SDL_SCANCODE_L, /* AKEYCODE_L */
    SDL_SCANCODE_M, /* AKEYCODE_M */
    SDL_SCANCODE_N, /* AKEYCODE_N */
    SDL_SCANCODE_O, /* AKEYCODE_O */
    SDL_SCANCODE_P, /* AKEYCODE_P */
    SDL_SCANCODE_Q, /* AKEYCODE_Q */
    SDL_SCANCODE_R, /* AKEYCODE_R */
    SDL_SCANCODE_S, /* AKEYCODE_S */
    SDL_SCANCODE_T, /* AKEYCODE_T */
    SDL_SCANCODE_U, /* AKEYCODE_U */
    SDL_SCANCODE_V, /* AKEYCODE_V */
    SDL_SCANCODE_W, /* AKEYCODE_W */
    SDL_SCANCODE_X, /* AKEYCODE_X */
    SDL_SCANCODE_Y, /* AKEYCODE_Y */
    SDL_SCANCODE_Z, /* AKEYCODE_Z */
    SDL_SCANCODE_COMMA, /* AKEYCODE_COMMA */
    SDL_SCANCODE_PERIOD, /* AKEYCODE_PERIOD */
    SDL_SCANCODE_LALT, /* AKEYCODE_ALT_LEFT */
    SDL_SCANCODE_RALT, /* AKEYCODE_ALT_RIGHT */
    SDL_SCANCODE_LSHIFT, /* AKEYCODE_SHIFT_LEFT */
    SDL_SCANCODE_RSHIFT, /* AKEYCODE_SHIFT_RIGHT */
    SDL_SCANCODE_TAB, /* AKEYCODE_TAB */
    SDL_SCANCODE_SPACE, /* AKEYCODE_SPACE */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_SYM */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_EXPLORER */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_ENVELOPE */
    SDL_SCANCODE_RETURN, /* AKEYCODE_ENTER */
    SDL_SCANCODE_DELETE, /* AKEYCODE_DEL */
    SDL_SCANCODE_GRAVE, /* AKEYCODE_GRAVE */
    SDL_SCANCODE_MINUS, /* AKEYCODE_MINUS */
    SDL_SCANCODE_EQUALS, /* AKEYCODE_EQUALS */
    SDL_SCANCODE_LEFTBRACKET, /* AKEYCODE_LEFT_BRACKET */
    SDL_SCANCODE_RIGHTBRACKET, /* AKEYCODE_RIGHT_BRACKET */
    SDL_SCANCODE_BACKSLASH, /* AKEYCODE_BACKSLASH */
    SDL_SCANCODE_SEMICOLON, /* AKEYCODE_SEMICOLON */
    SDL_SCANCODE_APOSTROPHE, /* AKEYCODE_APOSTROPHE */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_SLASH */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_AT */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_NUM */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_HEADSETHOOK */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_FOCUS */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_PLUS */
    SDL_SCANCODE_MENU, /* AKEYCODE_MENU */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_NOTIFICATION */
    SDL_SCANCODE_AC_SEARCH, /* AKEYCODE_SEARCH */
    SDL_SCANCODE_AUDIOPLAY, /* AKEYCODE_MEDIA_PLAY_PAUSE */
    SDL_SCANCODE_AUDIOSTOP, /* AKEYCODE_MEDIA_STOP */
    SDL_SCANCODE_AUDIONEXT, /* AKEYCODE_MEDIA_NEXT */
    SDL_SCANCODE_AUDIOPREV, /* AKEYCODE_MEDIA_PREVIOUS */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_MEDIA_REWIND */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_MEDIA_FAST_FORWARD */
    SDL_SCANCODE_MUTE, /* AKEYCODE_MUTE */
    SDL_SCANCODE_PAGEUP, /* AKEYCODE_PAGE_UP */
    SDL_SCANCODE_PAGEDOWN, /* AKEYCODE_PAGE_DOWN */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_PICTSYMBOLS */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_SWITCH_CHARSET */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_A */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_B */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_C */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_X */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_Y */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_Z */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_L1 */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_R1 */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_L2 */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_R2 */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_THUMBL */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_THUMBR */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_START */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_SELECT */
    SDL_SCANCODE_UNKNOWN, /* AKEYCODE_BUTTON_MODE */
};

static SDL_ScanCode
TranslateKeycode(int keycode)
{
    SDL_ScanCode scancode = SDL_SCANCODE_UNKNOWN;

    if (keycode < SDL_arraysize(Android_Keycodes)) {
        scancode = Android_Keycodes[keycode];
    }
    if (scancode == SDL_SCANCODE_UNKNOWN) {
        __android_log_print(ANDROID_LOG_INFO, "SDL", "Unknown keycode %d", keycode);
    }
    return scancode;
}

int
Android_OnKeyDown(int keycode)
{
    return SDL_SendKeyboardKey(SDL_PRESSED, TranslateKeycode(keycode));
}

int
Android_OnKeyUp(int keycode)
{
    return SDL_SendKeyboardKey(SDL_RELEASED, TranslateKeycode(keycode));
}

/* vi: set ts=4 sw=4 expandtab: */
