#include "doctest.h"
#include "string"
#include "sources/game.hpp"
#include "sources/player.hpp"
#include "sources/card.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("construction & functions"){

   
    Player p1("Natan");
    Player p2("Yossi");
    
    //new game each 26 cards
    CHECK_EQ(p1.stacksize() , 26);
    CHECK_EQ(p2.stacksize() , 26);  

    CHECK_EQ(p1.cardesTaken() , 0);
    CHECK_EQ(p2.cardesTaken() , 0);
    
    CHECK_THROWS(Game(p1 , p1));

    Game game(p1 , p2);
    
    //not played yet
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printLog());
    CHECK_THROWS(game.printWiner());
    CHECK_THROWS(game.printStats());

    game.playTurn();
    CHECK(p1.stacksize() == (25 - 2*game.getDrawCount()));//for every draw player drop 2 cards
    CHECK(p2.stacksize() == (25 - 2*game.getDrawCount()));

    CHECK_NE(p1.cardesTaken() , p2.cardesTaken());//not equals
    bool flag = (p1.cardesTaken() == (2 + 4*game.getDrawCount())) || (p2.cardesTaken() == (2 + 4*game.getDrawCount()));//for every draw player take 4 cards
    CHECK(flag);

    game.playAll();
    CHECK_EQ(p1.stacksize() , 0);
    CHECK_EQ(p2.stacksize() , 0);
    CHECK_THROWS(game.playTurn());
    CHECK_NOTHROW(game.printWiner());



       
}

TEST_CASE("many games"){
    

    Player p1("Natan");
    Player p2("Yossi");
      
    for(int i=0 ; i<1000 ; i++){
        Game game(p1 , p2);
        int maxCurStackSize=26;
        while(p1.stacksize() > 0 && p2.stacksize() > 0){
            CHECK_NOTHROW(game.playTurn());
            CHECK_THROWS(game.printWiner());
            maxCurStackSize--;
            CHECK(p1.stacksize() <= maxCurStackSize);
            CHECK(p2.stacksize() <= maxCurStackSize);
            if(p1.stacksize() == 0 && p2.stacksize()==0){//end game
                if(p1.cardesTaken() == p2.cardesTaken()){//draw
                    CHECK_THROWS(game.printWiner());
                }
            }
        }
    }

    Game game(p1 , p2);
    game.playAll();
    CHECK_THROWS(game.playAll());
    CHECK_THROWS(game.playTurn());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printStats());
    

}