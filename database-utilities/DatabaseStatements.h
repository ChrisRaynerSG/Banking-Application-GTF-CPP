//
// Created by cjpra on 20/09/2024.
//

#ifndef DATABASESTATEMENTS_H
#define DATABASESTATEMENTS_H
#include <vector>
#include <jdbc/mysql_connection.h>


class DatabaseStatements {
    sql::mysql::MySQL_Connection *connection;

    public:
    DatabaseStatements(sql::mysql::MySQL_Connection *connection);
    std::unique_ptr<sql::PreparedStatement> createStatement(const std::string &statement, const std::vector<std::string> &wildcardValues);
    ~DatabaseStatements();
};



#endif //DATABASESTATEMENTS_H
