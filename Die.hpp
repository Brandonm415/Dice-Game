/***********************************************************
** Program name: Lab 3
** Author: Brandon Mai
** Date: 4/18/2019
** Description: A dice throwing simulator game for two
**              players. The user can choose how many rounds,
**              sides of the dice, and normal or loaded dice.
************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

//Die class contains functions for rolling normal dice and returning the results
class Die
{
    public:
        Die();
        void setDiceSidesP1(int x);
        void setDiceSidesP2(int x);
        int rollDiceP1();
        int rollDiceP2();
        int getResultsP1();
        int getResultsP2();
    private:
        int resultsP1;
        int resultsP2;
    protected:
        int sidesP1;
        int sidesP2;

};

#endif
