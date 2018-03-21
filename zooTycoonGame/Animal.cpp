/*********************************************************************
 ** Program name: Project 2 - Zoo Tycoon
 ** Author: B. Christopher Loreta
 ** Date: 19 Oct 2017
 ** Description:
 
 This file contains implementation of Animal class member functions.
 *********************************************************************/

#include "Animal.hpp"

/*********************************************************************
 Setter function for age of animal in days
 *********************************************************************/
void Animal::setAge(int days){
    age = days;}

/*********************************************************************
  Setter function for cost of buying an animal
 *********************************************************************/
void Animal::setCost(int dollars){
    cost = dollars;}

/*********************************************************************
 Setter function for number of babies an animal would have
 *********************************************************************/
void Animal::setBabies(int numBabies){
    numberOfBabies = numBabies;}

/*********************************************************************
 Setter function for food cost per animal
 *********************************************************************/
void Animal::setFoodCost(int price){
    baseFoodCost = price;}

/*********************************************************************
 Setter function for payoff per animal
 *********************************************************************/
void Animal::setPayoff(int pay){
    payoff = pay;}

/*********************************************************************
 Getter function for age
 *********************************************************************/
int Animal::getAge(){
    return age;
}

/*********************************************************************
 Getter function for base food cost
 *********************************************************************/
int Animal::getBaseFoodCost(){
    return baseFoodCost;
}

/*********************************************************************
 Getter function for number of babies an animal has
 *********************************************************************/
int Animal::getNumBabies(){
    return numberOfBabies;
}

/*********************************************************************
 Getter function for cost of animal purchase
 *********************************************************************/
int Animal::getCost(){
    return cost;}

/*********************************************************************
 Getter function for animal payoff
 *********************************************************************/
int Animal::getPayoff(){
    return payoff;
}

/*********************************************************************
 This function adds a day to the animal's age.
 *********************************************************************/
void Animal::addDay(){
    age++;
}
