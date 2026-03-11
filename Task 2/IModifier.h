#pragma once
#include <string>

class IModifier {
public:
    virtual ~IModifier() {}
    virtual std::string getName() = 0;
    virtual int transformScore(int currentScore) = 0;
};

// Implementasi Konkrit 1
class BoostFlat : public IModifier {
public:
    std::string getName() override { return "Boost Flat (+10)"; }
    int transformScore(int s) override { return s + 10; }
};

// Implementasi Konkrit 2
class UpgradeMult : public IModifier {
public:
    std::string getName() override { return "Upgrade Mult (x2)"; }
    int transformScore(int s) override { return s * 2; }
};