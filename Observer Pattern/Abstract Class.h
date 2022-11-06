#ifndef DESIGN_PATTERN_ABSTRACT_CLASS_H
#define DESIGN_PATTERN_ABSTRACT_CLASS_H

class Observer {
public:
    void update(float temp, float humidity, float pressure);
public:
    float index_x;
    float index_y;
};

class DisplayElement {
public:
    void display();
};

class Subject {
public:
    void registerObserver(Observer o);
    void removeObserver(Observer o);
    void notifyObserver();
};

#endif //DESIGN_PATTERN_ABSTRACT_CLASS_H
