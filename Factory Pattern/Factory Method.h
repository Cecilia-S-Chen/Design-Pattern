#ifndef DESIGN_PATTERN_FACTORY_METHOD_H
#define DESIGN_PATTERN_FACTORY_METHOD_H

#include "Ingredient.h"
/*
 * 工厂模式：
 * 1、目的：封装""对象创建
 * 2、优点：将程序的变化和不变解耦，符合开闭原则
 * 3、工厂方法和抽象工厂的区别：
 *  （1）工厂方法：通过"继承"。生产"一个"产品
 *  （2）抽象工厂：通过"组合"。生产"一组"产品
 */


/*
 * 抽象工厂模式：
 *  目的：生产"一组"对象
 *  tips：抽象工厂可以利用工厂方法生产对象
 */
class PizzaIngredientFactory {
public:
    virtual unique_ptr<Dough> createDough() = 0;
    virtual unique_ptr<Sauce> createSauce() = 0;
    virtual unique_ptr<Clam> createClam() = 0;
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    unique_ptr<Dough> createDough() override;
    unique_ptr<Sauce> createSauce ()override;
    unique_ptr<Clam> createClam () override;

};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    unique_ptr<Dough> createDough() override;
    unique_ptr<Sauce> createSauce ()override;
    unique_ptr<Clam> createClam () override;

};


class Pizza {
public:
    Pizza(PizzaIngredientFactory &pizzaIngredientIn, string nameIn);
    virtual void prepare();
    static void bake();
    static void cut();
    static void box();

public:
    unique_ptr<Dough> dough;
    unique_ptr<Sauce> sauce;
    unique_ptr<Clam> clam;
    string name;
};

class CheesePizza : public Pizza {
public:
    CheesePizza(PizzaIngredientFactory &pizzaIngredientIn, string nameIn) : Pizza(pizzaIngredientIn, nameIn) {}
    void prepare() override;
};


/* 工厂方法：
 * 目的：工厂方法用于封装 生成对象
 * 核心：工厂方法将 生成具体对象 推迟到子类中实现。
 * 设计原则：
 *  (1)依赖倒置。高层组件和低层组件都依赖抽象对象。
 *      在本例中各种具体Pizza为低层组件，各种PizzaStore为高层组件。为了避免高层组件依赖低层组件，抽象出Pizza类，让高层组件和底层组件都依赖抽象类
 *  (2)封装变化的部分
 * （3）依赖接口编程，不依赖实现编程
 */
class PizzaStore {
public:
    std::unique_ptr<Pizza> orderPizza(PizzaType type);
protected:
    virtual std::unique_ptr<Pizza> createPizza(PizzaType type) = 0;
};

std::unique_ptr<Pizza> PizzaStore::orderPizza(PizzaType type) {
    std::unique_ptr<Pizza> pizza = createPizza(type);
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
    return std::move(pizza);
}

class NYPizzaStore : public PizzaStore {
public:
    NYPizzaStore() {}
protected:
    std::unique_ptr<Pizza> createPizza(PizzaType type) override;
private:
    NYPizzaIngredientFactory nyPizzaIngredient;
};


class ChicagoPizzaStore : public PizzaStore {
public:
    ChicagoPizzaStore() {}
protected:
    std::unique_ptr<Pizza> createPizza(PizzaType type) override;
private:
    ChicagoPizzaIngredientFactory chicagoPizzaIngredient;
};


#endif //DESIGN_PATTERN_FACTORY_METHOD_H
