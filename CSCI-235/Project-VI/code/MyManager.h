// Robi Gurung
// Professor Pavel Shostak
// Project II
// 03 April 2022

#ifndef MyManager_h
#define MyManager_h
#include "MyParser.h"
#include <iostream>
#include <sstream>
#include <fstream>

class MyManager
{
    public:
        MyManager();
        ~MyManager();
        bool process(std::vector<std::string> userInput);
    private:
        const std::string ADD = "ADD";
        const std::string FIND = "FIND";
        const std::string REMOVE = "REMOVE";
        const std::string STOP = "STOP";

        MyParser parser;

        void adder(unsigned int student_ID, std::string name, unsigned short age);
        void finder(std::string, std::string, std::string);
        void remover(std::string, std::string, std::string);
        bool stopper(std::vector<std::string>);
        long int init_add(std::string number, long int minValue, long int maxValue, std::string err_msg);
        std::string getWord(std::string line, int location, bool addPlusLocation);
        int wordCount(std::string);

    protected:

    private:
};
#endif /* MyManager_h */
