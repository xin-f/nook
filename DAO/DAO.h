#ifndef __DA_H___
#define __DA_H___


#ifdef _HAS_STD_BYTE
#undef _HAS_STD_BYTE
#endif
#define _HAS_STD_BYTE 0


#include "sqlite3.h"
//#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

class DAO
{
private:
	DAO(sqlite3* p);
	DAO(const DAO&) = delete;
	DAO& operator=(const DAO&) = delete;

	sqlite3* db;
	bool open_db(std::string path = { "nook.db" });
	void close_db();
	static int callback_create(void* data, int argc, char** argv, char** azColName);
	static int callback_insert(void* data, int argc, char** argv, char** azColName);
	int callback_select(void* data, int argc, char** argv, char** azColName);
	int callback_update(void* data, int argc, char** argv, char** azColName);
	int callback_delete(void* data, int argc, char** argv, char** azColName);
	//static DAO* ins;

public:
	static DAO* getInstance();
	bool insert(std::string name, std::string aut, std::string table = "BOOK");

	~DAO();
};

#endif // !__DA_H___
