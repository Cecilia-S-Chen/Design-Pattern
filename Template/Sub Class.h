#ifndef DESIGN_PATTERN_SUB_CLASS_H
#define DESIGN_PATTERN_SUB_CLASS_H

#include "Base Class.h"


class Tea final : public CaffeineBeverage {
public:
    void Brew() final { cout << "Step Tea Bag" << endl; }
    void AddElements() final { cout << "Add Lemon" << endl; }
};

class Coffee final : public CaffeineBeverage {
public:
    void Brew() final { cout << "Brew Coffee Grinds" << endl; }
    void AddElements() final { cout << "Add Sugar And Milk" << endl; }
};
#endif //DESIGN_PATTERN_SUB_CLASS_H
