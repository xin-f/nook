
#include "basics.h"

using namespace std;

void my_sleep(int sec) {
#if _Windows
	Sleep(sec * 1000);
#elif _Linux
	sleep(sec);
#else
#error error
#endif
}

void info(std::string str, ErrCat  general) {
	cout << "Info: " + str << endl;
}
