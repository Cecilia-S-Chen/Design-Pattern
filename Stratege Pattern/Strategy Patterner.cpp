#include <iostream>
using namespace std;
/*
 * 策略模式
 * 1、核心：策略模式针对对象的一组行为。针对一组算法，将每个算法封装进具有共同接口的子类中，从而使不同算法可以相互替换。
 * 2、优点：将对象和行为分离开，行为模式的改变不影响对象。
 * 3、缺点：客户端必须知道所有的策略类，并自行决定使用哪一个策略类。这就意味着客户端必须理解这些算法的区别，以便适时选择恰当的算法类。
 *          换言之，策略模式只适用于客户端知道算法或行为的情况。
 * 4、设计原则：
 *  （1）封装变化
 *  （2）针对接口编程，不针对实现编程
 *  （3）多用组合，少用继承
 *  （4）开闭原则

 */
class FlyBehavior {
public:
    virtual void fly() {};
};
class FlyWithWings : public FlyBehavior {
public:
    void fly() override {
        cout << "Fly With Wings" << endl;
    }
};
class FlyPoweredByRocket : public FlyBehavior {
public:
    void fly() override {
        cout << "Fly Powered By Rocket" << endl;
    }
};
class FlyNoWay : public FlyBehavior {
public:
    void fly() override {
        cout << "Can not Fly" << endl;
    }
};

class QuackBehavior {
public:
    virtual void quack() {};
};
class Quack : public QuackBehavior {
public:
    void quack() override {
        cout << "Quack Quack" << endl;
    }
};
class Squeak : public QuackBehavior {
public:
    void quack() override {
        cout << "Squeak Squeak" << endl;
    }
};
class Silence : public QuackBehavior {
public:
    void quack() override {
        cout << "Can not Quack" << endl;
    }
};

class Duck {
public:
    Duck(FlyBehavior *fbInput, QuackBehavior *qbInput) : fb(fbInput), qb(qbInput) {}
    void display(string s) {
        cout << s << endl;
    }
    void performFly() {
        fb->fly();
    }
    void performQuack() {
        qb->quack();
    }
    void setFlyBehavior(FlyBehavior *fbNew) {
        fb = fbNew;
    }
    void setQuackBehavior(QuackBehavior *qbNew) {
        qb = qbNew;
    }

private:
    FlyBehavior *fb;
    QuackBehavior *qb;
};

int main() {
    FlyBehavior *fb = new FlyWithWings();
    QuackBehavior *qb = new Quack();
    FlyBehavior *fbNew = new FlyPoweredByRocket();

    Duck redHeadDuck(fb, qb);
    redHeadDuck.display("Red Head Duck");
    redHeadDuck.performFly();
    redHeadDuck.performQuack();
    redHeadDuck.setFlyBehavior(fbNew);
    redHeadDuck.performFly();

    delete fb;
    delete qb;
}

