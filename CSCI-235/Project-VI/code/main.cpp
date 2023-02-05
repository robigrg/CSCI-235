// Robi Gurung
// Professor Pavel Shostak
// Project II
// 03 April 2022

#include "MyManager.h"

int main()
{
    MyManager engine;
    std::string userInput;
    MyParser parser;
    bool shouldStop = false;
    while(!shouldStop){
        std::cout<<"Command >> ";
        std::getline(std::cin, userInput);
        shouldStop = engine.process(parser(userInput));
    }
    return 0;
}
