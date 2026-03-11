#include "RunSession.h"
#include "ModifierFactory.h"
#include <iostream>

RunSession::RunSession() : money(0), currentRound(1) {}

void RunSession::startRun() {
    std::cout << "=== RUN START ===\n";
    while (currentRound <= 3) {
        std::cout << "\n--- ROUND " << currentRound << " ---\n";
        selectBlind();
        generateHand();
        chooseCards();
        calculateScore();
        resolveReward();
        openShop();
        currentRound++;
    }
    std::cout << "\n=== RUN END. Final Money: $" << money << " ===\n";
}

void RunSession::selectBlind() { std::cout << "[SYSTEM] Blind tantangan dipilih.\n"; }
void RunSession::generateHand() { std::cout << "[SYSTEM] Kartu dibagikan ke pemain.\n"; }
void RunSession::chooseCards() { std::cout << "[PLAYER] Pemain memilih kombinasi kartu.\n"; }

void RunSession::calculateScore() {
    int score = 50; // Skor dasar dari kombinasi
    std::cout << "[SCORE] Skor dasar: " << score << "\n";
    for (auto m : inventory) {
        score = m->transformScore(score);
        std::cout << "[MOD] Efek aktif: " << m->getName() << "\n";
    }
    std::cout << "[SCORE] Skor akhir ronde: " << score << "\n";
}

void RunSession::resolveReward() {
    money += 15;
    std::cout << "[REWARD] Berhasil menang! Dapat $15. Total: $" << money << "\n";
}

void RunSession::openShop() {
    std::cout << "[SHOP] Memasuki toko. Membeli Upgrade Mult...\n";
    inventory.push_back(ModifierFactory::createModifier(2)); // Memakai Factory
}