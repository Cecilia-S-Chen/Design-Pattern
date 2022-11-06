#ifndef DESIGN_PATTERN_FACADE_H
#define DESIGN_PATTERN_FACADE_H
#include <string>
using namespace std;
/*
 * 外观模式：
 * 1、提供统一的接口，访问子系统中一群接口。使得客户不用了解子系统内部的运行逻辑，就能实现复杂功能。
 * 2、设计原则：最小知识原则,对外暴露最少的接口。
 * 3、外观模式和适配器模式的区别：
 *  适配器模式的目的：改变接口以满足对接需要
 *  外观模式的目的：为子系统提供简化接口。
 */


class Amplifier {
public:
    void print(const string& str = "Amplifier");
};

class Tuner {
public:
    void print(const string& str = "Tuner");
};

class DvdPlayer {
public:
    void print(const string& str = "DvdPlayer");
};

class CdPlayer {
public:
    void print(const string& str = "CdPlayer");
};

class Projector {
public:
    void print(const string& str = "Projector");
};

class HomeTheaterFacade {
public:
    HomeTheaterFacade(const Amplifier &a, const Tuner &t, const DvdPlayer &d, const CdPlayer &c, const Projector &p);
    void watchMovie();
private:
    Amplifier amplifier;
    Tuner tuner;
    DvdPlayer dvdPlayer;
    CdPlayer cdPlayer;
    Projector projector;
};
#endif //DESIGN_PATTERN_FACADE_H
