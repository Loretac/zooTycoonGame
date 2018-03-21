/*********************************************************************
 ** Program name: Project 2 - Zoo Tycoon
 ** Author: B. Christopher Loreta
 ** Date: 19 Oct 2017
 ** Description:
 
This file contains implementation of Zoo class member functions.
 *********************************************************************/

#include <iostream>
#include "Zoo.hpp"

using std::cout;
using std::endl;

/*********************************************************************
 The play function begins by prompting the user to purchase either 1
 or 2 of each animal, then starts a loop that runs each "day".
 *********************************************************************/
void Zoo::play()
{
    srand(time(NULL)); // Seeds for random numbers
    
    cout << "Welcome to Zoo Tycoon! " << endl << endl;
    
    cout << "You begin with $" << bank;
    cout << " and can purchase 3 types of animals." << endl << endl;
    std::cout << "Tiger cost: $10,000" << endl;
    
    cout << "How many tigers would you like to buy? (1 or 2)" << endl;
    std::string choiceTig;
    getline(std::cin, choiceTig);
    
    while(choiceTig != "1" &&
          choiceTig != "2"
          )
    {
        std::cout << "Please choose a valid option." << std::endl;
        getline(std::cin, choiceTig);
    }
    
    if(choiceTig == "1"){
        addTiger(0);
        bank -= 10000;
        
    }
    
    if(choiceTig == "2"){
        addTiger(0);
        bank -= 10000;
        
        addTiger(0);
        bank -= 10000;
        
    }
    
    std::cout << std::endl << "Penguin cost: $1,000" << std::endl;
    
    cout << "How many penguins would you like to buy? (1 or 2)";
    cout << endl;
    std::string choicePen;
    getline(std::cin, choicePen);
    
    while(choicePen != "1" &&
          choicePen != "2")
    {
        std::cout << "Please choose a valid option." << std::endl;
        getline(std::cin, choicePen);}
    
    if(choicePen == "1")
    {
        addPenguin(0);
        bank -= 1000;
        
    }
    
    if(choicePen == "2")
    {
        addPenguin(0);
        bank -= 1000;
        
        addPenguin(0);
        bank -= 1000;
        
    }
    
    std::cout << std::endl << "Turtle cost: $100" << std::endl;
    
    cout << "How many turtles would you like to buy? (1 or 2)";
    cout << std::endl;
    std::string choiceTur;
    getline(std::cin, choiceTur);
    
    while(choiceTur != "1" &&
          choiceTur != "2"
          )
    {
        std::cout << "Please choose a valid option." << std::endl;
        getline(std::cin, choiceTur);
    }
    
    if(choiceTur == "1")
    {
        addTurtle(0);
        bank -= 100;
    }
    
    if(choiceTur == "2")
    {
        addTurtle(0);
        bank -= 100;
        
        addTurtle(0);
        bank -= 100;
    }
    
    std::cout << std::endl << "Press Enter to start the first day!" << std::endl;
    std::cin.ignore();
    
    string gameStatus = "1";
    
    
    /*****************************************************************
     Daily loop begins here!
     *****************************************************************/
    while(bank > 0 && gameStatus == "1"){
        cout << "-------------------------------------------" << endl;
        int tigerCost = 0, penguinCost = 0, turtleCost = 0;
        int tigerAdults = 0, penguinAdults = 0, turtleAdults = 0;
        int dailyCost = 0; // Total food costs for day
        
        for(int i = 0; i < numTigers; i++){
            tigerCost += tigerArr[i]->getBaseFoodCost();
            tigerArr[i]->addDay(); // Add a day to each tiger's age
            
            if(tigerArr[i]->getAge() >= 3){
                tigerAdults++;
                
            }
        }
 
        cout << "Cost for " << numTigers << " tigers: $";
        cout << tigerCost << endl;
        
        bank -= tigerCost;
        dailyCost += tigerCost;
        
        for(int i = 0; i < numPenguins; i++){
            penguinCost += penguinArr[i]->getBaseFoodCost();
            penguinArr[i]->addDay(); // Add day to each penguin's age
            
            if(penguinArr[i]->getAge() >= 3){
                penguinAdults++;
            }
        }
        
        std::cout << "Cost for " << numPenguins << " pengins: $";
        cout << penguinCost << std::endl;
        
        bank -= penguinCost;
        dailyCost += penguinCost;
        
        for(int i = 0; i < numTurtles; i++){
            turtleCost += turtleArr[i]->getBaseFoodCost();
            turtleArr[i]->addDay(); // Add a day to each turtle's age
            
            if(turtleArr[i]->getAge() >= 3){
                turtleAdults++;
            }
        }
        
        cout << "Cost for " << numTurtles << " turtles: $";
        cout << turtleCost << endl;
        
        bank -= turtleCost;
        dailyCost += turtleCost;
        
        cout << endl << "Daily cost of $" << dailyCost;
        cout << " removed from bank account." << endl << endl;
        
        cout << "Bank account: $" << bank << endl << endl;
        
        // Random Event
        int eventNumber = rand() % 4;
        
        int totalBonus = 0;
        
        while(eventNumber == 0){
            if(numTigers > 0 || numPenguins > 0 || numTurtles > 0){
            int animalNumber = rand() % 3;
            
            if(animalNumber == 0 && numTigers > 0){
                cout << "A sickness has occured to an animal! ";
                cout << endl;
                cout << "One of your tigers died." << endl;
                delete [] tigerArr[numTigers-1];
                numTigers--;
                break;}
            
            if(animalNumber == 1 && numPenguins > 0){
                cout << "A sickness has occured to an animal! ";
                cout << std::endl;
                cout << "One of your penguins died." << endl;
                delete [] penguinArr[numPenguins-1];
                numPenguins--;
                break;}
            
            if(animalNumber == 2 && numTurtles > 0){
                cout << "A sickness has occured to an animal! ";
                cout << endl;
                cout << "One of your turtles died." << endl;
                delete [] turtleArr[numTurtles-1];
                numTurtles--;
                break;}
            }
            else{
                cout << "No sicknesses, you have no more animals!";
                cout << endl;
                break;}
            
            }
        
        if(eventNumber == 1){
            int bonus = rand() % 250 + 250;
            totalBonus = bonus * numTigers;
            cout << "Today had a boom in attendance! " << endl;
            cout << "You earned a bonus of $" << bonus;
            cout << " per tiger!" << endl;
            cout << "Total bonus: $" << totalBonus << endl;
            bank += totalBonus;
        }
        while(eventNumber == 2){
            
            if(tigerAdults != 0 &&
               penguinAdults != 0 &&
               turtleAdults != 0){
                
                int animalNumber = rand() % 3;
                
                if(animalNumber == 0 && tigerAdults != 0){
                    cout << "A baby tiger is born!" << endl;
                    tigerBirth();
                    break;
                }
                
                if(animalNumber == 1 && penguinAdults != 0){
                    cout << "Baby penguins are born!" << endl;
                    penguinBirth();
                    break;
                }
                
                if(animalNumber == 2 && turtleAdults != 0){
                    cout << "Baby turtles are born!" << endl;
                    turtleBirth();
                    break;
                }
                
            }
            
            else{
                cout << "Your animals are too young to have babies.";
                cout << endl;
                break;
            }

        }
        if(eventNumber == 3){
            std::cout << "Nothing new happens today." << std::endl;
        }
        
        std::cout << std::endl;
        
        std::cout << "Number of tigers: " << numTigers << endl;
        std::cout << "Number of penguins: " << numPenguins << endl;
        std::cout << "Number of turtles: " << numTurtles << endl;
        
        int tigerProfit = 0;
        int penguinProfit = 0;
        int turtleProfit = 0;
        
        for(int i = 0; i < numTigers; i++){
            tigerProfit += tigerArr[i]->getPayoff();
        }
        
        for(int i = 0; i < numPenguins; i++){
            penguinProfit += penguinArr[i]->getPayoff();
        }
        
        for(int i = 0; i < numTurtles; i++){
            turtleProfit += turtleArr[i]->getPayoff();
        }
        
        std::cout << "Profit for tigers: $" << tigerProfit << endl;
        cout << "Profit for penguins: $" << penguinProfit << endl;
        cout << "Profit for turtles: $" << turtleProfit << endl;
        std::cout << "Tiger bonus: $" << totalBonus << std::endl;
        
        
        
        int totalProfit = (tigerProfit
                           + penguinProfit
                           + turtleProfit
                           + totalBonus);
        
        
        
        
        cout << "Daily profit: $" << totalProfit << endl;
        
        bank += totalProfit;
        
        cout << "Bank account: $" << bank << endl;
        
        cout << "Would you like to buy an adult animal?" << endl;
        
        Menu menu1;
        string choice1 = menu1.mainMenu("1. Yes", "2. No");
        
        cout << endl;
        
        if(choice1 == "1"){
            cout << "What type of animal?" << endl;
            
            string choice2 = menu1.mainMenu("1. Tiger",
                                            "2. Penguin",
                                            "3. Turtle");
            
            if(choice2 == "1"){
                checkTigerArray(1);
                addTiger(3); // Adult tiger is 3 days old
                bank -= tigerArr[0]->getCost();
                
                cout << "One adult tiger has been added ";
                cout << "to your zoo." << endl;
            }
            
            if(choice2 == "2"){
                checkPenguinArray(1);
                addPenguin(3); // Adult penguin is 3 days old
                bank -= penguinArr[0]->getCost();
                
                cout << "One adult penguin has been added ";
                cout << "to your zoo." << endl;
            }
            
            if(choice2 == "3"){
                checkTurtleArray(1);
                addTurtle(3); // Adult turtle is 3 days old
                bank -= turtleArr[0]->getCost();
                
                cout << "One adult turtle has been added ";
                cout << "to your zoo." << endl;
            }
        }
    
        gameStatus = menu1.mainMenu("1. Start a new day!",
                                    "2. Quit the game");
    }

    // Free allocated memory
    
    for(int i = 0; i < numTigers; i++){
        delete [] tigerArr[i];
    }
    
    delete []tigerArr;
    
    for(int i = 0; i < numPenguins; i++){
        delete [] penguinArr[i];
    }
    
    delete []penguinArr;
    
    for(int i = 0; i < numTurtles; i++){
        delete []turtleArr[i];
    }
 
    delete []turtleArr;
}

