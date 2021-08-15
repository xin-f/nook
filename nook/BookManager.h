#ifndef __BOOKMANAGER__
#define __BOOKMANAGER__

#include "IBook.h"
#include <map>


class BookManager
{
private:
	BookManager() = default;
	BookManager(const BookManager& bm) = delete;

	multimap <string&, IBook*> bookList;
	IBook* getBookByName(string& name);
  
public:
	static BookManager* getInstance() {
		static BookManager bm;
		return &bm;
	}

	void addNewBook(string *, Owner* o, string*);
	void deleteBook(string*);
	void borrow(IBook* , string ) ;
	void replace(IBook* , string ) ;

	void notify() {
		//send mail as a reminder
	}

};

#endif // !__BOOKMANAGER__
