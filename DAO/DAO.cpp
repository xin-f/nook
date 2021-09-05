#include "DAO.h"
#include "../basic/basics.h"


using namespace std;



DAO::DAO(sqlite3* p) :db(p) {
	if (open_db()) {
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
		rc = sqlite3_open(path.c_str(), &db);
		if (rc) {
			info("Can't create database: " + string(sqlite3_errmsg(db)));
			return false;
		}
		char* zErrMsg = nullptr;
		char* sql = "CREATE TABLE BOOK("  \
			"NAME           TEXT    NOT NULL," \
			"ID             INTEGER  DEFAULT 0,"\
			"AUTHOR         TEXT,"\
			"OWNER          TEXT,"\
			"DATE_OUT       INTEGER,"\
			"DATE_IN        INTEGER,"\
			"AVAILABLITY    INTEGER,"\
			"PRIMARY KEY (NAME, ID),"\
			"UNIQUE (NAME, ID));";
		rc = sqlite3_exec(db, sql, DAO::callback_create, nullptr, &zErrMsg);
		if (rc != SQLITE_OK) {
			info("Create Table error: " + string(zErrMsg));
			sqlite3_free(zErrMsg);
			return false;
		}
		else {
			info("Table created successfully.");
			return true;
		}
	}
	else {
		rc = sqlite3_open(path.c_str(), &db);
		if (rc) {
			info("Can't open database: " + string(sqlite3_errmsg(db)));
			return false;
		}
		else {
			info("Opened database successfully.");
			return true;
		}
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
		info("Insert Record error: " + string(zErrMsg) + ", try again.");
		if (string(zErrMsg).find("UNIQUE") != std::string::npos) {
			string s = "select count(*) from book where name glob '" + name + "'";
			const char* sql = s.c_str();
			int rc = sqlite3_exec(db, sql, callback_select_count, 0, &zErrMsg);
			s = "INSERT INTO " + table + " (NAME, AUTHOR, ID) VALUES ('" + name + "', '" + aut + "', " 
				+ string(1, count + '0') + "); ";
			sql = s.c_str();
			rc = sqlite3_exec(db, sql, callback_insert, 0, &zErrMsg);
			if (rc != SQLITE_OK) {
				info("Insert Record error: " + string(zErrMsg));
			}
			else {
				info("Insert Record successfully: " + name);
			}
		}
		else {
			info("Insert Record error: " + string(zErrMsg));
		}
		sqlite3_free(zErrMsg);
	}
	else {
		info("Recored created successfully.");
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

int DAO::callback_select_count(void* data, int argc, char** argv, char** azColName)
{
	return count = *argv[0] - '0';
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
int DAO::count = 0;
