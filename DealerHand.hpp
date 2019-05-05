//
//  DealerHand.hpp
//  BJBuddy
//
//  Created by Barry Nailor on 5/2/19.
//  Copyright © 2019 barrynailor. All rights reserved.
//

#ifndef DealerHand_hpp
#define DealerHand_hpp

#include <stdio.h>
#include <iostream>
#include "Hand.hpp"

using namespace std;

class DealerHand:Hand{
public:
    DealerHand(int card1, int card2)
    :Hand(card1, card2){};
    
    DealerHand():Hand(){};
    
    bool DealerShouldStay();
    void DisplayFirstCard();
};

#endif /* DealerHand_hpp */
