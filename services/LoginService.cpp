//
// Created by cjpra on 20/09/2024.
//

#include "LoginService.h"
#include "../interface/WelcomeScreen.h"
#include <iostream>

LoginService::LoginService() {
    std::cout << WelcomeScreen::getWelcomeScreen("loginCred");
    enterCredentials();
    if(authenticate()) {
        login();
    }
    else {
        std::cerr << "Invalid credentials" << std::endl;
    }
}

void LoginService::enterCredentials() {
    std::cout << "Email address: ";
    std::cin >>  email;
    std::cout << "Password: ";
    std::cin >> password;
}

std::string LoginService::getEmail() {
    return email;
}

std::string LoginService::getPassword() {
    return password;
}

bool LoginService::authenticate() {
    return true;
}

void LoginService::setEmail(std::string email) {
    this->email = email;
}

void LoginService::setPassword(std::string password) {
    this->password = password;
}

void LoginService::login() {

}






