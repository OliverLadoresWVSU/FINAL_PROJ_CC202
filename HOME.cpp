#include <iostream>
#include <string>
#include <fstream>

int menu();

int main()
{
    int choice = menu();

    switch (choice)
    {
    case 1:
        std::cout << "You chose 1" << std::endl;
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