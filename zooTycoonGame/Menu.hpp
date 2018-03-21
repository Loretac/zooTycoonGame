/*********************************************************************
 ** Program name: Project 2 - Zoo Tycoon
 ** Author: B. Christopher Loreta
 ** Date: 19 Oct 2017
 ** Description:
 
 This file contains the member variables and function prototypes for
 class Menu.
 *********************************************************************/

#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>
#include "Turtle.hpp"

using std::string;

class Menu
{
private:
    
public:
    string mainMenu(string, string, string); // Options: 3
    string mainMenu(string, string); // Options: 2
    
};

#endif /* Menu_hpp */
