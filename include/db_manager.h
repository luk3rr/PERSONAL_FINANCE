/*
 * Filename: db_manager.h
 * Created on: June  7, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef DB_MANAGER_H_
#define DB_MANAGER_H_

#include <sqlite3.h>
#include <string>
#include <iostream>

class DBManager
{
    private:
        sqlite3 *db;

    public:
        /**
         * @brief Construct a new DBManager object
         **/
        DBManager(const std::string& dbName) noexcept;

        /**
         * @brief Default destructor
         **/
        ~DBManager() noexcept;

        /**
         * @brief Execute a SQL command
         *
         * @param sql SQL command to be executed
         * @return bool SQLITE_OK if the command was executed successfully
         **/
        bool Execute(const std::string& sql);
};
#endif // DB_MANAGER_H_
