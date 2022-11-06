#ifndef DESIGN_PATTERN_ADAPTER_H
#define DESIGN_PATTERN_ADAPTER_H

/*
 * 适配器模式：
 * 1、作用：将A接口转化成B接口。使不兼容的接口能够在解耦的前提下合作。
 * 2、分类：对象适配器和类适配器.对象适配器采用组合，类适配器采用继承。
 */
class Duck {
public:
    virtual void quack();
    virtual void fly();
};

class Turkey {
public:
    void gobble();
    void fly();
};

// 对象适配器
class TurkeyAdapter : public Duck {
public:
    TurkeyAdapter(const Turkey &tIn);
    void quack();
    void fly();

private:
    Turkey t;
};

// 类适配器
class TurkeyClassAdapter : public Duck, public Turkey {
public:
    void quack();
    void fly();
};
#endif //DESIGN_PATTERN_ADAPTER_H
