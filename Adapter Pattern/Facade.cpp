#include <iostream>
#include "Facade.h"

static void commonPrint(const string &str) {
    cout << str << endl;
}

void Amplifier::print(const string& str) {
    commonPrint(str);
}

void Tuner::print(const string& str) {
    commonPrint(str);
}

void DvdPlayer::print(const string& str) {
    commonPrint(str);
}

void CdPlayer::print(const string& str) {
    commonPrint(str);
}

void Projector::print(const string& str) {
    commonPrint(str);
}


HomeTheaterFacade::HomeTheaterFacade(const Amplifier &a, const Tuner &t, const DvdPlayer &d, const CdPlayer &c,
                                     const Projector &p) {
    amplifier = a;
    tuner = t;
    dvdPlayer = d;
    cdPlayer = c;
    projector = p;
}
// 通过简化接口实现子系统复杂功能
void HomeTheaterFacade::watchMovie() {
    amplifier.print();
    tuner.print();
    dvdPlayer.print();
    cdPlayer.print();
    projector.print();
}

int main()
{
    Amplifier a;
    Tuner t;
    DvdPlayer d;
    CdPlayer c;
    Projector p;
    HomeTheaterFacade facade(a, t, d, c, p);
    facade.watchMovie();
}