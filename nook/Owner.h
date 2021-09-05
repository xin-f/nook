#ifndef __OWNER_H__
#define __OWNER_H__

#include "../basic/basics.h"
#include <vector>
//#include "IBook.h"

class IBook;
class Owner
{
private:

public:
	std::vector<IBook*> borrowed_list;
	std::string email;
	std::string name;
};



#endif // !__OWNER_H__

