#pragma once
#include <string>

using namespace std;

namespace ariel
{
    class Player
    {
    private:
        string Name;
        unsigned short StackSize;//the amount of card left
        unsigned short CardesTaken;//the amount of card win's
        float WinRate;
        

    public:
        
        Player(string Name);//constructor
        unsigned short stacksize();
        unsigned short cardesTaken();
        float getPlayerWinRate();


        
    };
    
          
}// namespace ariel
    