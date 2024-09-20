#include <iostream>
#include <thread>
#include <mysqlx/xdevapi.h>
#include <mysql/jdbc.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include "database-utilities/DatabaseConnection.h"
#include "interface/WelcomeScreen.h"

using namespace std;

int main() {

    bool isRunning = true;
    while (isRunning) {
        isRunning = false;
    }

    try {

        auto *databaseConnection = new DatabaseConnection();
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
            sql::PreparedStatement *pstmt = databaseConnection->getConnection()->prepareStatement("SELECT * FROM users WHERE email = ? AND password = ?");
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
