#include "BlackJack.h"
#include "slotMachine.h"
#include "PsychoDice.h"
void startup(std::string& name, int& wallet);
void enterCasino(std::string name, int& wallet);




int main(){
    system("clear");
    std::string name;
    int wallet;
	srand(time(0));
	startup(name, wallet);
	enterCasino(name, wallet);
return 0;	
}


void startup(std::string& name, int& wallet) {
		std::cout << "Please enter your name: " << std::flush;
		getline(std::cin, name);
		wallet = 500;
}

void enterCasino(std::string name, int& wallet){
    
	do{
        system("clear");
        std::cout << "What would you like to play?" << std::endl;
        std::cout << "(B) - BlackJack\n(S) - Slots\n(P) - Psycho Dice\n(L) - leave" << std::endl;
        char choice;
        std::cin >> choice;
        switch(std::tolower(choice)){
            case 'b':
                playBlackJack(name, wallet);
                break;
            case 's':
                PlaySlots(wallet);
                break;
            case 'p':
                playPsychoDice(wallet);
                break;
            case 'l':
                return;
                break;
        }
    }while(0==0);
    
}