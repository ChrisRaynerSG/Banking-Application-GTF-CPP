#include <iostream>
#include <thread>
#include <mysqlx/xdevapi.h>
#include <mysql/jdbc.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include "interface/WelcomeScreen.h"

using namespace std;

int main() {

    try {
        boost::property_tree::ptree pt;
        read_ini("config/DatabaseProperties.ini", pt);

        const auto host = pt.get<std::string>("database.url");
        const auto user = pt.get<std::string>("database.user");
        const auto password = pt.get<std::string>("database.password");

        cout << WelcomeScreen::getConnectionScreen("connection");

        sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();

        if (!driver) {
            cerr << "Error: Failed to get MySQL driver instance." << endl;
            return 1;
        }

        std::unique_ptr<sql::Connection> con(driver->connect(host, user, password));

        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << WelcomeScreen::getConnectionScreen("connected");
        con->setSchema("banking_app");
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << WelcomeScreen::getWelcomeScreen("init");

        string selection;
        string  email;
        string loginPassword;

        cout << "Please select: ";
        cin >> selection;
        while(selection != "L" && selection != "R") {
            cout << WelcomeScreen::getWelcomeScreen("inval");
            cout << "Please select: ";
            cin >> selection;
        }
        if(selection == "L") {
            cout << WelcomeScreen::getWelcomeScreen("loginCred");
            cout << "Email address: ";
            cin >>  email;
            cout << "Password: ";
            cin >> loginPassword;
            sql::PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM users WHERE email = ? AND password = ?");
            for(int i=1; i<3;i++) {
                pstmt->setString(i, email);
                pstmt->setString(i, loginPassword);
            }
            std::unique_ptr<sql::ResultSet> resLogin(pstmt->executeQuery());
            while (resLogin->next()) {
                string storedPassword = resLogin->getString("password");
                if(loginPassword == storedPassword) {
                    cout << "Welcome " << resLogin->getString("first_name") << " " << resLogin->getString("last_name") << "! What would you like to do today?"<< endl;
                }
            }
        }
        else if(selection == "R") {

        }
        return 0;
    }
    catch (const boost::property_tree::ini_parser_error &err) {
        cerr << "Error reading INI file: " << err.what() << endl;
        return 1;
    }
    catch (const sql::SQLException &err) {
        cerr << "SQL error: " << err.what() << endl;
        return 1;
    }
    catch (const std::exception &err) {
        cerr << "Error: " << err.what() << endl;
        return 1;
    }

}
