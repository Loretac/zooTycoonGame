/*********************************************************************
 ** Program name: Project 2 - Zoo Tycoon
 ** Author: B. Christopher Loreta
 ** Date: 19 Oct 2017
 ** Description:
 
 This file contains the member variables and function prototypes for
 class Zoo.
 *********************************************************************/

#ifndef Zoo_hpp
#define Zoo_hpp

#include <iostream>
#include "Menu.hpp"


class Zoo
{
private:
    int bank = 100000;
    int baseFoodCost = 10;
    int numTigers = 0;
    int numPenguins = 0;
    int numTurtles = 0;
    int tigerArrLength = 10;
    int penguinArrLength = 10;
    int turtleArrLength = 10;
    Tiger **tigerArr = new Tiger*[10];
    Penguin **penguinArr = new Penguin*[10];
    Turtle **turtleArr = new Turtle*[10];
    
    
public:
    void play();
    void addTiger(int);
    void addPenguin(int);
    void addTurtle(int);
    void tigerBirth();
    void penguinBirth();
    void turtleBirth();
    void checkTigerArray(int);
    void checkPenguinArray(int);
    void checkTurtleArray(int);
};

#endif /* Zoo_hpp */
