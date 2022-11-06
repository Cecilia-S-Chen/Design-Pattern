cmake_minimum_required(VERSION 3.17)
project(Design_Pattern)

set(CMAKE_CXX_STANDARD 14)

add_executable(main1 "Stratege Pattern/Strategy Patterner.cpp")
add_executable(main2 "Observer Pattern/Concrete Class.h" "Observer Pattern/Abstract Class.h" "Observer Pattern/Concrete Class.cpp" "Observer Pattern/Observer Pattern Project.cpp")
add_executable(main3 "Decorator Pattern/Decorator Pattern.cpp")
add_executable(main4 "Factory Pattern/Factory Method.cpp" "Factory Pattern/Ingredient.h" "Factory Pattern/Factory Method.h")
add_executable(main5 "Singleton Pattern/Hungry And Lazy.cpp" "Singleton Pattern/Hungry And Lazy.h")
add_executable(main6 "Command Pattern/Invoker.cpp" "Command Pattern/Invoker.h" "Command Pattern/Command.h" "Command Pattern/Reciever.cpp" "Command Pattern/Reciever.h" "Command Pattern/Command.cpp" "Command Pattern/CommandPatternTest.cpp")
add_executable(main7 "Adapter Pattern/Adapter.cpp" "Adapter Pattern/Adapter.h")
add_executable(main8 "Adapter Pattern/Facade.h" "Adapter Pattern/Facade.cpp")
add_executable(main9 "Template/Base Class.h" "Template/Sub Class.h" "Template/Template Pattern Test.cpp")