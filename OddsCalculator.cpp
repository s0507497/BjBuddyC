//
//  OddsCalculator.cpp
//  BJBuddy
//
//  Created by Barry Nailor on 4/27/19.
//  Copyright © 2019 barrynailor. All rights reserved.
//

#include "OddsCalculator.hpp"
#include <vector>

using namespace std;

class OddsCalculator {
    private:
        const int BaseOdds[19][7][2] =
        {
            {{1,4},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0}},
            {{1,4},{2,12},{3,0},{4,0},{5,0},{6,0},{7,0}},
            {{1,4},{2,32},{3,24},{4,0},{5,0},{6,0},{7,0}},
            {{1,4},{2,44},{3,144},{4,24},{5,0},{6,0},{7,0}},
            {{1,4},{2,64},{3,288},{4,384},{5,0},{6,0},{7,0}},
            {{1,4},{2,76},{3,552},{4,1248},{5,480},{6,0},{7,0}},
            {{1,4},{2,96},{3,816},{4,3072},{5,3360},{6,0},{7,0}},
            {{1,4},{2,108},{3,1200},{4,5880},{5,11040},{6,4320},{7,0}},
            {{1,4},{2,128},{3,1608},{4,9984},{5,28800},{6,23040},{7,0}},
            {{1,16},{2,140},{3,2112},{4,15936},{5,58080},{6,89280},{7,20160}},
            {{1,4},{2,192},{3,2112},{4,16416},{5,67584},{6,122880},{7,63360}},
            {{1,0},{2,248},{3,3528},{4,31752},{5,169248},{6,449568},{7,449280}},
            {{1,0},{2,256},{3,4456},{4,42112},{5,249024},{6,787584},{7,1050816}},
            {{1,0},{2,236},{3,5392},{4,60472},{5,388608},{6,1496640},{7,2796672}},
            {{1,0},{2,224},{3,6520},{4,80512},{5,597024},{6,2643072},{7,6238272}},
            {{1,0},{2,204},{3,7312},{4,106584},{5,869856},{6,4323168},{7,12435264}},
            {{1,0},{2,192},{3,8176},{4,133888},{5,1261920},{6,7058304},{7,23726784}},
            {{1,0},{2,172},{3,8728},{4,166240},{5,1739424},{6,10955328},{7,42100416}},
            {{1,0},{2,160},{3,9328},{4,199552},{5,2353728},{6,16787712},{7,72477504}}
        };
        int GetPrevComb(int curIndex, int curCombSize, int distance){
            //from 0 to current combo size
            //reduce combo size and index
            //reduce combo size til 0
            //reset combo size - 1, index - 1
            int prevIndex = curIndex - 1;
            int prevCombSize = curCombSize - 1;
            int totalToRemove = 0;
            int tempTotal = 0;
            while(distance > 0){
                for(int i = 0; i < prevCombSize; i++){
                    tempTotal += BaseOdds[prevIndex][i][1];
                }
                totalToRemove += tempTotal * 4;
                tempTotal = 0;
                prevIndex--;
                distance--;
            }
            if(BaseOdds[curIndex][curCombSize - 1][1] - totalToRemove < 0) totalToRemove = BaseOdds[curIndex][curCombSize - 1][1];
            
            return totalToRemove;
        }
    
   
    
    public:
        OddsCalculator(){};
    
        vector<double> ProgressiveTargetOdds17to21(int cardsValue){
            vector<double> progressiveOdds = {0,0,0,0,0};
            int value = 0;
            int target = 17;
            for(int i = 0; i < 5; i++){ //loop for 17 to 21
                value = target - cardsValue;
                int valueIndex = value - 1;
                for(int comboSizeIndex = 0; comboSizeIndex < 7; comboSizeIndex++){
                    if(BaseOdds[valueIndex][comboSizeIndex][0] != 1 && BaseOdds[valueIndex][comboSizeIndex][1] == 0) break;
                    //get bottom, bottom reduced deck size for each card drawn
                    double bottom = 1.00;
                    double reducingBottom = 52.00;
                    for(int x = 0; x < BaseOdds[valueIndex][comboSizeIndex][0]; x++){
                        bottom *= reducingBottom;
                        reducingBottom--;
                    }
                    double top = BaseOdds[valueIndex][comboSizeIndex][1]; //top = number of combinations
//                    if(comboSizeIndex == 0){ //if player has a card needed in there hand, reduce probabilty
//                        if(card1 == value) top -= 4 * (1/(4*deckSize));
//                        if(card2 == value) top -= 4 * (1/(4*deckSize));
//                    }
                    if(target != 17 && comboSizeIndex > 0){
                        int distance = target - 17;
                        int numToRemove = GetPrevComb(valueIndex, comboSizeIndex + 1, distance);
                        top -= numToRemove;
                    }
                    progressiveOdds[i] += top/bottom;
                }
                target++; // 17,18,19,20,21
            }
            
            return progressiveOdds;
        }
    
    
};


