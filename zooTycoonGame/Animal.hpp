/*********************************************************************
 ** Program name: Project 2 - Zoo Tycoon
 ** Author: B. Christopher Loreta
 ** Date: 19 Oct 2017
 ** Description:
 
 This file contains the member variables and function prototypes for
 class Animal.
 *********************************************************************/

#ifndef Animal_hpp
#define Animal_hpp

#include <iostream>

class Animal
{
private:
    int age;
    int cost;
    int numberOfBabies;
    int baseFoodCost = 10;
    int payoff;
    
public:
    void setAge(int);
    void setCost(int);
    void setBabies(int);
    void setFoodCost(int);
    void setPayoff(int);
    int getAge();
    int getCost();
    int getNumBabies();
    int getBaseFoodCost();
    int getPayoff();
    void addDay();
};

#endif /* Animal_hpp */
