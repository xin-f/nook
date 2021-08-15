#ifndef __OWNER_H__
#define __OWNER_H__

#include "basics.h"
#include <vector>
//#include "IBook.h"

class IBook;
class Owner
{
private:

public:
	vector<IBook*> borrowed_list;
	string email;
	string name;
};



#endif // !__OWNER_H__

