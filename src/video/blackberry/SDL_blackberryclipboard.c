/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2013 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "SDL_config.h"

#if SDL_VIDEO_DRIVER_BLACKBERRY

#include "SDL_blackberryvideo.h"

#include "../../core/blackberry/SDL_blackberry.h"

int
BlackBerry_SetClipboardText(_THIS, const char *text)
{
    return BlackBerry_SYS_SetClipboardText(text);
}

char *
BlackBerry_GetClipboardText(_THIS)
{
    return BlackBerry_SYS_GetClipboardText();
}

SDL_bool BlackBerry_HasClipboardText(_THIS)
{
    return BlackBerry_SYS_HasClipboardText();
}

#endif /* SDL_VIDEO_DRIVER_BLACKBERRY */

/* vi: set ts=4 sw=4 expandtab: */
