#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

struct card{
  char suit;
    std::string value;
    bool enquired = false;
    card() : suit('0'), value("0") {};
    card(int val){
        int tempSuit = val%4;
        int tempValue = 1+val%13;
        switch(tempSuit){//sets the suit value based on the inputted value
            case 0:
                suit = 'H';
                break;
            case 1:
                suit = 'D';
                break;
            case 2:
                suit = 'C';
                break;
            case 3:
                suit = 'S';
                break;
        }
        switch(tempValue){//sets the face value based on the value inputted
            case 1:
                value = 'A';
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                value = std::to_string(tempValue);
                break;
            case 11:
                value = 'J';
                break;
            case 12:
                value = 'Q';
                break;
            case 13:
                value = 'K';
                break;
        }
    }
    
    int getCardValue(){//card values specifically written for blackjack
         if(value == "A"){
            if(!enquired){
                enquired = true;
                return 11;
            }
             else{
                 return 1;
             }
         }
        else if(value == "J" || value == "Q" || value == "K"){
            return 10;
        }
        else{
            return std::stoi(value);
        }
    }
    bool operator==(const card &rhs){
        if(suit == rhs.suit && value == rhs.value){
            return true;
        }
        return false;
    }
     friend std::ostream &operator<<(std::ostream& os, card const &m);
};

class Deck{
    private:
        std::vector<card> deck;
    public:
        Deck(){refill();};
    void refill(){
        deck.resize(0);
        for(unsigned i = 1; i <= 52; ++i){
            deck.push_back(i);
        }
    }
    void shuffle(){
        for(unsigned i = 0; i < 10000; ++i){
            std::swap(deck.at(rand()%deck.size()), deck.at(rand()%deck.size()));
        }
    }
    card draw(){
		if(deck.size() ==0){
			refill();
			shuffle();
		}
        card temp = deck.at(deck.size()-1);
         deck.pop_back();
    return temp;
    }
    
    card at(int i){
        return deck.at(i);
    }
    void swap(int i, int j){
        card temp = deck.at(i);
        deck.at(i) = deck.at(j);
        deck.at(j) = temp;
        return;
    }
    int size(){return deck.size();}
    std::vector<card> getDeck() {return deck;}
     friend std::ostream &operator<<(std::ostream& os, Deck const &m);
};

std::ostream &operator<<(std::ostream &os, Deck const &m) { 
    for(unsigned i = 0; i < m.deck.size(); ++i){
        os << m.deck.at(i);
        if(i + 1 < m.deck.size()){
            os << ", ";
        }
    }
        return os;
}

std::ostream &operator<<(std::ostream &os, card const &m) { 
        os << m.value << m.suit;
    
        return os;
}

#endif