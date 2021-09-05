#include "BookManager.h"
#include "../DAO/DAO.h"

using namespace std;

void BookManager::addNewBook(string name, string aut = nullptr)
{
	IBook* book = new IBook(&name, &aut);
	//todo: �Ƿ��б�Ҫ��bookʵ����Ϊblob�ŵ����ݿ��
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
	//todo���������Ŀ��Ϊ0���黹�����ڲ����ظ���
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
