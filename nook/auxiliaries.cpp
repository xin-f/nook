
#include "basics.h"

void my_sleep(int sec) {
#if _Windows
	Sleep(sec * 1000);
#elif _Linux
	sleep(sec);
#else
#error error
#endif
}

