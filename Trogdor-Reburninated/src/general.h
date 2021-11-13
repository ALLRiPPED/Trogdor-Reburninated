#ifndef GENERAL_H
#define GENERAL_H

/* General-use Variables */
extern Sint8 i, j, k;
extern int int_i, int_j, int_k;
extern Uint32 uint_i, uint_j, uint_k;
extern float float_i;

struct Timer {
    double now;
    double last;
};

#define PI 3.14159265

#define RANDINT(min, max) \
    (rand() % ((max) - (min) + 1) + min)

#define LEN(arr) \
    (sizeof(arr) / sizeof(arr[0]))

#define ZERO_OUT_ARRAY(arr) \
    (memset(arr, 0, sizeof(arr)))

#define PRINT(str) \
    cout << str << endl

#define SIN_WAVE(timeVal, halfPeriod, amplitude) \
    (sin((timeVal) * PI / (halfPeriod)) * (amplitude))

#define COS_WAVE(timeVal, halfPeriod, amplitude) \
    (cos((timeVal) * PI / (halfPeriod)) * (amplitude))

#define MOVE_FAST_THEN_DECELERATE(dist, numSeconds, timeVal) \
    (0.5 * pow(((((numSeconds) - (timeVal)) / (numSeconds)) * sqrt(2 * (dist))), 2))

#define UPDATE_TIMER(timer) \
    timer.last = timer.now; \
    timer.now = SDL_GetTicks() / 1000.0;

#if defined(WII_U) || defined(VITA) || defined(SWITCH) || defined(WII) || defined(GAMECUBE) || defined(SDL1)
#define SDL_TOGGLE_FULLSCREEN()
#else
#define SDL_TOGGLE_FULLSCREEN()                                 \
	if (isWindowed)                                             \
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN); \
	else                                                        \
		SDL_SetWindowFullscreen(window, 0);                     \
	isWindowed = !isWindowed;
#endif

#endif