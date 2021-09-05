
#include "IBook.h"


int IBook::getDuration() {
	system_clock::time_point now = system_clock::now();
	std::chrono::nanoseconds dura = now.time_since_epoch() - time_borrow.time_since_epoch();//返回的是std::chrono::duration,nanoseconds是duration的特化。
	Day days = std::chrono::duration_cast<Day>(dura);
	std::cout << "current days: " << days.count() << std::endl;
	std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(dura);
	std::cout << "current seconds: " << sec.count() << std::endl;
	return 0;
}

IBook::IBook(std::string* name, std::string* aut = nullptr)
{
	this->name = name;
	author = aut;
	owner = nullptr;
}

IBook::~IBook()
{
	name = nullptr;
	author = nullptr;
	owner = nullptr;
}

