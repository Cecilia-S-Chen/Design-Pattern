#ifndef DESIGN_PATTERN_INGREDIENT_H
#define DESIGN_PATTERN_INGREDIENT_H

#include <iostream>
#include <string>
using namespace std;

enum PizzaType {
    Cheese = 0,
    Veggie = 1,
};


class Dough {
public:
    virtual void print() {
        cout << "Dough is normal dough" << endl;
    }
};
class ThinCrustDough : public Dough {
public:
    void print() {
        cout << "Dough is ThinCrustDough" << endl;
    }
};
class ThickCrustDough : public Dough {
public:
    void print() {
        cout << "Dough is ThickCrustDough" << endl;
    }
};


class Sauce {
public:
    virtual void print() {
        cout << "Dough is normal dough" << endl;
    }
};
class MarinaraSauce : public Sauce {
public:
    void print() override {
        cout << "Sauce is MarinaSauce" << endl;
    }
};
class PalmTomatoSauce : public Sauce {
public:
    void print() override {
        cout << "Sauce is PalmTomatoSauce" << endl;
    }
};

class Clam {
public:
    virtual void print() {
        cout << "Dough is normal dough" << endl;
    }
};
class FreshClam : public Clam {
public:
    void print() {
        cout << "Clam is FreshClam" << endl;
    }
};
class FrozenClam : public Clam {
public:
    void print() {
        cout << "Clam is FrozenClam" << endl;
    }
};

#endif //DESIGN_PATTERN_INGREDIENT_H
