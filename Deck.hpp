//
//  Deck.hpp
//  BJBuddy
//
//  Created by Barry Nailor on 5/2/19.
//  Copyright © 2019 barrynailor. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

class Deck {
private:
    vector<int> theDeck;
    void RemoveCard(int);

public:
    Deck(){
        init_deck();
        srand(unsigned(time(NULL)));
    }
    
    void init_deck();
    
    int DrawCard();
    
};
#endif /* Deck_hpp */
