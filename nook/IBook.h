#ifndef __IBOOK_H__
#define __IBOOK_H__

#include <vector>
#include "../basic/basics.h"
#include "Owner.h"
/*
把借出去的书按时间降序排列，每次只需要检查第一本，如果没到期，break；如果到期，发邮件，检查下一本。
*/

class IBook
{
	friend class BookManager;
protected:
	std::string* name;
	std::string* author;
	//a user can borrow multiple books, but a book can be obtained by only one user simultaneously. So the time stampe 
	//goes with book. Time value is stored in time_point, unless it is printed.
	std::chrono::system_clock::time_point time_borrow; //1970-1-1 8:0:0
	std::chrono::system_clock::time_point time_return; //1970-1-1 8:0:0
	Owner* owner; //不能用引用，因为没法在ctor里给初值。

	std::vector <std::pair< std::chrono::system_clock::time_point ,std:: string>> history; // log, contains date and user id.

	IBook() = default;
	IBook(std::string* name,  std::string* aut);
	~IBook();

public:
	void setTimeBorrow() {
		time_borrow = std::chrono::system_clock::now();
	}

	void setTimeReturn() {
		time_return = std::chrono::system_clock::now();
	}
	bool less(system_clock::time_point t1, system_clock::time_point t2) {
		return t1 < t2;
	}

	int getDuration() ;


};

#endif // !__IBOOK_H__

