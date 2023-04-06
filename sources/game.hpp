#pragma once
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel
{
    class Game
    {
    private:
        Player* player1;
        Player* player2;
        unsigned short DrawCount;
        float DrawRate;
        
        
    public:
        Game(Player& player1 , Player& player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        unsigned short getDrawCount();
        float getDrawRate();
        
        
    };
    

    
} // namespace ariel
