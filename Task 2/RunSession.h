#pragma once
#include <vector>
#include "IModifier.h"

class RunSession {
private:
    int money;
    int currentRound;
    std::vector<IModifier*> inventory;

public:
    RunSession();
    void startRun(); // Menjalankan loop utama
    
    // Fase-fase (Invariant Phases)
    void selectBlind();    
    void generateHand();   
    void chooseCards();    
    void calculateScore(); 
    void resolveReward();  
    void openShop();       
};