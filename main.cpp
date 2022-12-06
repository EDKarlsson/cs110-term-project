// CS 110 - Term Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "util.h"
#include "Library.h"
#include "Person.h"
#include "Book.h"
#include "Menu.h"
#include "ComputerBook.h"
#include "Novel.h"
#include "ChildrenBook.h"
#include <iostream>

int main() {
    bool exit = false;
    MenuOption choice;
    PersonNode *person[2] = {nullptr, nullptr};
    PersonNode* personNode = nullptr;
    BookNode *library[3] = {nullptr, nullptr, nullptr};
    BookNode *bookNode = nullptr;
    std::string bookTitle;
    ComputerBook *computerBook;
    Novel *novel;
    ChildrenBook *childrenBook;
    int bookCode;
    int personId;

    initializeLibrary(library);
    initializePeople(person);

    while (!exit) {
        printMenu();
        choice = getUserMainMenuSelection();
        switch (choice) {
            case MENU_SEARCH:
                std::cout << "Enter code  : ";
                std::cin >> bookCode;
                std::cin.ignore();
                std::cout << "Enter title : ";
                getline(std::cin, bookTitle);
                bookNode = searchBook(library, bookCode, bookTitle);
                if (bookNode != nullptr) {
                    std::cout << bookNode->book->getBookTitle() << " (" << bookNode->book->getCode() << ") exists."
                              << std::endl;
                    std::cout << "category : " << getBookTypeString(bookCode) << std::endl;
                    switch (getBookType(bookCode)) {
                        case BOOK_TYPE_CHILDREN:
                            childrenBook = (ChildrenBook *) bookNode->book;
                            std::cout << "age : " << childrenBook->getAge() << std::endl;
                            break;
                        case BOOK_TYPE_COMPUTER:
                            computerBook = (ComputerBook *) bookNode->book;
                            std::cout << "publisher : " << computerBook->getPublisher() << std::endl;
                            break;
                        case BOOK_TYPE_NOVEL:
                            novel = (Novel *) bookNode->book;
                            std::cout << "publish date : " << novel->getPublishDate() << std::endl;
                            break;
                        case BOOK_TYPE_ERROR:
                            std::cout << "incorrect code for book type" << std::endl;
                    }
                    std::cout << bookNode->book->getAvailable() << " available, "
                              << bookNode->book->getRented() << " rented" << std::endl << std::endl;
                } else {
                    std::cout << bookTitle << " (" << bookCode << ") not found!" << std::endl;
                }
                break;
            case MENU_RENT:
                std::cout << "Enter your id    : ";
                std::cin >> personId;
                std::cin.ignore();
                std::cout << "Enter book title : ";
                getline(std::cin, bookTitle);
                personNode = getPerson(person, personId);
                bookNode = searchBookByTitle(library, bookTitle);
                rentBook(personNode, bookNode);
                break;
            case MENU_RETURN:
                break;
            case MENU_SHOW_MY_INFO:
                break;
            case MENU_SHOW_ALL_BOOKS:
                break;
            case MENU_EXIT:
                exit = true;
                break;
            case MENU_ERROR:
                break;
        }
    }

    return 0;
}
