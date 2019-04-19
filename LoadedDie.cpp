/***********************************************************
** Program name: Lab 3
** Author: Brandon Mai
** Date: 4/18/2019
** Description: A dice throwing simulator game for two
**              players. The user can choose how many rounds,
**              sides of the dice, and normal or loaded dice.
************************************************************/
#include "LoadedDie.hpp"
#include "Die.hpp"
#include <iostream>
#include <cstdlib>

LoadedDie::LoadedDie()
{
}

//Function to roll a loaded dice for player 1
int LoadedDie::loadedRollP1()
{
    int holder;
    holder = rand() % sidesP1 + 1;
    resultsP1 = holder + rand() % sidesP1 + 1;
    resultsP1 = resultsP1 / 1.3;
    while(resultsP1 > sidesP1)
    {
        holder = rand() % sidesP1 + 1;
        resultsP1 = holder + rand() % sidesP1 + 1;
        resultsP1 = resultsP1 / 1.3;
    }
    return resultsP1;
}

//Function to roll a loaded dice for player 2
int LoadedDie::loadedRollP2()
{
    int holder;
    holder = rand() % sidesP2 + 1;
    resultsP2 = holder + rand() % sidesP2 + 1;
    resultsP2 = resultsP2 / 1.3;
    while(resultsP2 > sidesP2)
    {
        holder = rand() % sidesP2 + 1;
        resultsP2 = holder + rand() % sidesP2 + 1;
        resultsP2 = resultsP1 / 1.3;
    }
    return resultsP2;
}

//Get function for player 1 results
int LoadedDie::getLoadedResultsP1()
{
    return resultsP1;
}

//Get function for player 2 results
int LoadedDie::getLoadedResultsP2()
{
    return resultsP2;
}
