//
// Created by cjpra on 20/09/2024.
//

#include "Login.h"

#include <jdbc/mysql_connection.h>

std::string Login::getEmail() {
    return email;
}
std::string Login::getPassword() {
    return password;
}

void Login::setEmail(std::string email) {
    this->email = email;
}

void Login::setPassword(std::string password) {
    this->password = password;
}

bool Login::authenticate() {
    return true;
}

void Login::login() {

}

Login::Login() {

}

Login::~Login() {

}





