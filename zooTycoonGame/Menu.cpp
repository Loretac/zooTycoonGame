/*********************************************************************
 ** Program name: Project 2 - Zoo Tycoon
 ** Author: B. Christopher Loreta
 ** Date: 19 Oct 2017
 ** Description:
 
 This file contains implementation of Menu class member functions.
 *********************************************************************/

#include <iostream>
#include "Menu.hpp"

using std::string;
using std::cout;
using std::endl;

/*********************************************************************
 ** The mainMenu function provides 3 options for the user and runs
 ** through an input validation, returning the value that was input
 ** by the user. Any invalid inputs are declined and correct input
 ** is requested.
 *********************************************************************/
string Menu::mainMenu(string option1,
                      string option2,
                      string option3
                      )
{
    string input;
    cout << option1 << endl;
    cout << option2 << endl;
    cout << option3 << endl;
    cout << "Enter your choice: ";
    getline(std::cin, input);
    
    // Basic input validation
    while (input != "1" &&
           input != "2" &&
           input != "3"
           )
    {
        cout << "Please choose a valid option." << endl;
        getline(std::cin, input);
    }
    
    return input;
}

/*********************************************************************
 This menu function is identical to the one above, but instead takes
 two parameters as the two choices.
 *********************************************************************/
string Menu::mainMenu(string option1,
                      string option2)
{
    string input;
    cout << option1 << endl;
    cout << option2 << endl;
    cout << "Enter your choice: ";
    getline(std::cin, input);
    
    // Basic input validation
    while (input != "1" &&
           input != "2"
           )
    {
        cout << "Please choose a valid option." << endl;
        getline(std::cin, input);
    }
    
    return input;
}
