// Robi Gurung
// Professor Pavel Shostak
// Project II
// 03 April 2022

#ifndef MyParser_h
#define MyParser_h
#include <vector>
#include <string>
#include "ASCII.h"

class MyParser
{
    public:
        MyParser();
        ~MyParser();
        std::vector<std::string> operator()(std::string);

        const int SPACE = 32;
        const int TAB = 9;
        const int DOUBLE_QUOTE = 34;
        const int SINGLE_QUOTE = 39;
        const int LESS_THAN = 60;
        const int EQUAL_TO = 61;
        const int GREATER_THAN = 62;
        const int COMMA = 44;
        const int NEW_LINE = 10;

    protected:

    private:
        std::string trim_lr(std::string);

        std::string trim_left(std::string);

        std::string trim_right(std::string);
};
#endif /* MyParser_h */
