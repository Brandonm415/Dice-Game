/***********************************************************
** Program name: Lab 3
** Author: Brandon Mai
** Date: 4/18/2019
** Description: A dice throwing simulator game for two
**              players. The user can choose how many rounds,
**              sides of the dice, and normal or loaded dice.
************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "Die.hpp"

//LoadedDie class contains functions to roll a loaded dice and return the results
class LoadedDie:public Die
{
    public:
        LoadedDie();
        int loadedRollP1();
        int loadedRollP2();
        int getLoadedResultsP1();
        int getLoadedResultsP2();
    private:
        int resultsP1;
        int resultsP2;
};

#endif
