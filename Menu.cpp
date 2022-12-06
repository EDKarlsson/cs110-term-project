//
// Created by dank on 12/6/22.
//

#include "Menu.h"

void printMenu() {
    const int WIDTH = 28;
    std::cout << std::setfill('-') << std::setw(WIDTH) << '-'
              << std::endl << std::setfill(' ');
    std::cout << std::setw(WIDTH / 2 + 2) << "Menu" << std::endl;
    std::cout << std::setfill('-') << std::setw(WIDTH) << '-'
              << std::endl << std::setfill(' ');

    std::cout << "1. Search a book" << std::endl;
    std::cout << "2. Rent a book" << std::endl;
    std::cout << "3. Return a book" << std::endl;
    std::cout << "4. Show my information" << std::endl;
    std::cout << "5. Show all books" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Select (1~6) : ";
}

MenuOption getUserMainMenuSelection() {
    std::string userInput;
    char *pEnd;
    MenuOption choice;

    getline(std::cin, userInput);

    switch (std::strtol(userInput.c_str(), &pEnd, 10)) {
        case 1:
            choice = MENU_SEARCH;
            break;
        case 2:
            choice = MENU_RENT;
            break;
        case 3:
            choice = MENU_RETURN;
            break;
        case 4:
            choice = MENU_SHOW_MY_INFO;
            break;
        case 5:
            choice = MENU_SHOW_ALL_BOOKS;
            break;
        case 6:
            choice = MENU_EXIT;
            break;
        default:
            choice = MENU_ERROR;
            break;
    }
    return choice;
}

