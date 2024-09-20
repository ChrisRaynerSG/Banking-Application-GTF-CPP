//
// Created by cjpra on 20/09/2024.
//

#ifndef USERDTO_H
#define USERDTO_H
#include <string>


class UserDto {

  int userId;
  std::string firstName;
  std::string lastName;
  std::string email;
  std::string password;
  std::string address;
  std::string dob;

  public:
    //Constructor
    UserDto(int userId, const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& password, const std::string& address);

    int getUserId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmail() const;
    std::string getPassword() const;
    std::string getAddress() const;
    std::string getDob() const;
    ~UserDto();
};



#endif //USERDTO_H
