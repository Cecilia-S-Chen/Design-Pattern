#include "Abstract Class.h"
#include "Concrete Class.h"

/*
 * 观察者模式：
 * 1、核心：将观察者和被观察者解绑
 * （1）被观察者不感知观察者（换言之，被观察不关心观察者是谁，都同一套通知方法）
 * （2）观察者可以随时加入或退出观察
 * 2、定义：观察者模式定义了对象一对多依赖。当被观察者变化时，所有观察者都会收到通知并自动更新。
 * 3、设计原则：为交互对象之间的松耦合设计而努力
 */

int main()
{
    WeatherData *weatherData = new WeatherData();
    CurrentConditionsDisplay current(*weatherData);
    weatherData->setMeasurements(80, 65, 30.4);
    weatherData->setMeasurements(82, 70, 29.4);
    delete weatherData;
}

