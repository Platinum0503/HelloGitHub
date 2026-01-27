#include <iostream>
#include <string>
using namespace std;

enum class Suit {HEARTS, DIAMOND, CLUBS, SPADES};
enum class Rank {TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT
                , NINE, TEN, JACK, QUEEN, KING, ACE};

struct cardGame
{
    Suit suit;
    Rank rank;
};

string suitName(Suit c){
    switch(c){
        case Suit::HEARTS:  return "HEARTS";
        case Suit::DIAMOND: return "DIAMOND";
        case Suit::CLUBS:   return "CLUBS";
        case Suit::SPADES:  return "SPADES";
        default: return "Khong xac dinh";
    }
}
string getRankName(Rank r){
    switch(r){
        case Rank::TWO:     return "TWO";
        case Rank::THREE:   return "THREE";
        case Rank::FOUR:    return "FOUR";
        case Rank::FIVE:    return "FIVE";
        case Rank::SIX:     return "SIX";
        case Rank::SEVEN:   return "SEVEN";
        case Rank::EIGHT:   return "EIGHT";
        case Rank::NINE:    return "NINE";
        case Rank::TEN:     return "TEN";
        case Rank::JACK:    return "JACK";
        case Rank::QUEEN:   return "QUEEN";
        case Rank::KING:    return "KING";
        case Rank::ACE:     return "ACE";
        default: return "Khong xac dinh";
    }
}
void printCard(cardGame c){
    cout << getRankName(c.rank) << " of " << suitName(c.suit);
}
int getCardValue(cardGame c){
    int rankValue = static_cast<int>(c.rank); //convert enum sang int

    //J, Q, K= 10 point
    if(rankValue >= static_cast<int>(Rank::JACK) &&
        rankValue <= static_cast<int>(Rank::KING)){
            return 10;
        }

    if(c.rank == Rank::ACE){
        return 11;
    }

    return  rankValue;
}   
int compareCards(cardGame c1, cardGame c2){
    int value1 = static_cast<int>(c1.rank);
    int value2 = static_cast<int>(c2.rank);

    if(value1 > value2){
        return 1; //c1 greater than
    } else if (value1 < value2){
        return -1; //c2 greater than
    }else {
        return 0; //bang nhau
    }
    
    // Return 1: Card 1 thắng
    //Return -1: Card 2 thắng
    //Return 0: Hòa
}
int main(){
    cardGame card1 = {Suit::SPADES, Rank::ACE};
    cardGame card2 = {Suit::HEARTS, Rank::KING};
    cardGame card3 = {Suit::CLUBS, Rank::FIVE};
    
    cout << "\n=== TEST PRINT CARD ===\n";
    printCard(card1); cout << endl;
    printCard(card2); cout << endl;
    printCard(card3); cout << endl;

    cout << "\n=== TEST CARD VALUE ===" << endl;
    cout << "Value of "; printCard(card1);
    cout << ": " << getCardValue(card1) << endl;

    cout << "Value of "; printCard(card2); 
    cout << ": " << getCardValue(card2) << endl;

    cout << "\n=== TEST COMPARE ===" << endl;
    int result = compareCards(card1, card2);

    printCard(card1); cout << " VS "; printCard(card2);
    if(result > 0){
        cout << " -> Card 1 Wins!" << endl;
    } else if(result < 0){
        cout << " -> Card 2 Wins!" << endl;
    } else {
        cout << " -> Tie!" << endl;
    }

    return 0;
}