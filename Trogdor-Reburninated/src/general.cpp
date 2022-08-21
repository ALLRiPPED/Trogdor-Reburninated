#include "general.h"

#if defined(SDL1) && !defined(WII) && !defined(GAMECUBE) && !defined(PSP)
FILE _iob[] = { *stdin, *stdout, *stderr };

FILE * __cdecl __iob_func(void) {
	return _iob;
}
#endif

void SYSTEM_SPECIFIC_OPEN() {
#if defined(WII_U)
	/* Set SD Card Mount Path */
	if (!WHBMountSdCard()) {
		return 0;
	}
	if (WHBGetSdCardMountPath() == NULL) {
		return 0;
	}
	string sdPathStr = "/wiiu/apps/Trogdor-Beta";
	const char *sdPathStart = WHBGetSdCardMountPath();
	sdPathStr = sdPathStart + sdPathStr;
	const char *sdPath = sdPathStr.c_str();
	chdir(sdPath);
#elif defined(VITA)
	/* Disable rear touch pad */
	SDL_setenv("VITA_DISABLE_TOUCH_BACK", "1", 1);
#elif defined(SWITCH)
	/* Set SD Card mount path */
	chdir("/switch/Trogdor-Beta");
#elif defined(WII) || defined(GAMECUBE)
	/* Initialize SD Card */
	fatInitDefault();
#endif
}

void SYSTEM_SPECIFIC_CLOSE() {
#if defined(WII_U)
	/* Unmount SD Card */
	WHBUnmountSdCard();
#elif defined(VITA)
	sceKernelExitProcess(0);
#elif defined(WII) || defined(GAMECUBE)
	exit(EXIT_SUCCESS);
#elif defined(PSP)
	sceKernelExitGame();
#endif
}