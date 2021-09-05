#ifndef __BASICS_H__
#define __BASICS_H__

#ifdef _HAS_STD_BYTE
#undef _HAS_STD_BYTE
#endif
#define _HAS_STD_BYTE 0

/*
瀚海

书单录入，书本数量，可用状态，owner（邮箱，借入，归还时间），

Query : getBookList(), getBookStatus(),
Action : 删 borrow(), 增 replace(), 书目扩充 addNewBook(),

socket
flask

*/

#include <string>
#include <ctime>
#include <chrono>
#include <iostream>
#include <ratio>  //std::ratio<>


//using namespace std;
using namespace std::chrono;

//for sleep() system call
#if defined(__linux) || defined(__linux__) || defined(linux)
#include<unistd.h>
#define _Linux 1
#define _Windows 0
#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#include <Windows.h>
#define _Windows 2
#define _Linux 0
#endif


typedef std::chrono::duration<int, std::ratio<60 * 60> > hours_type;
typedef std::chrono::duration<int, std::ratio<24 * 60 * 60> > Day;

#if 0
unsigned long long operator"" _days(unsigned long long x) {
	return x;
}
#endif

void my_sleep(int sec);
extern system_clock::time_point now; //only for test

 enum class ErrCat{
	general,
	nook,
	dao,
	ipc,
};

void info(std::string, ErrCat  cat = ErrCat::general);

#endif // !__BASICS_H__
