//
//  Hand.hpp
//  BJBuddy
//
//  Created by Barry Nailor on 5/2/19.
//  Copyright © 2019 barrynailor. All rights reserved.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Hand{

protected:
    vector<int> cardsInHand;
    
public:
    
    //init with cards
    Hand(int card1, int card2){
        cardsInHand.push_back(card1);
        cardsInHand.push_back(card2);
    };
    //init without cards
    Hand(){
        cardsInHand.push_back(0);
        cardsInHand.push_back(0);
    };
    
    vector<int> GetCards(){
        return cardsInHand;
    };
    
    void AddCardToHand(int card);
    bool HandIsBust();
    bool HandHasAce();
    bool HasBlackjack();
    int HandValueWithAceAs11();
    int HandValueWithAceAs1();
    void DisplayCardsPlayer();
    void DisplayCardsDealer();
    bool DealerShouldStay();
    void DisplayFirstCard();
    void EmptyHand();
    
};

#endif /* Hand_hpp */
