/***********************************************************
** Program name: Lab 3
** Author: Brandon Mai
** Date: 4/18/2019
** Description: A dice throwing simulator game for two
**              players. The user can choose how many rounds,
**              sides of the dice, and normal or loaded dice.
************************************************************/
#include <iostream>
#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include <time.h>
#include <string>

Game::Game()
{
    normalDice = "Normal";
    loadedDice = "Loaded";
}

//Function to display menu, run the game, and print out results
void Game::displayMenu()
{
    std::cout << "Welcome to the Dice War Game!" << std::endl;
    std::cout << "Please pick and option:" << std::endl;
    std::cout << "1. Play Game" << std::endl;
    std::cout << "2. Exit Game" << std::endl;
    chooseOption();
        if(choice == 1)
        {
            chooseRounds();
            chooseDiceSidesP1();
            chooseDiceSidesP2();
            chooseDiceStatusP1();
            chooseDiceStatusP2();

            //Regular Die and Loaded Die classes
            Die rolls;
            LoadedDie loadedRolls;

            int counter = 0;
            srand(time(0));

            //Arrays to keep track of score
            int scoreKeeperP1[rounds];
            int scoreKeeperP2[rounds];

            //Roll dice until rounds are finished
            while(counter < rounds)
            {
                //If Player1 picks regular dice
                if(diceStatusP1 == 0)
                {
                    //Roll the dice
                    rolls.setDiceSidesP1(diceSidesP1);
                    rolls.rollDiceP1();
                    std::cout << "Player1- Dice sides: " << diceSidesP1 << " Type of dice: " << diceType() << std::endl;
                    int resultsP1 = rolls.getResultsP1();
                    std::cout << "Player1 rolled: " << resultsP1 << std::endl;
                    scoreKeeperP1[counter] = resultsP1;
                }
                //If Player1 picks loaded dice
                else if(diceStatusP1 == 1)
                {
                    //Roll the dice
                    loadedRolls.setDiceSidesP1(diceSidesP1);
                    loadedRolls.loadedRollP1();
                    std::cout << "Player1- Dice sides: " << diceSidesP1 << " Type of dice: " << diceType() << std::endl;
                    int resultsP1 = loadedRolls.getLoadedResultsP1();
                    std::cout << "Player1 rolled: " << resultsP1 << std::endl;
                    scoreKeeperP1[counter] = resultsP1;
                }
                //If Player2 picks regular dice
                if(diceStatusP2 == 0)
                {
                    //Roll the dice
                    rolls.setDiceSidesP2(diceSidesP2);
                    rolls.rollDiceP2();
                    std::cout << "Player2- Dice sides: " << diceSidesP2 << " Type of dice: " << diceTypeP2() << std::endl;
                    int resultsP2 = rolls.getResultsP2();
                    std::cout << "Player2 rolled: " << resultsP2 << std::endl;
                    scoreKeeperP2[counter] = resultsP2;
                }
                //If Player2 picks loaded dice
                else if(diceStatusP2 == 1)
                {
                    //Roll the dice
                    loadedRolls.setDiceSidesP2(diceSidesP2);
                    loadedRolls.loadedRollP2();
                    std::cout << "Player2- Dice sides: " << diceSidesP2 << " Type of dice: " << diceTypeP2() << std::endl;
                    int resultsP2 = loadedRolls.getLoadedResultsP2();
                    std::cout << "Player2 rolled: " << resultsP2 << std::endl;
                    scoreKeeperP2[counter] = resultsP2;
                }
                counter++;
            }
                //Score trackers
                int player1Score = 0;
                int player2Score = 0;
                int draws = 0;
                //Loop that compares all player 1 rolls with player 2 rolls
                //Uses the array created from earlier to compare
                //If player 1 wins add one to player 1 score, and vice versa
                for(int i = 0; i < rounds; i++)
                {
                    if(scoreKeeperP1[i] > scoreKeeperP2[i])
                    {
                        player1Score++;
                    }
                    else if(scoreKeeperP1[i] < scoreKeeperP2[i])
                    {
                        player2Score++;
                    }
                    else
                    {
                        draws++;
                    }
                }
                //Print out final scores
                std::cout << "Player1 win count: " << player1Score << std::endl;
                std::cout << "Player2 win count: " << player2Score << std::endl;
                std::cout << "Draws: " << draws << std::endl;
        }
}

//Function that checks input validation for menu options
void Game::chooseOption()
{
    int counter = 0;
    while(counter < 1)
    {
        std::cin >> choice;
        //Adapted from: http://www.cplusplus.com/forum/beginner/58833/
        //Checks if integer is entered or not
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid option. Please choose a valid option." << std::endl;
            std::cout << "1. Play Game" << std::endl;
            std::cout << "2. Exit Game" << std::endl;
        }
        //If integer is entered checks if it matches options
        else
        {
            //If integer entered matches possible choices end the loop
            if(choice == 1 || choice == 2)
            {
                counter++;
            }
            //Repeat the loop if integer does not match possible choices
            else
            {
                std::cout << "That is not a valid option. Please choose a valid option." << std::endl;
                std::cout << "1. Play Game" << std::endl;
                std::cout << "2. Exit Game" << std::endl;
            }
        }
    }
}

