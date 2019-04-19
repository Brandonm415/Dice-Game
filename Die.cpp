/***********************************************************
** Program name: Lab 3
** Author: Brandon Mai
** Date: 4/18/2019
** Description: A dice throwing simulator game for two
**              players. The user can choose how many rounds,
**              sides of the dice, and normal or loaded dice.
************************************************************/
#include "Die.hpp"
#include <iostream>
#include <cstdlib>

Die::Die()
{
}

//Set function for dice sides for player 1
void Die::setDiceSidesP1(int x)
{
    sidesP1 = x;
}

//Set function for dice sides for player 2
void Die::setDiceSidesP2(int x)
{
    sidesP2 = x;
}

//Function that rolls dice for player 1
int Die::rollDiceP1()
{
    //Adapted from: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    resultsP1 = rand() % sidesP1 + 1;
    return resultsP1;
}

//Function that rolls dice for player 2
int Die::rollDiceP2()
{
    //Adapted from: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    resultsP2 = rand() % sidesP2 + 1;
    return resultsP2;
}

//Get function for player 1 results
int Die::getResultsP1()
{
    return resultsP1;
}

//Get function for player 2 results
int Die::getResultsP2()
{
    return resultsP2;
}
