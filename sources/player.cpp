#include "player.hpp"
#include <string>

using namespace std;

namespace ariel
{
    //constructor
    Player::Player(string name){
        this->Name = name;
        this->StackSize = 0;
        this->CardesTaken = 0;
        this->WinRate = 0;
    };

    unsigned short Player::stacksize(){
        return this->StackSize;
    }

    unsigned short Player::cardesTaken(){
        return this->CardesTaken;
    }
    
    float Player::getPlayerWinRate(){
        return this->WinRate;
    }




} // namespace ariel







