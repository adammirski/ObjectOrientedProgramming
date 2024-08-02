/*
 * functiions.cpp
 *
 *  Created on: Apr 29, 2024
 *      Author: adammirski
 */


/*********************************************************
*
*   Intro to OOP
*
*---------------------------------------------------------
*
* This program demonstrates the principles of Object-Oriented Programming (OOP)
* through a simulation of animal management in a farm setting. It features:
* - Dynamic object initialization for animals.
* - Implementation of class methods to modify and access animal attributes.
* - Use of encapsulation to safeguard the integrity of animal data.
* - A menu-driven interface that handles user interactions effectively.
* - Demonstrates the utility of constructors, destructors, and friend functions.
* - Efficient input validation and error handling for user inputs.
*
* It serves as an educational tool for understanding basic OOP concepts
* like classes, objects, and member functions.
*
**********************************************************/

#include "header.h"

/**
 * Displays the main menu and prompts for user interaction based on whether the animals
 * have been initialized or not.
 * @param initialized Indicates if the animal objects have been initialized.
 */
void showMainMenu(bool initialized) {
    cout << (initialized ? "\n1 - Initialize Animals\n2 - Change Age\n3 - Change Value\n4 - Display\n" : "1 - Initialize Animals\n") << "0 - Exit\nEnter selection: ";
}

/**
 * Initializes three animal objects with predefined values for demonstration.
 * @param fluffy Reference to an Animal object representing Fluffy.
 * @param maa Reference to an Animal object representing Maa.
 * @param babe Reference to an Animal object representing Babe.
 */
void initializeAnimals(Animal& fluffy, Animal& maa, Animal& babe) {
    fluffy.SetInitialValues("Fluffy", "Sheep", 1, 15000.00);
    maa.SetInitialValues("Maa", "Sheep", 3, 16520.35);
    babe.SetInitialValues("Babe", "Pig", 2, 10240.67);
    cout << "\nInitializing Fluffy, Maa, & Babe...\n";
}

/**
 * Displays the details of the animals in a formatted table.
 * @param fluffy Animal object representing Fluffy.
 * @param maa Animal object representing Maa.
 * @param babe Animal object representing Babe.
 */
void displayAnimals(const Animal& fluffy, const Animal& maa, const Animal& babe) {
    cout << "\nANIMAL     NAME           AGE    VALUE\n";
    cout << "---------- -------------- --- -----------\n";
    fluffy.Display();
    maa.Display();
    babe.Display();
}

/**
 * Provides an interface for changing the age of a specified animal.
 * @param fluffy Reference to Animal object representing Fluffy.
 * @param maa Reference to Animal object representing Maa.
 * @param babe Reference to Animal object representing Babe.
 */
void changeAnimalAge(Animal& fluffy, Animal& maa, Animal& babe) {
    cout << "CHANGE AGE:\n1 - Fluffy\n2 - Maa\n3 - Babe\nSelect the animal you'd like to change: ";
    int selection = getIntegerInput("", 1, 3);
    Animal* selectedAnimal = nullptr;
    switch (selection) {
        case 1: selectedAnimal = &fluffy; break;
        case 2: selectedAnimal = &maa; break;
        case 3: selectedAnimal = &babe; break;
        default:
            cout << "\n**** Invalid selection ****\n";
            return;
    }
    int newAge = getIntegerInput("NEW AGE: ", 1, 10);
    selectedAnimal->ChangeAge(newAge);
    cout << "\nChanging " << selectedAnimal->GetName() << "'s age to " << newAge << " ...\n";
}

/**
 * Provides an interface for changing the value of a specified animal.
 * @param fluffy Reference to Animal object representing Fluffy.
 * @param maa Reference to Animal object representing Maa.
 * @param babe Reference to Animal object representing Babe.
 */
void changeAnimalValue(Animal& fluffy, Animal& maa, Animal& babe) {
    cout << "CHANGE VALUE:\n1 - Fluffy\n2 - Maa\n3 - Babe\nSelect the animal you'd like to change: ";
    int selection = getIntegerInput("", 1, 3);
    Animal* selectedAnimal = nullptr;
    switch (selection) {
        case 1: selectedAnimal = &fluffy; break;
        case 2: selectedAnimal = &maa; break;
        case 3: selectedAnimal = &babe; break;
        default:
            cout << "\n**** Invalid selection ****\n";
            return;
    }
    float newValue = getFloatInput("NEW VALUE: ");
    selectedAnimal->ChangeValue(newValue);
    cout << "Changing " << selectedAnimal->GetName() << "'s value to " << newValue << " ...\n";
}

/**
 * Validates and retrieves an integer input from the user within a specified range.
 * @param prompt The message displayed to the user.
 * @param min The minimum acceptable input value.
 * @param max The maximum acceptable input value.
 * @return The validated integer input from the user.
 */
int getIntegerInput(const string& prompt, int min, int max) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail() || input < min || input > max) {
            cout << "\n**** Invalid entry ****\n";
            cout << "**** Please input a number between " << min << " and " << max << " ****\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        return input;
    }
}

/**
 * Validates and retrieves a floating-point input from the user within a specified range.
 * @param prompt The message displayed to the user.
 * @return The validated floating-point input from the user.
 */
float getFloatInput(const string& prompt) {
    float input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail() || input < 0 || input > 400000) {
            cout << "\n**** Please input a number between 0 and 400000 ****\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        return input;
    }
}

/**
 * Retrieves a Y/N confirmation from the user.
 * @param message The confirmation message displayed to the user.
 * @return The user's response as a character ('Y' or 'N').
 */
char getConfirmation(const string& message) {
    char response;
    while (true) {
        cout << message;
        cin >> response;
        response = toupper(response);
        if (response == 'Y' || response == 'N') {
            return response;
        } else {
            cout << "\n**** " << response << " is an invalid entry ****\n";
            cout << "**** Please input Y or N ****\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

/**
 * Prints a standardized heading to an output stream.
 * @param os Reference to the output stream (can be an ofstream or cout).
 */
void printHeading(ostream& os) {

    const char PROGRAMMER[30] = "Adam Mirski";
    const char CLASS[5] = "CS1B";
    const char SECTION[25] = "MW: 7:30p - 10:00p";
    const char LAB_NUM[5] = "12";
    const char LAB_NAME[50] = "Intro to OOP";

    os << left;
    os << "**************************************************";
    os << "\n* PROGRAMMED BY : " << PROGRAMMER;
    os << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
    os << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
    os << "\n* " << "LAB#" << setw(10) << LAB_NUM << ": " << LAB_NAME;
    os << "\n**************************************************\n\n";
    os << right;
}
