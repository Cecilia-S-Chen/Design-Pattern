#include "Sub Class.h"

int main() {
    CaffeineBeverage *baseClassPtr = new Tea();
    baseClassPtr->PrepareRecipe();
    baseClassPtr = new Coffee();
    baseClassPtr->PrepareRecipe();
}

