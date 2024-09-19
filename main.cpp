#include <iostream>
using namespace std;

int main() {

    string blankTile {"|                                                                        |"};
    string selection;
    string  email;
    string password;

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
        cin >> password;
    }
    else if(selection == "R") {

    }
    return 0;
}
