//
//  DealerHand.cpp
//  BJBuddy
//
//  Created by Barry Nailor on 5/2/19.
//  Copyright © 2019 barrynailor. All rights reserved.
//

#include "DealerHand.hpp"


//returns true if the dealer should stay, dealer will stay on hard 17, hit on soft 17 
bool DealerHand::DealerShouldStay(){
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
void DealerHand::DisplayFirstCard(){
    vector<int> Cards = GetCards();
    cout<<"Dealer shows "<<Cards[0]<<endl;
}