//Function that asks user for how many rounds with input validation
void Game::chooseRounds()
{
    int counter = 0;
    while(counter < 1)
    {
        std::cout << "Please enter how many rounds you would like to play." << std::endl;
        std::cout << "Enter a number between 1 - 9999." << std::endl;
        std::cin >> rounds;
        //Adapted from: http://www.cplusplus.com/forum/beginner/58833/
        //Checks if integer is entered or not
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid entry. Please enter a valid entry." << std::endl;
        }
        //If integer is entered checks if it matches options
        else
        {
            //If integer entered matches possible choices end the loop
            if(rounds > 0 && rounds < 10000)
            {
                counter++;
            }
            //Repeat the loop if integer does not match possible choices
            else
            {
                std::cout << "That is not a valid entry. Please enter a valid entry." << std::endl;
            }
        }
    }
}

//Function that asks user to choose how many sides for the dice for Player 1 with input validation
void Game::chooseDiceSidesP1()
{
    int counter = 0;
    while(counter < 1)
    {
        std::cout << "Please choose how many sides the dice for Player 1 will have." << std::endl;
        std::cout << "Enter a number between 2 - 9999." << std::endl;
        std::cin >> diceSidesP1;
        //Adapted from: http://www.cplusplus.com/forum/beginner/58833/
        //Checks if integer is entered or not
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid entry. Please enter a valid entry." << std::endl;
        }
        //If integer is entered checks if it matches options
        else
        {
            //If integer entered matches possible choices end the loop
            if(diceSidesP1 > 1 && diceSidesP1 < 10000)
            {
                counter++;
            }
            //Repeat the loop if integer does not match possible choices
            else
            {
                std::cout << "That is not a valid entry. Please enter a valid entry." << std::endl;
            }
        }
    }
}

//Function that asks user to choose how many sides for the dice for Player 2 with input validation
void Game::chooseDiceSidesP2()
{
    int counter = 0;
    while(counter < 1)
    {
        std::cout << "Please choose how many sides the dice for Player 2 will have." << std::endl;
        std::cout << "Enter a number between 2 - 9999." << std::endl;
        std::cin >> diceSidesP2;
        //Adapted from: http://www.cplusplus.com/forum/beginner/58833/
        //Checks if integer is entered or not
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid entry. Please enter a valid entry." << std::endl;
        }
        //If integer is entered checks if it matches options
        else
        {
            //If integer entered matches possible choices end the loop
            if(diceSidesP2 > 1 && diceSidesP2 < 10000)
            {
                counter++;
            }
            //Repeat the loop if integer does not match possible choices
            else
            {
                std::cout << "That is not a valid entry. Please enter a valid entry." << std::endl;
            }
        }
    }
}

//Function that asks user to choose regular or loaded dice for player 1 with input validation
void Game::chooseDiceStatusP1()
{
    int counter = 0;
    while(counter < 1)
    {
        std::cout << "Please choose what kind of dice Player 1 will use." << std::endl;
        std::cout << "Enter 0 for normal dice and enter 1 for loaded dice." << std::endl;
        std::cin >> diceStatusP1;
        //Adapted from: http://www.cplusplus.com/forum/beginner/58833/
        //Checks if integer is entered or not
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid entry. Please enter a valid entry." << std::endl;
        }
        //If integer is entered checks if it matches options
        else
        {
            //If integer entered matches possible choices end the loop
            if(diceStatusP1 == 0)
            {
                counter++;
            }
            else if(diceStatusP1 == 1)
            {
                counter++;
            }
            //Repeat the loop if integer does not match possible choices
            else
            {
                std::cout << "That is not a valid entry. Please enter a valid entry." << std::endl;
            }
        }
    }
}

//Function that asks user to choose regular or loaded dice for player 2 with input validation
void Game::chooseDiceStatusP2()
{
    int counter = 0;
    while(counter < 1)
    {
        std::cout << "Please choose what kind of dice Player 2 will use." << std::endl;
        std::cout << "Enter 0 for normal dice and enter 1 for loaded dice." << std::endl;
        std::cin >> diceStatusP2;
        //Adapted from: http://www.cplusplus.com/forum/beginner/58833/
        //Checks if integer is entered or not
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid entry. Please enter a valid entry." << std::endl;
        }
        //If integer is entered checks if it matches options
        else
        {
            //If integer entered matches possible choices end the loop
            if(diceStatusP2 == 0)
            {
                counter++;
            }
            else if(diceStatusP2 == 1)
            {
                counter++;
            }
            //Repeat the loop if integer does not match possible choices
            else
            {
                std::cout << "That is not a valid entry. Please enter a valid entry." << std::endl;
            }
        }
    }
}

//Function that checks dice type and returns if it is normal or loaded for player 1
std::string Game::diceType()
{
    if(diceStatusP1 == 0)
    {
        return normalDice;
    }
    else
    {
        return loadedDice;
    }
}

//Function that checks dice type and returns if it is normal or loaded for player 2
std::string Game::diceTypeP2()
{
    if(diceStatusP2 == 0)
    {
        return normalDice;
    }
    else
    {
        return loadedDice;
    }

}

