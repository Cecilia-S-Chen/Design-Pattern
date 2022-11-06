#include "Hungry And Lazy.h"
using namespace std;
/*
 * 饿汉模式：
 * 1、定义：无论是否要使用该类的实例，在程序开始时就产生该类的实例（让人有它很饥饿的感觉）
 * 2、优点：线程安全。因为通过单线程的方式实例化
 *    缺点：浪费空间。即使不使用，也产生该类实例
 */
SingletonHungry* SingletonHungry::p = new SingletonHungry();
SingletonHungry* SingletonHungry::instance()
{
    return p;
}

/*
 * 懒汉模式：
 * 1、定义：在使用该实例时再初始化
 * 2、优点：不浪费空间。避免出现初始化实例后不需要使用的情况
 *    缺点：线程不安全。假设两个线程 同时首次 调用该类的静态方法instance(),则两个线程会各自实例化。从而产生多例
 */
SingletonLazy* SingletonLazy::p = nullptr;
SingletonLazy* SingletonLazy::instance()
{
    p = nullptr;
    if (p) {
        p = new SingletonLazy();
    }
    return p;
}

/*
 * 问题：懒汉模式线程不安全
 * 解决方式：上锁+双重校验
 */

SingletonLazyImprov* SingletonLazyImprov::p = nullptr;
SingletonLazyImprov* SingletonLazyImprov::instance()
{
    // 先校验是否p为空再加锁，能提高效率
    if (p == nullptr) {
        pthread_mutex_init(&mutex);
        pthread_mutex_lock(&mutex);
        if (p == nullptr) {
            p = new SingletonLazyImprov();
        }
        pthread_mutex_unlock(&mutex);
    }
    return p;
}
