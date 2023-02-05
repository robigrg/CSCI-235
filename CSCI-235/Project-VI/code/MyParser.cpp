// Robi Gurung
// Professor Pavel Shostak
// Project II
// 03 April 2022

#include "MyParser.h"
#include <stdio.h>

MyParser::MyParser()
{
    //concstructor
}

std::vector<std::string> MyParser::operator()(std::string command){
    std::vector<std::string> collection;
            std::string space_command = trim_lr(command)+" ";
            bool pushed = false;
            int quote_counter = 0;
            int string_size = space_command.size();
            std::string command_word = "";
            for(int i=0; i<string_size; i++){
                int value = ASCII::Data(space_command[i]);
                if(value==SPACE || value==TAB || value==NEW_LINE){
                    if(!pushed){
                        if(quote_counter==0 || quote_counter==2){
                            collection.push_back(command_word);
                            command_word = "";
                            pushed = true;
                        }else if(quote_counter>0 && quote_counter<2){
                            command_word += " ";
                        }
                    }
                }else if(value==LESS_THAN || value==EQUAL_TO || value==GREATER_THAN){
                    if(command_word!=""){
                        collection.push_back(command_word);
                        command_word = "";
                        pushed = true;
                    }
                    std::string temp = "";
                    temp += space_command[i];
                    collection.push_back(temp);
                }else if(value==DOUBLE_QUOTE){
                    quote_counter++;
                    if(quote_counter>2){
                        return collection;
                    }
                }else{
                    pushed = false;
                    command_word += space_command[i];
                }
            }
            return collection;
}

std::string MyParser::trim_left(std::string data){
    std::string temp = "";
            int starter = 0;
            int dataSize = data.size();
            for(int i=0; i<dataSize; i++){
                if(!(ASCII::Data(data[i])==SPACE || ASCII::Data(data[i])==TAB)){
                    starter = i;
                    break;
                }
            }
            for(int i=starter; i<dataSize; i++){
                temp += data[i];
            }
            return temp;
}

std::string MyParser::trim_right(std::string data){
    std::string temp = "";
            int starter = 0;
            int dataSize = data.size();
            for(int i=dataSize-1; i>=0; i--){
                if(!(ASCII::Data(data[i])==SPACE || ASCII::Data(data[i])==TAB)){
                    starter = i;
                    break;
                }
            }
            for(int i=0; i<=starter; i++){
                temp += data[i];
            }
            return temp;
}

std::string MyParser::trim_lr(std::string data){
    return trim_left(trim_right(data));
}

MyParser::~MyParser()
{
    //destructor
}
