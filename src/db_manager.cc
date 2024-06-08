/*
 * Filename: db_manager.cc
 * Created on: June  7, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "db_manager.h"

DBManager::DBManager(const std::string& dbName) noexcept
{
    bool rc = sqlite3_open(dbName.c_str(), &db);
    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        db = nullptr;
    }
    else
    {
        std::cout << "Opened database successfully" << std::endl;
    }
}
