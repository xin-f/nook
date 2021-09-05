#include "BookManager.h"
#include "../DAO/DAO.h"

using namespace std;

void BookManager::addNewBook(string name, string aut = nullptr)
{
	IBook* book = new IBook(&name, &aut);
	//todo: 是否有必要把book实例作为blob放到数据库里？
	DAO::getInstance()->insert(name, aut);
}

void BookManager::deleteBook(string* name)
{
}

IBook* BookManager::getBookByName(string& name)
{
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
