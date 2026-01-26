#include <iostream>
#include <string>
using namespace std;

enum class pizzaSize {SMALL, MEDIUM, LARGE, EXTRA_LARGE};

int getPrice(pizzaSize size){
    switch(size){
        case pizzaSize::SMALL: return 50000;
        case pizzaSize::MEDIUM: return 80000;
        case pizzaSize::LARGE: return 120000;
        case pizzaSize::EXTRA_LARGE: return 150000;
        default: return 0;
    }
}
string getSizename(pizzaSize size){
    switch(size){
        case pizzaSize::SMALL:          return "SMALL";
        case pizzaSize::MEDIUM:         return "MEDIUM";
        case pizzaSize::LARGE:          return "LARGE";
        case pizzaSize::EXTRA_LARGE:    return "EXTRA_LARGE";
        default:                        return "UNKNOWN";             
    }
}
void printPizzaInfo(pizzaSize size){
    cout << "Size: " << getSizename(size)
         << " - price: "<< getPrice(size) << " VND" << endl;
}
int main(){
    pizzaSize size = pizzaSize::MEDIUM;

    cout << "Ban da chon pizza: " << endl;
    printPizzaInfo(size);

    return 0;
}