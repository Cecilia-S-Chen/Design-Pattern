#include <iostream>
class Base {
public:
    void print() {
        std::cout << "base" << std::endl;
    }
};


class Derived {
public:
    void print() {
        std::cout << "derived" << std::endl;
    }
};

int main() {
    return 0;
}
