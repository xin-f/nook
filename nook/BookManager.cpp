#include "BookManager.h"




void BookManager::addNewBook(string* name, Owner* o = nullptr, string* aut = nullptr)
{
	IBook* book = new IBook(name, o, aut);
	bookList.emplace(name, book);
}

void BookManager::deleteBook(string* name)
{
	if(bookList.count(*name) > 1)
	if (bookList[book] == 0)
	{
		delete book;
		bookList.erase(book);
	}
}

IBook* BookManager::getBookByName(string& name)
{
	for (auto it = bookList.begin(); it != bookList.end(); it++) {
		if (it->first == name)
			return it->second;
	}
	return nullptr; 
}

void BookManager::borrow(IBook* book, string user_id) {
	//todo：如果该书的库存为0，归还三日内不能重复借
	system_clock::time_point now = system_clock::now();
	::now = now;
	my_sleep(3);
	time_t tt = system_clock::to_time_t(now);
	cout << user_id << " borrows " << book->name << " on " << ctime(&tt) << endl;
}

void BookManager::replace(IBook* book, string user_id) {
	system_clock::time_point now = system_clock::now();
	time_t tt = system_clock::to_time_t(now);
	cout << user_id << " replaces " << book->name << " on " << ctime(&tt) << endl;
}
