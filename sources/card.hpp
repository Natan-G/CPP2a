#pragma once
#include <string>

using namespace std;

namespace ariel
{
    class Card
    {
    private:
        int cardValue;
        string shape;
        string color;

    public:    
        Card(int value , string shape , string color);
        
    };
    

} // namespace ariel
