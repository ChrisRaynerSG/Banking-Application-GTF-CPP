#include <iostream>
#include <mysqlx/xdevapi.h>
#include <mysql/jdbc.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

using namespace std;

int main() {

    try {

        boost::property_tree::ptree pt;
        read_ini("config/DatabaseProperties.ini", pt);

        const auto host = pt.get<std::string>("database.url");
        const auto user = pt.get<std::string>("database.user");
        const auto password = pt.get<std::string>("database.password");

        cout << "Connecting to host: "<< host << endl;

        sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();

        if (!driver) {
            cerr << "Error: Failed to get MySQL driver instance." << endl;
            return 1;
        }

        std::unique_ptr<sql::Connection> con(driver->connect(host, user, password));

        cout << "Connected!" << endl;

        con->setSchema("banking_app");

        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM banks"));

        cout << "Bank ID | Bank Name | Bank Code | Addr1 | Addr2 | Addr3 | City | Postcode |" << endl;

        while (res->next()) {
            cout<< "" <<res->getInt("bank_id");
            cout << "       | " << res->getString("bank_name");
            cout << "  | " << res->getString("bank_code");
            cout << "  | " << res->getString("address1");
            cout << " | " << res->getString("address2");
            cout << " | " << res->getString("address3");
            cout << " | " << res->getString("city");
            cout << " | " << res->getString("postcode") << " |" << endl;
        }
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

    string blankTile {"|                                                                        |"};
    string selection;
    string  email;
    string loginPassword;

    cout << "__________________________________________________________________________" << endl;
    cout << "|                  CRSG command line banking application                 |" << endl;
    cout << "|                      Please select an option below                     |" << endl;
    for(int i=0; i<5; i++) {
        cout << blankTile << endl;
    }
    cout << "|                                 Register                               |" << endl;
    cout << "|                                  Login                                 |" << endl;
    cout << "|________________________________________________________________________|" << endl;
    cin >> selection;
    if(selection == "L") {
        cout << "Email address: " << endl;
        cin >>  email;
        cout << "Password: " << endl;
        cin >> loginPassword;
    }
    else if(selection == "R") {

    }
    return 0;
}
