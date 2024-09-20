//
// Created by cjpra on 20/09/2024.
//

#include "UserDto.h"

UserDto::UserDto(int userId, const std::string &firstName, const std::string &lastName, const std::string &email, const std::string &password, const std::string &address)
    : userId(userId), firstName(firstName), lastName(lastName), email(email), password(password), address(address){
}

UserDto::~UserDto() = default;

