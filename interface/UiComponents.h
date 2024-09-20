//
// Created by cjpra on 20/09/2024.
//

#ifndef UICOMPONENTS_H
#define UICOMPONENTS_H
#include <string>


class UiComponents {

    std::string topLine       {" ________________________________________________________________________ \n"};
    std::string appName       {"|                  CRSG command line banking application                 |\n"};
    std::string optionLine    {"|                      Please select an option below                     |\n"};
    std::string invalidOpt    {"|                    ERR: Please select a valid option                   |\n"};
    std::string connectionLine{"|                Connecting to host: tcp://127.0.0.1:3306                |\n"};
    std::string connected     {"|                                 Connected!                             |\n"};
    std::string blankLine     {"|                                                                        |\n"};
    std::string bottomLine    {"|________________________________________________________________________|\n"};
    std::string loginLine     {"|                                  Login(L)                              |\n"};
    std::string registerLine  {"|                                Register(R)                             |\n"};
    std::string loginCreds    {"|                   Please enter your email and password                 |\n"};

public:
    UiComponents() =default;

    std::string getTopLine() const {
        return topLine;
    }
    std::string getAppName() const {
        return appName;
    }
    std::string getOptionLine() const {
        return optionLine;
    }
    std::string getBlankLine() const {
        return blankLine;
    }
    std::string getBottomLine() const {
        return bottomLine;
    }
    std::string getLoginLine() const {
        return loginLine;
    }
    std::string getRegisterLine() const {
        return registerLine;
    }
    std::string getConnectionLine() const {
        return connectionLine;
    }
    std::string getConnected() const {
        return connected;
    }
    std::string getInvalidOption() const {
        return invalidOpt;
    }

    std::string getLoginCreds() const {
        return loginCreds;
    }

    ~UiComponents() = default;

};

#endif //UICOMPONENTS_H