/*********************************************************************
 This function takes as a parameter an integer (starting age) and adds
 a tiger to the zoo with this age. It returns no value.
 *********************************************************************/
void Zoo::addTiger(int age){
    Tiger *t = new Tiger;
    t->setAge(age);
    
    tigerArr[numTigers] = t;
    numTigers++;
}

/*********************************************************************
 This function takes as a parameter an integer (starting age) and adds
 a penguin to the zoo with this age. It returns no value.
 *********************************************************************/
void Zoo::addPenguin(int age){
    Penguin *p = new Penguin;
    p->setAge(age);
    
    penguinArr[numPenguins] = p;
    numPenguins++;
}

/*********************************************************************
 This function takes as a parameter an integer (starting age) and adds
 a turtle to the zoo with this age. It returns no value.
 *********************************************************************/
void Zoo::addTurtle(int age){
    Turtle *t = new Turtle;
    t->setAge(age);
    
    turtleArr[numTurtles] = t;
    numTurtles++;
}

/*********************************************************************
 This function creates the birth of a tiger with age 0. It takes no
 parameters and returns no values.
 *********************************************************************/
void Zoo::tigerBirth(){
    
    checkTigerArray(tigerArr[0]->getNumBabies());
    
    for(int i = 0; i < tigerArr[0]->getNumBabies(); i++){
        addTiger(0);
    }
}

