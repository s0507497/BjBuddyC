//
//  Hand.cpp
//  BJBuddy
//
//  Created by Barry Nailor on 5/2/19.
//  Copyright © 2019 barrynailor. All rights reserved.
//

#include "Hand.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



void Hand::AddCardToHand(int card){
    cardsInHand.push_back(card);
};

//return true if hand total value is greater than 21
bool Hand::HandIsBust(){
    int handTotal = 0;
    //add up cards in hand
    for(int i = 0; i < cardsInHand.size(); i++){
        handTotal += cardsInHand[i];
    }
    if(handTotal > 21) return true;
    return false;
}

//returns the total value of the cards with aces being 1
int Hand::HandValueWithAceAs1(){
    int handTotal = 0;
    //add up cards in hand
    for(int i = 0; i < cardsInHand.size(); i++){
        handTotal += cardsInHand[i];
    }
    return handTotal;
};

//returns the total value of the cards with an ace as 11, if hand does not have an ace, returns the hands value
int Hand::HandValueWithAceAs11(){
    int handTotal = 0;
    //add up cards in hand
    for(int i = 0; i < cardsInHand.size(); i++){
        handTotal += cardsInHand[i];
    }
    //check for ace
    if(HandHasAce()){
        handTotal += 10;
    }
    
    return handTotal;
};

//function returns true if hand contains an ace
bool Hand::HandHasAce(){
    if(find(cardsInHand.begin(), cardsInHand.end(), 1) != cardsInHand.end()){
        return true;
    }
    return false;
};

//returns true if the hand has a blackjack (21)
bool Hand::HasBlackjack(){
    if(!HandHasAce()){
        if(HandValueWithAceAs1() == 21) return true;
        else return false;
    }
    else{
        if(HandValueWithAceAs11() == 21 || HandValueWithAceAs1() == 21) return true;
        else return false;
    }
};

void Hand::DisplayCardsPlayer(){
    cout<<"You have ";
    for(int x = 0; x < cardsInHand.size(); x++){
        cout<<cardsInHand[x]<<"  ";
    }
    cout<<endl;
};

void Hand::DisplayCardsDealer(){
    cout<<"Dealer has ";
    for(int x = 0; x < cardsInHand.size(); x++){
        cout<<cardsInHand[x]<<"  ";
    }
    cout<<endl;
};

bool Hand::DealerShouldStay(){
    //if no ace
    if(!HandHasAce()){
        if(HandValueWithAceAs1() >= 17) return true;
        else return false;
    }
    
    //if ace
    else {
        if(HandValueWithAceAs11() > 17 || HandValueWithAceAs1() >= 17) return true;
        else return false;
    }
};

//Display one card for the dealer
void Hand::DisplayFirstCard(){
    vector<int> Cards = GetCards();
    cout<<"Dealer shows "<<Cards[0]<<endl;
}

void Hand::EmptyHand(){
    cardsInHand.clear();
}
