#pragma once
#include "IModifier.h"

class ModifierFactory {
public:
    static IModifier* createModifier(int type) {
        if (type == 1) return new BoostFlat();
        if (type == 2) return new UpgradeMult();
        return nullptr;
    }
};