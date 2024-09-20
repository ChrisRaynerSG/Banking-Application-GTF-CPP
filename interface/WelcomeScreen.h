//
// Created by cjpra on 20/09/2024.
//

#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H
#include <string>
#include <cstdlib>

#include "UiComponents.h"

class WelcomeScreen{

public:
    WelcomeScreen();

    std::string static getWelcomeScreen(std::string step) {
        system("cls");
        const auto *ui_components = new UiComponents();
        std::string blankSpace;
        std::string welcomeScreenTop;
        std::string bottomLine = ui_components->getLoginLine() + ui_components->getRegisterLine() + ui_components->getBottomLine();
        for(int i=0; i<5; i++) {
            blankSpace += ui_components->getBlankLine();
        }
        if(step == "init") {
            welcomeScreenTop = ui_components->getTopLine() + ui_components->getAppName() + ui_components->getOptionLine();
        }

        else if(step == "inval") {
            welcomeScreenTop = ui_components->getTopLine() + ui_components->getAppName() + ui_components->getInvalidOption();
        }

        else if(step == "loginCred") {
            welcomeScreenTop = ui_components->getTopLine() + ui_components->getAppName() + ui_components->getLoginCreds();
            blankSpace += ui_components->getBlankLine() + ui_components->getBlankLine();
            bottomLine = ui_components->getBottomLine();
        }
        else if(step == "register") {

        }

        return welcomeScreenTop + blankSpace + bottomLine;
    }

    std::string static getConnectionScreen(std::string step) {
        const auto *ui_components = new UiComponents();
        std::string blankSpace;
        std::string welcomeScreenTop;

        for(int i=0; i<7; i++) {
            blankSpace += ui_components->getBlankLine();
        }
        if(step == "connection") {
            welcomeScreenTop = ui_components->getTopLine() + ui_components->getAppName() + ui_components->getConnectionLine();
        }
        else {
            system("cls");
            welcomeScreenTop = ui_components->getTopLine() + ui_components->getAppName() + ui_components->getConnected();
        }

        return welcomeScreenTop + blankSpace + ui_components->getBottomLine();
    }
};

#endif //WELCOMESCREEN_H
