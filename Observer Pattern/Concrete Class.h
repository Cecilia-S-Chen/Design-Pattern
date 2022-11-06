#ifndef DESIGN_PATTERN_CONCRETE_CLASS_H
#define DESIGN_PATTERN_CONCRETE_CLASS_H

#include "Abstract Class.h"
#include <unordered_set>

using namespace std;

class WeatherData : public Subject {
public:
    WeatherData() = default;
    void registerObserver(Observer o);
    void removeObserver(Observer o);
    void notifyObserver();
    void measurementChanged();
    void setMeasurements(float tempIn, float humidityIn, float pressureIn);
private:
    float temp;
    float humidity;
    float pressure;
    unordered_set<Observer> observerLst;
};



class CurrentConditionsDisplay : public Observer, DisplayElement {
public:
    CurrentConditionsDisplay(Subject &weatherDataIn);
    void update(float tempIn, float humidityIn, float pressureIn);
    void display();
private:
    float temp;
    float humidity;
    Subject *weatherData;
};
#endif //DESIGN_PATTERN_CONCRETE_CLASS_H
