//
// Created by cjpra on 20/09/2024.
//

#ifndef LOGIN_H
#define LOGIN_H
#include <string>


class Login {

    std::string email;
    std::string password;

    public:

    Login();
    std::string getEmail();
    std::string getPassword();
    void setEmail(std::string email);
    void setPassword(std::string password);
    bool authenticate();
    void login();
    ~Login();
};



#endif //LOGIN_H
