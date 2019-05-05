//
//  main.cpp
//  BJBuddy
//
//  Created by Barry Nailor on 4/27/19.
//  Copyright © 2019 barrynailor. All rights reserved.
//

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "OddsCalculator.cpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "DealerHand.hpp"

bool CheckStayValue(vector<int>);
void DisplayRules();
void PromptForChoice();
void DisplayWinner(Hand,Hand);
void MakeSpace();
vector<int> hitRecord;

int main(int argc, const char * argv[]) {
    
    
    bool newGame = true;
    
    while(newGame){
        MakeSpace();
        //List Rules
        DisplayRules();
        //deal cards
        Deck myDeck = Deck();
        //init players hand by drawing two cards
        Hand playerHand = Hand(myDeck.DrawCard(),myDeck.DrawCard());
        //init dealer hand by drawing two cards
        Hand dealerHand = Hand(myDeck.DrawCard(),myDeck.DrawCard());
        
        bool contPlaying = true;
        while(contPlaying){
            //Show dealer card
            dealerHand.DisplayFirstCard();
            //Show player cards
            playerHand.DisplayCardsPlayer();
            //Show odds
            OddsCalculator odds;
            //player odds
            vector<double> playerOdds = odds.ProgressiveTargetOdds17to21(playerHand.HandValueWithAceAs1());
            //dealer odds
            vector<double> dealerOdds = odds.ProgressiveTargetOdds17to21(dealerHand.GetCards()[0]);
            //reformat odds and display
            
            for(int x = 0; x < playerOdds.size(); x++){
                playerOdds[x] = playerOdds[x] * 100;
                dealerOdds[x] = dealerOdds[x] * 100;
            }
            //display odds
            int start = 17;
            cout<<"Odds for dealer: "<<endl;
            for(int x = 0; x < dealerOdds.size(); x++){
                cout<<start<<" = "<<setprecision(2)<<dealerOdds[x]<<"%  ";
                start++;
            }
            cout<<endl<<endl;
            start = 17;
            cout<<"Odds for player: "<<endl;
            for(int x = 0; x < playerOdds.size(); x++){
                cout<<start<<" = "<<setprecision(2)<<playerOdds[x]<<"%  ";
                start++;
            }
            cout<<endl<<endl;
            //Prompt for choice
            PromptForChoice();
            int choice;
            bool validEntry = false;
            while(!validEntry){
                cout<<"Enter Choice: ";
                cin >> choice;
                if(choice == 1 || choice == 2 || choice == 3){
                    validEntry = true;
                }
                else {
                    cout<<"Invalid Entry"<<endl;
                }
            }
            MakeSpace();
            switch(choice){
                case 1:
                    playerHand.AddCardToHand(myDeck.DrawCard());
                    if(playerHand.HandIsBust()){
                        DisplayWinner(playerHand, dealerHand);
                        contPlaying = false;
                    }
                    break;
                case 2:
                    //finish dealer hand
                    while(!dealerHand.DealerShouldStay()){
                        dealerHand.AddCardToHand(myDeck.DrawCard());
                    }
                    //show all cards and declare winner
                    DisplayWinner(playerHand, dealerHand);
                    contPlaying = false;
                    break;
                case 3:
                    return 0;
            }


        }
        bool validEntry = false;
        char playAgain;
        while(!validEntry){
            cout<<"Play again Y or N? ";
            cin>>playAgain;
            if(playAgain == 'y' || playAgain == 'Y'){
                validEntry = true;
                newGame = true;
            }
            else if(playAgain == 'n' || playAgain == 'N'){
                validEntry = true;
                newGame = false;
            }
            else {
                validEntry = false;
                cout << "Invalid entry" << endl;
            }
        }

    }


    return 0;
}

void DisplayRules(){
    cout<<"****BJ Buddy****"<<endl;
    cout<<"This application will deal a hand of blackjack."<<endl;
    cout<<"It will display odds and prompt a move."<<endl<<endl;
}


void PromptForChoice(){
    cout<<"1 = Hit, 2 = Stay, 3 = Quit"<<endl;
}

void DisplayWinner(Hand player, Hand dealer){
    dealer.DisplayCardsDealer();
    player.DisplayCardsPlayer();
    if(player.HandIsBust()){
        cout<<"Bust! You lose."<<endl;
    }
    else if(dealer.HandIsBust()){
        cout<<"Dealer is bust, you win!"<<endl;
    }
    else {
        int dealerValue, playerValue;
        if(dealer.HandHasAce()){
            dealerValue = dealer.HandValueWithAceAs11() <= 21 ? dealer.HandValueWithAceAs11() : dealer.HandValueWithAceAs1();
        } else dealerValue = dealer.HandValueWithAceAs1();
        if(player.HandHasAce()){
            playerValue = player.HandValueWithAceAs11() <= 21 ? player.HandValueWithAceAs11() : player.HandValueWithAceAs1();
        } else playerValue = player.HandValueWithAceAs1();
        
        if(dealerValue > playerValue){
            cout<<"Dealer Wins"<<endl;
        }
        else if(playerValue > dealerValue){
            cout<<"Player Wins"<<endl;
        }
        //draw
        else {
            cout<<"Draw!"<<endl;
        }
    }
}

void MakeSpace(){
    for(int x = 0; x < 50; x++){
        cout<<endl;
    }
}
