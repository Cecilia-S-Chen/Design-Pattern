#include "iostream"
#include "Reciever.h"
using namespace std;

void Light::lightOn()
{
    printf("Light is On\n");
}

void Light::lightOff()
{
    printf("Light is off\n");
}

void Stereo::on()
{
    printf("Stereo is on\n");
}

void Stereo::off()
{
    printf("Stereo is off\n");
}

void Stereo::setCD()
{
    mode = CD;
    printf("Set CD\n");
}

void Stereo::setDVD()
{
    mode = DVD;
    printf("Set DVD\n");
}

void Stereo::setVolumn(int volumnValue)
{
    volumn = volumnValue;
    printf("Set Volumn is %d\n", volumnValue);
}

void Stereo::getStatus(int &volumnOut, PlayMode &modeOut)
{
    volumnOut = volumn;
    modeOut = mode;
}

void Stereo::setStatus(int volumnIn, PlayMode modeIn)
{
    switch (mode) {
        case DVD:
            setDVD();
        case CD:
            setCD();
    }
    setVolumn(volumnIn);
}
