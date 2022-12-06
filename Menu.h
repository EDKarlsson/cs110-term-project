//
// Created by dank on 12/6/22.
//

#pragma once

#include <string>
#include <iostream>
#include <iomanip>

enum MenuOption {
    MENU_SEARCH,
    MENU_RENT,
    MENU_RETURN,
    MENU_SHOW_MY_INFO,
    MENU_SHOW_ALL_BOOKS,
    MENU_ERROR,
    MENU_EXIT
};

void printMenu();
MenuOption getUserMainMenuSelection();
