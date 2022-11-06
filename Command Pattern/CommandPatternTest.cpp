#include <iostream>
#include "Command.h"
#include "Invoker.h"

/*
 * 命令模式
 *  核心：命令模式通过command对象，将reciever和invoker解耦开。
 *  优点：（1）使invoker不用关心reciever是如何实现的，只需要调用统一接口excute即可。
 *       （2）将执行的reciever作为对象封装起来，因此可以容易的储存，传递和调用它们。
 *  实现：（1）命令模式需要撤销和party模式，party模式是宏命令，一个命令多种功能。
 */

int main()
{
    Light *l = new Light();
    Stereo *s = new Stereo();
    LightOnCommand lOn = LightOnCommand(l);
    LightOffCommand lOff = LightOffCommand(l);
    StereoOnWithCDCommand sOn = StereoOnWithCDCommand(s);
    StereoOffCommand sOff = StereoOffCommand(s);

    RemoteControl *remoteControl = new RemoteControl();
    remoteControl->SetCommand(0, &lOn, &lOff);
    remoteControl->SetCommand(1, &sOn, &sOff);
    remoteControl->onButtonIsPressed(0);
    remoteControl->offButtonIsPressed(0);
    remoteControl->undoButtonIsPressed();
    remoteControl->onButtonIsPressed(1);
    remoteControl->offButtonIsPressed(1);
    remoteControl->undoButtonIsPressed();

    printf("-------------------------------------------\n");
    Command *commandsOn[2] = {&lOn, &sOn};
    int onCnt = sizeof(commandsOn) / sizeof(commandsOn[0]);
    MacroCommandOn macroCommandOn(commandsOn, onCnt);
    Command *commandsOff[] = {&lOff, &sOff};
    int offCnt = sizeof(commandsOff) / sizeof(commandsOff[0]);
    MacroCommandOff macroCommandOff(commandsOff, offCnt);
    remoteControl->SetCommand(2, &macroCommandOn, &macroCommandOff);
    remoteControl->onButtonIsPressed(2);
    remoteControl->undoButtonIsPressed();
}

