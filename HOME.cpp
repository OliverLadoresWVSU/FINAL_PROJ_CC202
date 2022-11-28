/*
Program Title: CLI Diary Application
Submitted by: Oliver Ladores
              Lemmuel Dave Dañosos
Program Description: This program is a CLI Diary Application that allows the
                     user to create, read, update, and delete entries.
*/

#include <iostream>
#include <string>
#include <fstream>

int menu();
void openEntry();
void createEntry();

int main()
{
    int choice = menu();

    switch (choice)
    {
    case 1:
        std::cout << "You chose to open an entry" << std::endl;
        openEntry();
        break;

    case 2:
        std::cout << "You chose to create an entry" << std::endl;
        createEntry();
        break;
    
    case 0:
        std::cout << "You chose to exit. " << std::endl;
        exit(0);

    default:
        break;
    }

    return 0;
}

int menu()
{
    int choice;
    std::cout << "This is a diary program." << std::endl;
    std::cout << "Open an entry (1)" << std::endl;
    std::cout << "Create a new entry (2)" << std::endl;
    std::cout << "Exit (0)" << std::endl;

    std::cin >> choice;

    return choice;
}