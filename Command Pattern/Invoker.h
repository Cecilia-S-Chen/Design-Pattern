#ifndef DESIGN_PATTERN_INVOKER_H
#define DESIGN_PATTERN_INVOKER_H

#include "Command.h"
class RemoteControl {
public:
    RemoteControl();
    void SetCommand(int slot, Command *onCommand, Command *offCommand);
    void onButtonIsPressed(int slot);
    void offButtonIsPressed(int slot);
    void undoButtonIsPressed();
private:
    bool JudgeSlotAvaliable(int slot);
    Command *onCommands[7];
    Command *offCommands[7];
    Command *undoCommand;
};
#endif //DESIGN_PATTERN_INVOKER_H
