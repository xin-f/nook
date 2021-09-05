#ifndef __BOOKMANAGER__
#define __BOOKMANAGER__

#include "IBook.h"
//#include <map>
#ifdef _HAS_STD_BYTE
#undef _HAS_STD_BYTE
#endif
#define _HAS_STD_BYTE 0

class BookManager
{
private:
	BookManager() = default;
	BookManager(const BookManager& bm) = delete;

//	multimap <std::string&, IBook*> bookList;
	IBook* getBookByName(std::string& name);
  
public:
	static BookManager* getInstance() {
		static BookManager bm;
		return &bm;
	}

	void addNewBook(std::string name, std::string author);
	void deleteBook(std::string*);
	void borrow(IBook* , std::string ) ;
	void replace(IBook* , std::string ) ;

	void notify() {
		//send mail as a reminder
	}

};

#endif // !__BOOKMANAGER__
