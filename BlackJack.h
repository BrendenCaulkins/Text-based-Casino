#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Deck.h"
void playBlackJack(std::string name, int & wallet);
void displayBlackJackCurrent(std::vector<card> playersCards, int cardSum, std::vector<card> dealersCards, int dealerCardSum, std::string name, int wallet);
int recalculate(std::vector<card>& cards);
void dealerMoves(const std::vector<card> playersCards,const  int cardSum, std::vector<card> & dealersCards, int &dealerCardSum, std::string name, int wallet, Deck& playingDeck);
void displayRules();

void playBlackJack(std::string name, int & wallet){
    system("clear");
	Deck playingDeck;
	int cardSum = 0, dealerCardSum = 0, bet = 0; std::vector<card> playersCards, dealersCards;
	char choice;
	playingDeck.shuffle();
    std::cout << "You walk up to a table and notice a sign that says:\n----------------\n|h - hit        |\n|s - stand       |\n|r - rules      |\n|b - leave table|\n----------------" << std::endl;
	std::cout << "Once you sit down, " << std::flush;
	do{
        do{
            std::cout << "the dealer states \"It's a $50 minimum to play at this table, how much would you like to bet?(press any non-numeric button to leave)" << std::endl;
            
            std::cout << "Wallet: "<< wallet << std::endl;
        std::cin >> bet;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(500, '\n');
            return;
        }
            if(bet < 50){
                std::cout << "The bet amount must be larger than that to play at this table." << std::endl;		 
                }
            if(bet > wallet){
                std::cout << "You don't have enough money to bet that." << std::endl;
            }
        }while(bet < 50 || bet > wallet);
	
	
	
        cardSum = 0;
        dealerCardSum = 0;
        playersCards.resize(0);
        dealersCards.resize(0);
			playersCards.push_back(playingDeck.draw());
			cardSum += playersCards.at(0).getCardValue();
			playersCards.push_back(playingDeck.draw());
			cardSum += playersCards.at(1).getCardValue();
			
			dealersCards.push_back(playingDeck.draw());
			dealerCardSum += dealersCards.at(0).getCardValue();
			dealersCards.push_back(playingDeck.draw());
			dealerCardSum += dealersCards.at(1).getCardValue();
		
		do{
			displayBlackJackCurrent(playersCards, cardSum, dealersCards, dealerCardSum, name, wallet);
			std::cout << "hit or stand? " << std::endl;
			std::cin >> choice;
			if(std::tolower(choice) == 'h'){
				playersCards.push_back(playingDeck.draw());
				cardSum += playersCards.at(playersCards.size()-1).getCardValue();
				if(cardSum > 21){
					cardSum = recalculate(playersCards);
				}
			}
            else if(std::tolower(choice) == 'r'){
                displayRules();
                choice = 'h';
            }
		}while(std::tolower(choice) == 'h' && cardSum < 21);
		if(cardSum > 21){
            displayBlackJackCurrent(playersCards, cardSum, dealersCards, dealerCardSum, name, wallet);
			std::cout << "Bust, you lost $" << bet << " would you like to play again?" << std::endl;
            wallet -= bet;
		}
		else if(cardSum == 21){
            displayBlackJackCurrent(playersCards, cardSum, dealersCards, dealerCardSum, name, wallet);
			std::cout << "21! congratulations, you won $" << bet << std::endl;
			wallet += bet;
			std::cout << "would you like to play again?" << std::endl;
		}
		else{
			
			dealerMoves(playersCards, cardSum, dealersCards, dealerCardSum, name, wallet, playingDeck);
            displayBlackJackCurrent(playersCards, cardSum, dealersCards, dealerCardSum, name, wallet);
            if(dealerCardSum > 21){
                std::cout << "Dealer's Bust! congratulations, you won $" << bet << std::endl;
                wallet += bet;
                std::cout << "would you like to play again?" << std::endl;
            }
            else if(dealerCardSum == 21){
                std::cout << "Dealer's 21, you lost $" << bet << std::endl;
			wallet -= bet;
			std::cout << "would you like to play again?" << std::endl;
            }
            else{
                if(cardSum >= dealerCardSum){
                    std::cout << "Congratulations, you won $" << bet << std::endl;
                wallet += bet;
                std::cout << "would you like to play again?" << std::endl;
                }
                else{
                    std::cout << "Dealer won, you lost $" << bet << std::endl;
                    wallet -= bet;
                    std::cout << "would you like to play again?" << std::endl;
                }
            }
		}
		do{
			std::cin >> choice;
			if(std::tolower(choice) == 'b'){
				return;
			}
			if(std::tolower(choice) != 'y' && std::tolower(choice) != 'n'){
				std::cout << "Please make a choice" << std::endl;
			}
		  }while(std::tolower(choice) !='y' && std::tolower(choice) != 'n');
		
	}while(std::tolower(choice) == 'y');
	
}