/*********************************************************************
 This function checks the array of tigers to make sure it is large
 enough to hold its current value plus a specified amount, which it
 takes as a parameter. If the array is large enough, the function
 completes without doing anything; if not, the function creates a new
 array double the size which becomes the new tiger array. It returns
 no values.
 *********************************************************************/
void Zoo::checkTigerArray(int addedNumber){
    // If current array is not long enough for more turtles
    if(tigerArrLength < numTigers + addedNumber){
        
        int newLength = tigerArrLength * 2;  // New doubled array length
        
        Tiger **tempTigerArr= new Tiger*[newLength]; // Allocate memory for a new array
        
        for(int i = 0; i < numTigers; i++){
            tempTigerArr[i] = tigerArr[i];// Copy each object to new array
        }
        
        delete [] tigerArr; // Free the original array
        
        tigerArr = tempTigerArr; // Point at the newly created array
        
        tigerArrLength *= 2; // Double the length variable
    }
}

/*********************************************************************
 This function creates the birth of a penguin with age 0. It takes no
 parameters and returns no values.
 *********************************************************************/
void Zoo::penguinBirth(){

    checkPenguinArray(penguinArr[0]->getNumBabies());
    
    for(int i = 0; i < penguinArr[0]->getNumBabies(); i++){
        addPenguin(0);
    }
}

/*********************************************************************
 This function is identical to checkTigerArray, but for penguins.
 *********************************************************************/
void Zoo::checkPenguinArray(int numAdded){
    if(penguinArrLength < numPenguins + numAdded){
        
        int newLength = penguinArrLength * 2;
        
        Penguin **tempPenguinArr = new Penguin*[newLength];
        
        for(int i = 0; i < numPenguins; i++){
            
            tempPenguinArr[i] = penguinArr[i];
        }
        
        delete [] penguinArr;
        
        penguinArr = tempPenguinArr;
        
        penguinArrLength *= 2;
    }
}

/*********************************************************************
 This function creates the birth of a turtle with age 0. It takes no
 parameters and returns no values.
 *********************************************************************/
void Zoo::turtleBirth(){
    
    checkTurtleArray(turtleArr[0]->getNumBabies());
    
    for(int i = 0; i < turtleArr[0]->getNumBabies(); i++){
        addTurtle(0);
    }
}

/*********************************************************************
 This function is identical to checkTigerArray, but for turtles.
 *********************************************************************/
void Zoo::checkTurtleArray(int numAdded){
    // If current array is not long enough for 10 more turtles
    if(turtleArrLength < numTurtles + numAdded){
        
        // New doubled array length
        int newLength = turtleArrLength * 2;
        
        // Allocate memory for a new array
        Turtle **tempTurtleArr = new Turtle*[newLength];
        
        for(int i = 0; i < numTurtles; i++){
            
            // Copy each object to new array
            tempTurtleArr[i] = turtleArr[i];
        }
        
        // Free the original array
        delete [] turtleArr;
        
        // Point at the newly created array
        turtleArr = tempTurtleArr;
        
        // Double the length variable
        turtleArrLength *= 2;
    }
    
}

