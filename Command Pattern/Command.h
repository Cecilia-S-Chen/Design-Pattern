#ifndef DESIGN_PATTERN_COMMAND_H
#define DESIGN_PATTERN_COMMAND_H

#include "Reciever.h"

class Command {
public:
    virtual void excute() {};
    virtual void undo() {};
};

class LightOnCommand : public Command {
public:
    LightOnCommand(Light *lightIn);
    void excute() override;
    void undo() override;
private:
    Light *light;
};

class LightOffCommand : public Command {
public:
    LightOffCommand(Light *lightIn);
    void excute() override;
    void undo() override;
private:
    Light *light;
};

class StereoOnWithCDCommand : public Command {
public:
    StereoOnWithCDCommand(Stereo *stereoIn);
    void excute() override;
    void undo() override;
private:
    Stereo *stereo;
};

class StereoOffCommand : public Command {
public:
    StereoOffCommand(Stereo *stereoIn);
    void excute() override;
    void undo() override;
private:
    Stereo *stereo;
};

class MacroCommandOn : public Command {
public:
    MacroCommandOn(Command **commandsIn, int size);
    void excute() override;
    void undo() override;
private:
    Command *commands[7];
    int commandsSize;
};

class MacroCommandOff : public Command {
public:
    MacroCommandOff(Command **commandsIn, int size);
    void excute() override;
    void undo() override;
private:
    Command *commands[7];
    int commandsSize;
};

#endif //DESIGN_PATTERN_COMMAND_H