void displayBlackJackCurrent(std::vector<card> playersCards, int cardSum, std::vector<card> dealersCards, int dealerCardSum, std::string name, int wallet){
	std::cout << "Dealer: "<< std::endl;
	for(unsigned i = 0; i < dealersCards.size(); ++i){
		std::cout << dealersCards.at(i) << std::flush;
		if(i + 1 < dealersCards.size()){
			std::cout << ", " << std::flush;
		}
	}
	std::cout << std::endl;
	std::cout << "Value: " << dealerCardSum << std::endl;
	std::cout << std::endl;
	std::cout << name << ": "<< std::endl;
	for(unsigned i = 0; i < playersCards.size(); ++i){
		std::cout << playersCards.at(i) << std::flush;
		if(i + 1 < playersCards.size()){
			std::cout << ", " << std::flush;
		}
	}
	std::cout << std::endl;
	std::cout << "Value: " << cardSum << std::endl;
	std::cout << "Wallet: " << wallet << std::endl;
    std::cout << std::endl;
	
}

int recalculate(std::vector<card> & cards){
	int temp = 0;
	for(unsigned i = 0; i < cards.size(); ++i){
		temp += cards.at(i).getCardValue();
	}
	return temp;
}

void dealerMoves(const std::vector<card> playersCards, const int cardSum, std::vector<card>& dealersCards, int& dealerCardSum, std::string name, int wallet, Deck& playingDeck){
    char decision;
    do{
        displayBlackJackCurrent(playersCards, cardSum, dealersCards, dealerCardSum, name, wallet);
        
        if(dealerCardSum <=11 || cardSum == dealerCardSum){
            decision = 'h';
            dealersCards.push_back(playingDeck.draw());
            dealerCardSum += dealersCards.at(dealersCards.size()-1).getCardValue();
            if(dealerCardSum > 21){
                dealerCardSum = recalculate(dealersCards);
            }
        }
        else{
            int valCheck = 21 - dealerCardSum;
            std::vector<card> cardsLeft = playingDeck.getDeck();
            int lessThan = 0, numLess = 0;
            for(unsigned i = 0; i < cardsLeft.size(); ++i){
                lessThan = cardsLeft.at(i).getCardValue();
                lessThan = cardsLeft.at(i).getCardValue(); 
                if(lessThan <= valCheck){
                    ++numLess;
                }
            }
            double percentage = 100.0 *(numLess/( 1.0 *cardsLeft.size()));
            if(percentage > 50){
                decision = 'h';
            dealersCards.push_back(playingDeck.draw());
            dealerCardSum += dealersCards.at(dealersCards.size()-1).getCardValue();
            if(dealerCardSum > 21){
                dealerCardSum = recalculate(dealersCards);
            }
            }
            else{
                decision = 'p';
            }
        }
        int currTime = time(0), wait = time(0) + 1;
        while(currTime < wait){
            currTime = time(0);
        }
        
    }while(decision == 'h' && dealerCardSum < 21);
}

void displayRules(){ 
    char exit;
    std::cout << "The goal is to get as close to 21 without going over as possible.\n";
    std::cout << "Card values:\nAce:\t1 or 11\n2:\t2\n3:\t3\n4:\t4\n5:\t5\n6:\t6\n7:\t7\n8:\t8\n9:\t9\n10:\t10\nJ:\t10\nQ:\t10\nK:\t10\n";
    do{std::cout << "\nPress 'b' to return\n";
        std::cin >> exit;
    }while (std::tolower(exit) != 'b');
}

#endif