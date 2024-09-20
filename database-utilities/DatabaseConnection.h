//
// Created by cjpra on 20/09/2024.
//

#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H
#include <string>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/connection.h>


class DatabaseConnection {

    sql::mysql::MySQL_Driver *driver;
    std::unique_ptr<sql::Connection> connection;


    public:
    DatabaseConnection();
    [[nodiscard]] sql::Connection* getConnection() const;
    ~DatabaseConnection();
};



#endif //DATABASECONNECTION_H
