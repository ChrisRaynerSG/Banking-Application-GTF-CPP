//
// Created by cjpra on 20/09/2024.
//

#include "DatabaseConnection.h"

#include <chrono>
#include <thread>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include "../interface/WelcomeScreen.h"

DatabaseConnection::DatabaseConnection() {

    try {
        boost::property_tree::ptree pt;
        read_ini("config/DatabaseProperties.ini", pt);

        const auto host = pt.get<std::string>("database.url");
        const auto user = pt.get<std::string>("database.user");
        const auto password = pt.get<std::string>("database.password");

        std::cout << WelcomeScreen::getConnectionScreen("connection");

        driver = sql::mysql::get_mysql_driver_instance();
        if(!driver) {
            throw std::runtime_error("Could not initialize database connection.");
        }
        connection = std::unique_ptr<sql::Connection>(driver->connect(host, user, password));
        connection->setSchema("banking_app");
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << WelcomeScreen::getConnectionScreen("connected");
    }
    catch (const boost::property_tree::ini_parser_error &err) {
        std::cerr << "Error reading INI file: " << err.what() << std::endl;

    }
    catch (const sql::SQLException &err) {
        std::cerr << "SQL error: " << err.what() << std::endl;
    }
    catch (const std::exception &err) {
        std::cerr << "Error: " << err.what() << std::endl;
    }
}

sql::Connection *DatabaseConnection::getConnection() const {
    return connection.get();
}

DatabaseConnection::~DatabaseConnection() {
    connection->close();
}


