//
// Created by cjpra on 20/09/2024.
//

#ifndef LOGINSERVICE_H
#define LOGINSERVICE_H
#include <string>


class LoginService {

    std::string email;
    std::string password;

    bool authenticate();
    void enterCredentials();
    void login();

    public:
    LoginService();
    void setEmail(std::string email);
    void setPassword(std::string password);
    std::string getEmail();
    std::string getPassword();

};



#endif //LOGINSERVICE_H
