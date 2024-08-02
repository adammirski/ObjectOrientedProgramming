
/**********************************************************
* AUTHOR 		: Adam Mirski
* LAB: # 12   		: Intro to OOP
* CLASS 		: CS1B
* SECTION 		: Mw: 7:30p - 10:00p
* DUE DATE 		: Apr 29, 2024
**********************************************************/

/*********************************************************
*
*   OOP
*
*---------------------------------------------------------
*
* This program introduces the basic principles of Object-Oriented Programming (OOP)
* by managing a database of animal records for a farm. It features:
* - Creating and initializing objects dynamically.
* - Implementing class methods to manipulate object properties.
* - Using encapsulation to protect data integrity.
* - Providing a simple menu-driven interface for user interactions.
* - Demonstrating the use of constructors and destructors.
* - Efficient management of memory and error handling..
*
**********************************************************/

#include "header.h"

int main() {
	printHeading(cout);
    Animal fluffy, maa, babe;
    bool initialized = false;
    int choice;

    while (true) {
        showMainMenu(initialized);
        cin >> choice;
        if (cin.fail() || (initialized ? (choice < 0 || choice > 4) : (choice < 0 || choice > 1))) {
            cout << "\n**** Invalid entry ****\n";
            cout << "**** Please input a number between " << (initialized ? "0 and 4" : "0 and 1") << " ****\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 0:
                return 0;
            case 1:
                if (initialized) {
                    char confirm = getConfirmation("\nAre you sure you want to reinitialize (Y/N)? ");
                    if (confirm == 'Y') {
                        initializeAnimals(fluffy, maa, babe);
                    } else {
                        cout << "\nAnimals have not been re-initialized!\n";
                    }
                } else {
                    initializeAnimals(fluffy, maa, babe);
                    initialized = true;
                }
                break;
            case 2:
                if (initialized) {
                    changeAnimalAge(fluffy, maa, babe);
                }
                break;
            case 3:
                if (initialized) {
                    changeAnimalValue(fluffy, maa, babe);
                }
                break;
            case 4:
                if (initialized) {
                    displayAnimals(fluffy, maa, babe);
                }
                break;
        }
    }
}

