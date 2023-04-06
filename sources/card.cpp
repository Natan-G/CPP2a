
#include <string>
#include "card.hpp"

using namespace std;

namespace ariel
{
    
    Card::Card(int value , string shape , string color){
        this->cardValue = value;
        this->shape = shape;
        this->color = color;
    };    


} // namespace ariel



