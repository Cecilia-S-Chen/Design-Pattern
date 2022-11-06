#ifndef DESIGN_PATTERN_BASE_CLASS_H
#define DESIGN_PATTERN_BASE_CLASS_H
#include <iostream>
using namespace std;

/*
 * 模板方法定义：模板方法定义在基类中，该方法是算法骨架，将一些步骤延迟到子类中实现。
 *          模板方法使得子类在不改变算法结构的前提下，重新定义算法中的某些步骤。
 * 钩子（hook）: 基类中定义的"默认不做事的方法"。子类可以视情况决定是否要覆盖钩子。
 *          （1）钩子可以让子类实现算法中可选的部分
 *          （2）影响抽象类中的算法流程
 *          （2）让子类能够有机会对模板方法中的某些即将发生（或刚刚发生）的步骤作出反应（比如业务中勾到消息，打桩回复或储存消息等）
 * 好莱坞原则：别调用我，我会调用你。
 *      解释为：高层组件（基类）调用底层组件（子类）。底层组件不能调用高层组件。
 *      目的：避免循环依赖导致的依赖腐败。
 * */

class CaffeineBeverage {
public:
    void PrepareRecipe() {
        BoilWater();
        Brew();
        PourInCup();
        if (IfCustomerWantsCondiments()) {
            AddElements();
        }
    }
protected:
    void BoilWater() {cout << "Boil Water" << endl;}
    virtual void Brew() = 0;
    void PourInCup() { cout << "Pour In Cup" << endl; };
    virtual bool IfCustomerWantsCondiments() { return true; }
    virtual void AddElements() = 0;
};

#endif //DESIGN_PATTERN_BASE_CLASS_H
