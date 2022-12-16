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
#include <filesystem>

int menu();
void openEntry();
void createEntry();

int main()
{
    // Display the menu and get the user's choice until the user chooses to exit.
    while(true)
    {   
        int choice = menu();
        switch (choice)
        {
        case 1:
            std::cout << std::endl << "You chose to open an entry" << std::endl;
            openEntry();
            break;

        case 2:
            std::cout << std::endl << "You chose to create an entry" << std::endl;
            createEntry();
            break;
        
        case 0:
            std::cout << std::endl << "You chose to exit. " << std::endl;
            exit(0);

        default:
            break;
        }
    }

    return 0;
}

/**
 * @brief This function displays the menu and returns the user's choice.
 * 
 * @return int 
 */
int menu()
{
    int choice;
    system("cls");
    std::cout << std::endl<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "This is a diary program." << std::endl;
    std::cout << "Open an entry (1)" << std::endl;
    std::cout << "Create a new entry (2)" << std::endl;
    std::cout << "Exit (0)" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;

    std::cin >> choice;

    return choice;
}

/**
 * @brief This function opens a diary entry.
 * 
 */
void openEntry()
{
    // Print the list of files in the current directory.
    std::string path = std::filesystem::current_path().string();
    for (const auto & entry : std::filesystem::directory_iterator(path))
        std::cout << entry.path() << std::endl;
    std::string filename;

    // Prompt the user to enter the name of the file they want to open.
    std::cout << "Enter the name of the file you want to open: ";
    std::cin >> filename;

    std::ifstream file;
    file.open(filename);
    system("cls");

    if (file.is_open())
    {
        std::cout << "Here are the contents of the file: " << std::endl;

        std::string line;
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }

    }
    else
    {
        std::cout << "File not found." << std::endl;
    }
    file.close();
    
    system("pause");
    system("cls");

}

/**
 * @brief This function creates a diary entry object and save it to a file.
 * 
 */
void createEntry(){
    std::string filename;
    
    system("cls");
    std::cout << "Enter the name of the file you want to create: ";
    std::cin >> filename;

    std::ofstream file;
    file.open(filename);

    if (file.is_open())
    {
        std::string line;
        std::cout << "Enter the contents of the file. Enter \"~END~\" to stop writing to the file:\n";
        do{
            file << line << std::endl;
            std::getline(std::cin, line); 
        }while(line != "~END~");
    }
    else
    {
        std::cout << "File not found." << std::endl;
    }
    file.close();

    system("pause");
    system("cls");
}