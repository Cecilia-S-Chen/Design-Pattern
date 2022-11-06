#include "iostream"
using namespace std;

#include "Invoker.h"

RemoteControl::RemoteControl()
{
    Command *noCommand = new Command();
    for (int i = 0; i < 7; i++) {
        onCommands[i] = noCommand;
        offCommands[i] = noCommand;
    }
}

void RemoteControl::SetCommand(int slot, Command *onCommand, Command *offCommand)
{
    if (!JudgeSlotAvaliable(slot)) {
        return;
    }
    onCommands[slot] = onCommand;
    offCommands[slot] = offCommand;
}

void RemoteControl::onButtonIsPressed(int slot)
{
    if (!JudgeSlotAvaliable(slot)) {
        return;
    }
    undoCommand = onCommands[slot];
    onCommands[slot]->excute();
}

void RemoteControl::offButtonIsPressed(int slot)
{
    if (!JudgeSlotAvaliable(slot)) {
        return;
    }
    undoCommand = offCommands[slot];
    offCommands[slot]->excute();
}

void RemoteControl::undoButtonIsPressed()
{
    undoCommand->undo();
}

bool RemoteControl::JudgeSlotAvaliable(int slot)
{
    if (slot >= 0 && slot < 7) {
        return true;
    }
    cout << "slot is out of the range of remote control" << endl;
    return false;
}
