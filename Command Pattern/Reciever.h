#ifndef DESIGN_PATTERN_RECIEVER_H
#define DESIGN_PATTERN_RECIEVER_H

enum PlayMode : int {
    CD = 0,
    DVD = 1,
    BUTT = 2,
};

class Light {
public:
    void lightOn();
    void lightOff();
};

class Stereo {
public:
    void on();
    void off();
    void setCD();
    void setDVD();
    void setVolumn(int volumnValue);
    void getStatus(int &volumnOut, PlayMode &modeOut);
    void setStatus(int volumnIn, PlayMode modeIn);
private:
    int volumn;
    PlayMode mode;
};

#endif //DESIGN_PATTERN_RECIEVER_H
