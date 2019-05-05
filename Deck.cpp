//
//  Deck.cpp
//  BJBuddy
//
//  Created by Barry Nailor on 5/2/19.
//  Copyright © 2019 barrynailor. All rights reserved.
//

#include "Deck.hpp"


void Deck::init_deck(){
    theDeck = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
}

//Remove card at given index
void Deck::RemoveCard(int cardIndex){
    theDeck.erase(theDeck.begin() + cardIndex);
}

//Return a card from the deck and remove that card from the deck.
int Deck::DrawCard(){
    
    int randCard = rand() % theDeck.size();
    RemoveCard(randCard);
    return theDeck[randCard];
}
