#ifndef PSYCHO_DICE_H
#define PSYCHO_DICE_H
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

void playPsychoDice(int& wallet);
int CheckMatch(std::vector <int>& uv, std::vector <int>& cv);
void displayPsychoRules();

void playPsychoDice(int & wallet){
    system("clear");
    char choice;
    int userVal, bet, roundsRemaining, roundcount, remainDie, matches;
    std::vector<int> playersDice, results;
    std::cout << "You walk up to a table and notice a sign that says:\n----------------\n|t - throw dice |\n|r - rules      |\n|b - leave table|\n----------------" << std::endl;
    
    std::cout << "Once you sit down, " << std::flush;
     do{
         
     do{
            std::cout << "the dealer states \"It's a $5 minimum to play at this table, how much would you like to bet?(press any non-numeric button to leave)" << std::endl;
            
            std::cout << "Wallet: "<< wallet << std::endl;
        std::cin >> bet;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(500, '\n');
            return;
        }
            if(bet < 5){
                std::cout << "The bet amount must be larger than that to play at this table." << std::endl;		 
                }
            if(bet > wallet){
                std::cout << "You don't have enough money to bet that." << std::endl;
            }
        }while(bet < 5 || bet > wallet);
    
    
      roundsRemaining = 0;
        roundcount = 0;
    playersDice.resize(0);
         results.resize(0);
    std::cout << "Declare 4 numbers that you wish to roll, (or any non-numeric key to leave)\n";
    while(playersDice.size() < 4){
        std::cin >> userVal;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(500000, '\n');
           return;
        }
        if(userVal <= 6 && userVal > 0){
            playersDice.push_back(userVal);
            
        }
        else{
            std::cout << "Please choose an actual die number.\n";
        }
    }
    
    do{
        results.resize(0);
      do{
          
       std::cout << "Please throw the dice or leave (t/q)" << std::endl;
        std::cin >> choice;
        if(std::tolower(choice) == 'q'){
            return;
        }
        else if(std::tolower(choice) == 't'){
            for(unsigned i = 0; i < playersDice.size(); ++i){
                results.push_back(1 + rand()%6);
            }
        }
        else if(std::tolower(choice) == 'r'){
            displayRules();
        }
        else{
            std::cout << "Please make a decision" << std::endl;
        }
    } while(std::tolower(choice) != 'r');
        for (unsigned i = 0; i < playersDice.size(); ++i){
            std::cout << playersDice.at(i) << " " << std::flush;
        }
        std::cout << std::endl;
        for(int i = 0; i < results.size(); ++i){
            std::cout << results.at(i) << " " << std::flush;
        }
        std::cout << std::endl;
        
        matches = CheckMatch(playersDice, results);
        if( matches == 0){
            ++ roundsRemaining;
        }
        else{
            roundsRemaining = 0;
        }
        std::cout << "Matches found: " << matches << std::endl;
        std::cout << "Di";
        if(remainDie > 1){
                std::cout << "c";
                }
        std::cout << "e remaining: " << results.size() << std::endl;
    ++roundcount;
        std::cout << "Rolls: " << roundcount << std::endl;
        std::cout << "Rounds remaining: " << 3 - roundsRemaining << std::endl;
        std::cout << "Wallet: " << wallet << std::endl;
    }while(results.size() > 0 && roundsRemaining < 3 && std::tolower(choice) != 'q');
    if(results.size() == 0){
        std::cout << "Congratulations on your victory.\n";
        wallet += bet;
    }
    else{
        std::cout << "Better luck next time.\n";
        wallet -= bet;
    }
    do{
    std::cout << "Play again? (y/n)\n";
    std::cin >> choice;
    }while (std::tolower(choice) != 'y' && std::tolower(choice) != 'n');
}while(std::tolower(choice) == 'y');
    
}

int CheckMatch(std::vector <int>& player, std::vector <int>& result){
int matches = 0;
    for(unsigned i = 0; i < player.size(); ++i){
        for(unsigned j = 0; j < result.size(); ++j){
            if(player.at(i) == result.at(j)){
                std::swap(result.at(j), result.at(result.size()-1));
                std::swap(player.at(i), player.at(player.size()-1));
                player.pop_back();
                result.pop_back(); 
                ++ matches;
            }
        }
    }
    return matches;
}

void displayPsychoRules(){
    char b;
    std::cout << "GamePlay:\n\tDeclare four numbers between (and including) 1-6. \n\tEX. 4 3 6 6\n\tRoll the dice, if any of your numbers appear, leave them standing.\n\tRoll until you either match all the numbers or go three successive turns without a match.\n\tIn the latter case you are eliminated.\n\tThe object is to roll all four numbers in the fewest rolls.\n";
    std::cout << "\n\tPress 'b' to return.\n";
    std::cin >> b;
    while(b != 'b' && b != 'B'){
        std::cout << "Please hit the proper button to leave this section.\n";
        std::cin >> b;
    }
}


#endif