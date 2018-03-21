/*********************************************************************
 ** Program name: Project 2 - Zoo Tycoon
 ** Author: B. Christopher Loreta
 ** Date: 19 Oct 2017
 ** Description:
 
 This file contains implementation of Turtle class member functions.
 *********************************************************************/

#include "Turtle.hpp"

/*********************************************************************
 Default constructor takes no parameters, sets the cost, number of
 babies, food cost, and payoff.
 *********************************************************************/
Turtle::Turtle(){
    setCost(100);
    setBabies(10);
    setFoodCost(getBaseFoodCost() / 2);
    setPayoff(getCost() / 20);
    
}
