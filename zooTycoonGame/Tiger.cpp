/*********************************************************************
 ** Program name: Project 2 - Zoo Tycoon
 ** Author: B. Christopher Loreta
 ** Date: 19 Oct 2017
 ** Description:
 
 This file contains implementation of Tiger class member functions.
 *********************************************************************/

#include "Tiger.hpp"

/*********************************************************************
 Default constructor takes no parameters, sets the cost, number of
 babies, food cost, and payoff.
 *********************************************************************/
Tiger::Tiger()
{
    setCost(10000);
    setBabies(1);
    setFoodCost(getBaseFoodCost()*5);
    setPayoff(getCost() / 5);
}
