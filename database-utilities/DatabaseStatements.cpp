//
// Created by cjpra on 20/09/2024.
//

#include "DatabaseStatements.h"

#include <jdbc/cppconn/prepared_statement.h>

DatabaseStatements::DatabaseStatements(sql::mysql::MySQL_Connection *connection) {
    this->connection = connection;
}
std::unique_ptr<sql::PreparedStatement> DatabaseStatements::createStatement(const std::string &statement, const std::vector<std::string> &wildcardValues) {
    std::unique_ptr<sql::PreparedStatement> stmt(connection->prepareStatement(statement));
    int wildcards = std::count(statement.begin(), statement.end(), '?');
    if(wildcardValues.size() != wildcards) {
        throw std::invalid_argument("wildcard values do not match amount of wildcards");
    }
    for(int i= 1; i <= wildcardValues.size(); i++) {
        stmt->setString(i, wildcardValues[i-1]);
    }
    return stmt;
}


