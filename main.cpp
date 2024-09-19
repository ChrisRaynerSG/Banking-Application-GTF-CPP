#include <iostream>
#include <mysqlx/xdevapi.h>
#include <mysql/jdbc.h>
#include <jdbc/cppconn/exception.h>

using namespace std;


int main() {

    const string host = "tcp://127.0.0.1:3306";
    const string user = "root";
    const string password = "root";

    cout << "Connecting to host: "<< host << endl;

    try {

        // mysqlx::Session session("localhost", 33060, "root", "root");
        //
        // cout << "Connected" << endl;
        //
        // mysqlx::Schema schema = session.getSchema("banking_app");
        //
        // schema.getTable()

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
    catch (const mysqlx::Error &err) {
        cout << "ERROR: " << err <<endl;
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
