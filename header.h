/*
 * header.h
 *
 *  Created on: Apr 29, 2024
 *      Author: adammirski
 */
/**********************************************************
* AUTHOR 		: Adam Mirski
* LAB: # 12   	: Intro to OOP
* CLASS 		: CS1B
* SECTION 		: Mw: 7:30p - 10:00p
* DUE DATE 		: Apr 29, 2024
**********************************************************/

/*********************************************************
*
*   Intro to OOP
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


#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**
 * class Animal
 * Handles information about Farmer Pete's animals.
 */

class Animal {
public:
    Animal() : name(""), type(""), age(0), value(0.0) {} // Default constructor
    ~Animal() {} // Destructor

    void SetInitialValues(string aName, string aType, int aAge, float aValue) { // Sets initial properties of the animal
        name = aName;
        type = aType;
        age = aAge;
        value = aValue;
    }

    void ChangeAge(int aAge) { // Changes the animal's age
        age = aAge;
    }

    void ChangeValue(float aValue) { // Changes the animal's value
        value = aValue;
    }

    void Display() const { // Displays animal information in a formatted manner
        cout << left << setw(11) << type << setw(16) << name
                  << setw(5) << age << fixed << setprecision(2) << right << setw(9) << value << endl;
    }

    string GetName() const { return name; } // Returns the animal's name
    string GetType() const { return type; } // Returns the animal's type
    int GetAge() const { return age; } // Returns the animal's age
    float GetValue() const { return value; } // Returns the animal's value

private:
    string name; // Name of the animal
    string type; // Type or species of the animal
    int age; // Age of the animal in years
    float value; // Monetary value of the animal
};

// Function prototypes
void initializeAnimals(Animal& fluffy, Animal& maa, Animal& babe); // Initializes the static animal instances
void displayAnimals(const Animal& fluffy, const Animal& maa, const Animal& babe); // Displays all animals in a table format
void changeAnimalAge(Animal& fluffy, Animal& maa, Animal& babe); // Interface for changing the age of a specified animal
void changeAnimalValue(Animal& fluffy, Animal& maa, Animal& babe); // Interface for changing the value of a specified animal
int getIntegerInput(const string& prompt, int min, int max); // Validates integer input within a specified range
float getFloatInput(const string& prompt); // Validates floating-point input within a specified range
void showMainMenu(bool initialized); // Displays the main menu and manages application flow
char getConfirmation(const string& message); // Gets Y/N confirmation from the user

void printHeading(ostream& os);




#endif /* HEADER_H_ */
