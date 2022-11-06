#ifndef LEETCODE_SINGLETON_PATTERN_H
#define LEETCODE_SINGLETON_PATTERN_H

#include <pthread.h>
/*
 * 单例模式：
 * 1、核心：一个类只允许一个实例 = 一个类只能生成一个对象
 * 2、实现：类的构造函数为private或者protected，类内部保存一个static private类型的指针，指向类生成的对象
 *          类的生成对象操作由类的一个public方法代劳
 *   Ps:使用static类型指针，因为饿汉模式在实例化对象之前就使用该成员变量。
 * 3、类型：
 * 懒汉模式和饿汉模式
 */
class SingletonHungry {
private:
    SingletonHungry() {}
    static SingletonHungry* p;
public:
    static SingletonHungry* instance();
};

class SingletonLazy {
private:
    SingletonLazy() {}
    static SingletonLazy* p;
public:
    static SingletonLazy* instance();
};

/*
 * Linux互斥锁
 * 1、目的：线程同步运行时保证线程的安全性
 * 2、使用方式：
 *  pthread_mutex_t类有以下几个常用的成员函数：
 *  （1）pthread_mutex_init：锁的初始化
 *  （2）pthread_mutex_destory：锁的销毁
 *  （3）pthread_mutex_lock：上锁
 *  （4）pthread_mutex_unlock：解锁
 */
class SingletonLazyImprov {
private:
    SingletonLazyImprov() {}
    static SingletonLazyImprov* p;
public:
    static pthread_mutex_t mutex;
    static SingletonLazyImprov* instance();
};
#endif //LEETCODE_SINGLETON_PATTERN_H