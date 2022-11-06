#include <iostream>
using namespace std;

/*
 * 装饰者模式
 * 1、核心：让装饰者和被装饰者继承同一个类。强调继承中的"兄弟关系"，而非"父子关系"。
 * 2、目的：是让装饰者和被装饰者有相同的接口，从而让装饰者可以"取代"被装饰者
 * 3、优势："兄弟关系"，说明装饰者和被装饰者是组合关系，而非继承关系。利用继承设计的子类行为是在编译时静态决定的。而利用组合，可以在运行时动态的扩展
 * 4、设计原则：开闭原则。类应该对扩展开发，对修改关闭。
 *      （1）缺点：过度适用开闭原则，会引入新的适配层，增加代码复杂度。
 */

class Beverage {
public:
    virtual string getDescription() {}
    virtual double cost() {}
};

class CondimentDecorator : public Beverage {
};


class Espresso : public Beverage {
public:
    string getDescription () {
        return "Espresso";
    }
    double cost() {
        return 1.99;
    }
};

class HouseBlend : public Beverage {
public:
    string getDescription () {
        return "HouseBlend";
    }
    double cost() {
        return 1.69;
    }
};


class Mocha : public CondimentDecorator {
public:
    Mocha(Beverage &b) {
        beverage = &b;
    }
    string getDescription() {
        return beverage->getDescription() + "Mocha";
    }
    double cost() {
        return beverage->cost() + 0.2;
    }
private:
    Beverage *beverage;
};

class Whip : public CondimentDecorator {
public:
    Whip(Beverage &b) {
        beverage = &b;
    }
    string getDescription() {
        return beverage->getDescription() + "Whip";
    }
    double cost() {
        return beverage->cost() + 0.4;
    }
private:
    Beverage *beverage;
};

int main() {
    Beverage *beverage = new Espresso();
    cout << beverage->getDescription() << ", " << beverage->cost() << "$" << endl;

    Beverage *beverage1 = new HouseBlend();
    beverage1 = new Mocha(*beverage1);
    beverage1 = new Whip(*beverage1);
    beverage1 = new Whip(*beverage1);
    cout << beverage1->getDescription() << ", " << beverage1->cost() << "$" << endl;

    delete beverage;
    delete beverage1;
}