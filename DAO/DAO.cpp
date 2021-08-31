#include "DAO.h"
#include "../basic/basics.h"


using namespace std;



DAO::DAO(sqlite3* p) :db(p) {
	if (open_db()) {
		char* zErrMsg = nullptr;
		char* sql = "CREATE TABLE BOOK("  \
			//"ID INT PRIMARY KEY     NOT NULL," 
			"NAME           TEXT    NOT NULL," \
			"AUTHOR         TEXT," \
			"OWNER          TEXT," \
			"DATE_OUT       INTEGER," \
			"DATE_IN        INTEGER ,"\
			"AVAILABLITY    INTEGER );";
		int rc = sqlite3_exec(db, sql, DAO::callback_create, nullptr, &zErrMsg);
		if (rc != SQLITE_OK) {
			info("Create Table error: " + string(zErrMsg));
			sqlite3_free(zErrMsg);
		}
		else {
			info("Table created successfully\n");
		}
	}
}

DAO* DAO::getInstance()
{
	static DAO d{ nullptr };
	return &d;
}

bool DAO::open_db(string path) {
	int rc;
	fs::file_status s = fs::file_status{};
	fs::path p{ path };
	if ((fs::status_known(s) ? fs::exists(s) : fs::exists(p)) == false) {
		info("Database file does not exist. If this is not the case, check the data base file path.");
	}
	rc = sqlite3_open(path.c_str(), &db);
	if (rc) {
		info("Can't open database: " + string(sqlite3_errmsg(db)));
		return false;
	}
	else {
		info("Opened database successfully\n");
		return true;
	}
}

void DAO::close_db() {
	sqlite3_close(db);
}

bool DAO::insert(string name, string aut, string table)
{
	char* zErrMsg = nullptr;
	string s = "INSERT INTO " + table + " (NAME, AUTHOR) VALUES ('" + name + "', '" + aut + "');";
	const char* sql = s.c_str();
	int rc = sqlite3_exec(db, sql, callback_insert, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		info("Insert Record error: " + string(zErrMsg));
		sqlite3_free(zErrMsg);
	}
	else {
		info("Recored created successfully\n");
		return true;
	}
}

int DAO::callback_create(void* data, int argc, char** argv, char** azColName)
{
	return 0;
}

int DAO::callback_insert(void* data, int argc, char** argv, char** azColName)
{
	return 0;
}

int DAO::callback_select(void* data, int argc, char** argv, char** azColName)
{
	return 0;
}

int DAO::callback_update(void* data, int argc, char** argv, char** azColName)
{
	return 0;
}

int DAO::callback_delete(void* data, int argc, char** argv, char** azColName)
{
	return 0;
}

DAO::~DAO()
{
	close_db();
	db = nullptr;
}


//DAO* DAO::ins = nullptr;
