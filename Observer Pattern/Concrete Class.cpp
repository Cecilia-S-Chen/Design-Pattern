#include "Concrete Class.h"
#include "Abstract Class.h"
#include <iostream>

using namespace std;

void WeatherData::registerObserver(Observer o)
{
    observerLst.insert(o);
}

void WeatherData::removeObserver(Observer o)
{
    if(!observerLst.empty()) {
        observerLst.erase(o);
    }
}

void WeatherData::notifyObserver()
{
    for (Observer o : observerLst) {
        o.update(temp, humidity, pressure);
    }
}


void WeatherData::measurementChanged()
{
    notifyObserver();
}

void WeatherData::setMeasurements(float tempIn, float humidityIn, float pressureIn)
{
    temp = tempIn;
    humidity = humidityIn;
    pressure = pressureIn;
    measurementChanged();
}




CurrentConditionsDisplay::CurrentConditionsDisplay(Subject &weatherDataIn)
{
    weatherData = &weatherDataIn;
    weatherData->registerObserver(*this);
}

void CurrentConditionsDisplay::display()
{
    cout << temp << " degree, " << humidity << "% humidity " << endl;
}

void CurrentConditionsDisplay::update(float tempIn, float humidityIn, float pressureIn)
{
    temp = tempIn;
    humidity = humidityIn;
    display();
}