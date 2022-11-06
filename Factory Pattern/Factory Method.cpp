#include <iostream>
#include <string>
#include "Factory Method.h"
using namespace std;


Pizza::Pizza(PizzaIngredientFactory &pizzaIngredientIn, string nameIn)
{
    dough = std::move(pizzaIngredientIn.createDough());
    sauce = std::move(pizzaIngredientIn.createSauce());
    clam = std::move(pizzaIngredientIn.createClam());
    name = nameIn;
}

void Pizza::prepare()
{
    cout << "prepare cheese pizza" << endl;
    dough->print();
    sauce->print();
    clam->print();
}

void Pizza::bake() {
    cout << "Baking for 25 min at 350 degree" << endl;
}
void Pizza::cut() {
    cout << "Cutting pizza into diagonal slices" << endl;
}
void Pizza::box() {
    cout << "Placing pizza in pizza store box" << endl;
}


void CheesePizza ::prepare() {
    cout << "prepare " << name << "cheese pizza" << endl;
    dough->print();
    sauce->print();
    clam->print();
}

class VeggiePizza : public Pizza {
public:
    VeggiePizza(PizzaIngredientFactory &pizzaIngredientIn, string nameIn) : Pizza(pizzaIngredientIn, nameIn) {}
    void prepare() override;
};

void VeggiePizza ::prepare() {
    cout << "prepare " << name << "veggie pizza" << endl;
    dough->print();
    sauce->print();
    clam->print();
}

// --------------------------NYPizzaIngredientFactory----------------------------------------------------------
unique_ptr<Dough> NYPizzaIngredientFactory::createDough()
{
    return std::move(make_unique<ThinCrustDough>(ThinCrustDough()));
}

unique_ptr<Sauce> NYPizzaIngredientFactory::createSauce ()
{
    return std::move(make_unique<MarinaraSauce>(MarinaraSauce()));
}
unique_ptr<Clam> NYPizzaIngredientFactory::createClam ()
{
    return std::move(make_unique<FreshClam>(FreshClam()));
}


// --------------------------ChicagoPizzaIngredientFactory----------------------------------------------------------
unique_ptr<Dough> ChicagoPizzaIngredientFactory::createDough()
{
    return std::move(make_unique<ThickCrustDough>(ThickCrustDough()));
}

unique_ptr<Sauce> ChicagoPizzaIngredientFactory::createSauce ()
{
    return std::move(make_unique<PalmTomatoSauce>(PalmTomatoSauce()));
}
unique_ptr<Clam> ChicagoPizzaIngredientFactory::createClam ()
{
    return std::move(make_unique<FrozenClam>(FrozenClam()));
}




//---------------------------------------NYPizzaStore-------------------------------------------------------
std::unique_ptr<Pizza> NYPizzaStore::createPizza(PizzaType type) {
    switch (type) {
        case Cheese:
            return std::make_unique<CheesePizza>(nyPizzaIngredient, "NY");
        case Veggie:
            return std::make_unique<VeggiePizza>(nyPizzaIngredient, "NY");
        default:
            return std::make_unique<Pizza>(nyPizzaIngredient, "NY");
    }
}

//---------------------------------------ChicagoPizzaStore------------------------------------------------------
std::unique_ptr<Pizza> ChicagoPizzaStore::createPizza(PizzaType type) {
    switch (type) {
        case Cheese:
            return std::make_unique<CheesePizza>(chicagoPizzaIngredient, "Chicago");
        case Veggie:
            return std::make_unique<VeggiePizza>(chicagoPizzaIngredient, "Chicago");
        default:
            return std::make_unique<Pizza>(chicagoPizzaIngredient, "Chicago");
    }
}


int main()
{
    NYPizzaStore nyStore = NYPizzaStore();
    ChicagoPizzaStore chicagoStore = ChicagoPizzaStore();

    PizzaType type = Cheese;
    std::unique_ptr<Pizza> pizza = std::move(nyStore.orderPizza(type));
    std::unique_ptr<Pizza> pizza2 = std::move(chicagoStore.orderPizza(type));
}