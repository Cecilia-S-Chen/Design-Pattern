#include "Command.h"
using namespace std;

LightOnCommand::LightOnCommand(Light *lightIn)
{
    light = lightIn;
}

void LightOnCommand::excute()
{
    light->lightOn();
}

void LightOnCommand::undo()
{
    light->lightOff();
}

LightOffCommand::LightOffCommand(Light *lightIn)
{
    light = lightIn;
}

void LightOffCommand::excute()
{
    light->lightOff();
}

void LightOffCommand::undo()
{
    light->lightOn();
}

StereoOnWithCDCommand::StereoOnWithCDCommand(Stereo *stereoIn)
{
    stereo = stereoIn;
}

void StereoOnWithCDCommand::excute()
{
    stereo->on();
    stereo->setCD();
    stereo->setVolumn(11);
}

void StereoOnWithCDCommand::undo()
{
    stereo->off();
}

StereoOffCommand::StereoOffCommand(Stereo *stereoIn)
{
    stereo = stereoIn;
}

void StereoOffCommand::excute()
{
    stereo->off();
}

void StereoOffCommand::undo()
{
    stereo->on();
    int volumn;
    PlayMode mode;
    stereo->getStatus(volumn, mode);
    stereo->setStatus(volumn, mode);
}

/*
 * 注：传入数组名时，数组名不代表数组，而是指向数组首元素的指针
 * 解决办法：（1）传入数组的引用
 *          （2）传入指向数组的指针，指向数组的的指针定义为T(*p)[N]。本例中可以定义为Command*(*p)[2]
 */
MacroCommandOn::MacroCommandOn(Command **commandsIn, int size)
{
    commandsSize = size;
    for (int i = 0; i < commandsSize; i++) {
        commands[i] = commandsIn[i];
    }
}

void MacroCommandOn::excute()
{
    for (int i = 0; i < commandsSize; i++) {
        if (commands[i] != nullptr) {
            commands[i]->excute();
        }
    }
}

void MacroCommandOn::undo()
{
    for (int i = 0; i < commandsSize; i++) {
        if (commands[i] != nullptr) {
            commands[i]->undo();
        }
    }
}

MacroCommandOff::MacroCommandOff(Command **commandsIn, int size)
{
    commandsSize = size;
    for (int i = 0; i < commandsSize; i++) {
        commands[i] = commandsIn[i];
    }
}

void MacroCommandOff::excute()
{
    for (int i = 0; i < commandsSize; i++) {
        if (commands[i] != nullptr) {
            commands[i]->excute();
        }
    }
}

void MacroCommandOff::undo()
{
    for (int i = 0; i < commandsSize; i++) {
        if (commands[i] != nullptr) {
            commands[i]->undo();
        }
    }
}