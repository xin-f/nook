
#include "IBook.h"


int IBook::getDuration() {
	system_clock::time_point now = system_clock::now();
	chrono::nanoseconds dura = now.time_since_epoch() - time_borrow.time_since_epoch();//返回的是chrono::duration,nanoseconds是duration的特化。
	Day days = chrono::duration_cast<Day>(dura);
	cout << "current days: " << days.count() << endl;
	chrono::seconds sec = chrono::duration_cast<chrono::seconds>(dura);
	cout << "current seconds: " << sec.count() << endl;
	return 0;
}

IBook::IBook(string* name, Owner* o = nullptr, string* aut = nullptr)
{
	this->name = name;
	author = aut;
	owner = o;
	cnt++;
	available_cnt++;
}

IBook::~IBook()
{
	name = nullptr;
	author = nullptr;
	owner = nullptr;
	cnt--;
	available_cnt--;
	//todo: for debug
	if (cnt < 0 || available_cnt < 0)
		cout << "error " << cnt << " " << available_cnt << endl;
}

int IBook::cnt = 0;
int IBook::available_cnt = 0;
