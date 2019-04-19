/***********************************************************
** Program name: Lab 3
** Author: Brandon Mai
** Date: 4/18/2019
** Description: A dice throwing simulator game for two
**              players. The user can choose how many rounds,
**              sides of the dice, and normal or loaded dice.
************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

//Game class contains functions that handle the menu options as well as user input to set up dice game
class Game
{
    public:
        Game();
        void displayMenu();
        int getChoice();
        void chooseOption();
        void chooseRounds();
        void chooseDiceSidesP1();
        void chooseDiceSidesP2();
        void chooseDiceStatusP1();
        void chooseDiceStatusP2();
        std::string diceType();
        std::string diceTypeP2();
    private:
        int choice;
        int rounds;
        int diceSidesP1;
        int diceSidesP2;
        int diceStatusP1;
        int diceStatusP2;
        std::string normalDice;
        std::string loadedDice;
};

#endif
