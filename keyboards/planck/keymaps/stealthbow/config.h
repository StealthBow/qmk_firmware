#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND) }
#endif

#define FORCE_NKRO

/* Backlight Settings
*/
#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 5
#define BREATHING_PERIOD 6
#define BACKLIGHT_BREATHING 0

/* Mouse Key Settings
*/
#define MOUSEKEY_DELAY 300
#define MOUSEKEY_INTERVAL 25
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_TIME_TO_MAX 20
#define MOUSEKEY_WHEEL_MAX_SPEED 2
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#endif
