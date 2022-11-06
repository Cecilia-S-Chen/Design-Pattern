#include <iostream>
#include "Adapter.h"
using namespace std;

void Duck::quack() {
    cout << "Duck quack" << endl;
}
void Duck::fly() {
    cout << "Duck fly" << endl;
}


void Turkey::gobble() {
    cout << "Turkey gobble" << endl;
}
void Turkey::fly() {
    cout << "Turkey fly" << endl;
}



TurkeyAdapter::TurkeyAdapter(const Turkey &tIn) {
    t = tIn;
}
void TurkeyAdapter::quack(){
    t.gobble();
}
void TurkeyAdapter::fly(){
    t.fly();
}


void TurkeyClassAdapter::quack() {
    Turkey::gobble();
}

void TurkeyClassAdapter::fly() {
    Turkey::fly();
}


int main() {
    Turkey turkey;
    turkey.gobble();
    turkey.fly();

    Duck duck;
    duck.quack();
    duck.fly();

    Duck *adapterTest = new TurkeyAdapter(turkey);
    adapterTest->quack();
    adapterTest->fly();

    Duck *classAdapterTest = new TurkeyClassAdapter();
    classAdapterTest->quack();
    classAdapterTest->fly();
}