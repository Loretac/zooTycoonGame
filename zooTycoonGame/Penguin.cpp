/*********************************************************************
 ** Program name: Project 2 - Zoo Tycoon
 ** Author: B. Christopher Loreta
 ** Date: 19 Oct 2017
 ** Description:
 
 This file contains implementation of Penguin class member functions.
 *********************************************************************/

#include "Penguin.hpp"

/*********************************************************************
 Default constructor takes no parameters, sets the cost, number of
 babies, food cost, and payoff.
 *********************************************************************/
Penguin::Penguin(){
    setCost(1000);
    setBabies(5);
    setFoodCost(getBaseFoodCost());
    setPayoff(getCost() / 10);
    
}
