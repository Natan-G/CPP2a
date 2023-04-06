#include <stdio.h>
#include "string"
#include "game.hpp"
#include "card.hpp"
#include "player.hpp"

namespace ariel{

   Game::Game(Player& player1 , Player& player2){
      this->DrawCount = 0;
      this->DrawRate = 0;
   }
   void Game::playTurn(){

   };
   void Game::printLastTurn(){

   };

   void Game::playAll(){

   }

   void Game::printWiner(){

   }

   void Game::printLog(){

   }

   void Game::printStats(){
    
   }

   unsigned short Game::getDrawCount(){
      return this->DrawCount;
   }

   float Game::getDrawRate(){
      return this->DrawRate;
   }
  
   
}
