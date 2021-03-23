#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include <iostream>
#include <ctime>
#include <cstdlib>

std::string FirstSlot();
std::string SecondSlot();
std::string ThirdSlot();
int SlotResults(const std::string&, const std::string&, const std::string&);
void PlaySlots();


std::string FirstSlot(){
    int chance = 1 + rand()%100;
    switch(chance){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
            return "Cherry";
            break;
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
            return "Bar";
            break;
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
        case 69:
            return "BarBar";
            break;
        case 80:
        case 81:
        case 82:
        case 83:
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
            return "BarBarBar";
            break;
        case 77:
        case 78:
        case 79:
            return "Seven";
            break;
        case 100:
            return "Diamond";
            break;
        default:
            return "blank";
            break;
}


}

std::string SecondSlot(){
int chance = 1 + rand()%100;
    switch(chance){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
            return "Cherry";
            break;
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
            return "Bar";
            break;
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
        case 69:
            return "BarBar";
            break;
        case 80:
        case 81:
        case 82:
        case 83:
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
            return "BarBarBar";
            break;
        case 77:
        case 78:
        case 79:
            return "Seven";
            break;
        case 100:
            return "Diamond";
            break;
        default:
            return "blank";
            break;
}


}

std::string ThirdSlot(){
int chance = 1 + rand()%100;
    switch(chance){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
            return "Cherry";
            break;
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
            return "Bar";
            break;
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
        case 69:
            return "BarBar";
            break;
        case 80:
        case 81:
        case 82:
        case 83:
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
            return "BarBarBar";
            break;
        case 77:
        case 78:
        case 79:
            return "Seven";
            break;
        case 100:
            return "Diamond";
            break;
        default:
            return "blank";
            break;
}


}

int SlotResults(const std::string& first, const std::string& second, const std::string& third){
    int gainz;

    if(first == second && second == third){
        if( first == "Cherry" || first == "Bar"){
                return 10;
        }
        else if( first == "BarBar"){
                 return 25;
        }
        else if (first == "BarBarBar"){
                return 40;
        }
        else if(first == "Seven"){
                return 80;
        }
        else if(first == "Diamond"){
                return 800;
        }
    }
    else if((first == "Cherry" && second == "Cherry") ||
            (first == "Cherry" && third == "Cherry") ||
             (second == "Cherry" && third == "Cherry")||
            first == "Bar" || second == "Bar" || third == "Bar" ||
            first == "BarBar" || second == "BarBar" || third == "BarBar" ||
            first == "BarBarBar" || second == "BarBarBar" || third == "BarBarBar"){
                return 5;
             }
    else if (first == "Cherry" || second == "Cherry" || third == "Cherry"){
        return 2;
    }
return 0;
}

void PlaySlots(int& wallet){
    system("clear");
    std::string firstSlot, secondSlot, thirdSlot;
    char userChoice, replay;
    int gainz = 0;
    srand(time(0));
        std::cout << "Welcome, ";
       do{
        std::cout << "Please push p to pull the lever or q to quit at any point\n";
        std::cout << "Wallet: $" << wallet << std::endl;

        do{

         std::cin >> userChoice;
            switch(std::tolower(userChoice)){
                case 'p':
                    wallet -=2;
                    std::cout << "Wallet: $" << wallet << std::endl;
                    firstSlot = FirstSlot();
                    std::cout << firstSlot << std::endl;
                    break;
                case 'q':
                    return;
                    break;
                default:
                    std::cout << "Please choose whether to pull the lever or quit\n";
                    break;
            }
        }while(std::tolower(userChoice) != 'q' && std::tolower(userChoice) != 'p');


        do{
            if(std::tolower(userChoice) == 'q'){
                break;
            }
            std::cin >> userChoice;
            switch(std::tolower(userChoice)){
                case 'p':
                    secondSlot = SecondSlot();
                    std::cout << firstSlot << " " << secondSlot << std::endl;
                    break;
                case 'q':
                    break;
                default:
                    std::cout << "Please choose whether to pull the lever or quit\n";
                    break;
            }
        }while(std::tolower(userChoice) != 'q' && std::tolower(userChoice) != 'p');


        do{
            if(std::tolower(userChoice) == 'q'){
                break;
            }
            std::cin >> userChoice;
            switch(std::tolower(userChoice)){
                case 'p':
                    thirdSlot = ThirdSlot();
                    std::cout << firstSlot << " " << secondSlot << " " << thirdSlot << std::endl;
                    gainz = SlotResults(firstSlot, secondSlot, thirdSlot);
                    wallet += gainz;
                    std::cout << "Payout: $" << gainz << std::endl;
                    std::cout << "Wallet: $" << wallet << std::endl;
                    break;
                case 'q':
                    break;
                default:
                    std::cout << "Please choose whether to pull the lever or quit\n";
                    break;
            }
        }while(std::tolower(userChoice) != 'q' && std::tolower(userChoice) != 'p');
        std::cout << "Would you like to play again?(y/n)\n";
        std::cin >> replay;
        while(std::tolower(replay) != 'y'&& std::tolower(replay) != 'n'){
            std::cout << "Please decide\n";
            std::cin >> replay;
        }
    }while(std::tolower(replay) == 'y');
}

#endif