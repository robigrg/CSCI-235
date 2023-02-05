// Robi Gurung
// Professor Pavel Shostak
// Project II
// 03 April 2022

#include "MyManager.h"
#include <stdio.h>

MyManager::MyManager()
{
    //constructor
}

bool MyManager::process(std::vector<std::string> userInput){
    std::vector<std::string> collection = userInput;
    std::string Action = collection.at(0);
    if(Action==ADD){
        unsigned int student_ID;
        std::string name;
        unsigned short age;

        switch(collection.size()){
            case 4:
                student_ID = init_add(collection.at(1), 0, 4294967295, "ERR: student_ID must be between 0 - 4294967295!");
                if(student_ID==-1){
                    return false;
                }
                name = collection.at(2);
                age = init_add(collection.at(3), 0, 65535, "ERR: age must be between 0 - 65,535");
                if(age==-1){
                    return false;
                }
                adder(student_ID, name, age);
                break;
            case 5:
                student_ID = init_add(collection.at(1), 0, 4294967295, "ERR: student_ID must be between 0 - 4294967295!");
                if(student_ID==-1){
                    return false;
                }
                name = collection.at(2) + " " + collection.at(3);
                age = init_add(collection.at(4), 0, 65535, "ERR: age must be between 0 - 65,535");
                if(age==-1){
                    return false;
                }
                adder(student_ID, name, age);
                break;
            default:
                std::cout<<"ERR: input must be in ADD STUDENT_ID(unsigned int) NAME(string) AGE(unsigned short) pattern!"<<std::endl;
            break;
        }
        return false;
    }else if(Action==FIND){
        int collectionSize = collection.size();
        if(collectionSize>=4 && collectionSize<=5){
            std::string keyword = collection.at(1);
            std::string value;
            if(collectionSize==4)
                value = collection.at(3);
            else if(collectionSize==5)
                value = collection.at(3)+" "+collection.at(4);
            std::string operatorType = collection.at(2);
            finder(keyword, operatorType, value);
        }else{
            std::cout<<"ERR: Datatype Conditional_Operator Value is not given!"<<std::endl;
        }
        return false;
    }else if(Action==REMOVE){
        int collectionSize = collection.size();
        if(collectionSize>=4 && collectionSize<=5){
            std::string keyword = collection.at(1);
            std::string value;
            if(collectionSize==4)
                value = collection.at(3);
            else if(collectionSize==5)
                value = collection.at(3)+" "+collection.at(4);
            std::string operatorType = collection.at(2);
            remover(keyword, operatorType, value);
        }else{
            std::cout<<"ERR: Datatype Conditional_Operator Value is not given!"<<std::endl;
        }
        return false;
    }else if(Action==STOP){
        return stopper(collection);
    }else{
        std::cout<<"bad command!!!"<<std::endl;
        return false;
    }
}

void MyManager::adder(unsigned int student_ID, std::string name, unsigned short age){
    std::ofstream file("test.txt", std::ofstream::out | std::ofstream::app);
    if(file.is_open()){
        file<<student_ID<<" "<<name<<" "<<age<<"\n";
    }
    file.close();
}

void MyManager::finder(std::string keyword, std::string operatorType, std::string value){
    std::stringstream ss, file_ss;
    ss << value;
    std::ifstream file("test.txt");
    std::string line;
    std::string word;

    if(keyword=="id" || keyword=="student_ID"){
        long int number, file_id;
        ss >> number;
        if(file.is_open()){
            while(file){
                //line = "";
                getline(file, line);
                word = getWord(line, 0, false);
                file_ss << word;
                file_ss >> file_id;
                if(operatorType==">"){
                    if(file_id > number){
                        std::cout<<line<<std::endl;
                    }
                }else if(operatorType=="<"){
                    if(file_id < number){
                        std::cout<<line<<std::endl;
                    }
                }else if(operatorType=="="){
                    if(file_id == number){
                        std::cout<<line<<std::endl;
                    }
                }else{
                    std::cout<<"Conditional Operator couldn't be recognized, it should be '<' ,'>' or '='."<<std::endl;
                }
            file_ss.clear();
            }
        }
    }else if(keyword=="name"){
        if(file.is_open()){
            while(file){
                //line = "";
                getline(file, line);
                int countSize = wordCount(line);
                bool concatWord = false;
                if(countSize>3){
                    concatWord = true;
                }
                word = getWord(line, 1, concatWord);
                if(operatorType=="="){
                    if(word == value){
                        std::cout<<line<<std::endl;
                    }
                }else{
                    std::cout<<"Conditional Operator couldn't be recognized, it should be '='."<<std::endl;
                }
            file_ss.clear();
            }
        }
    }else if(keyword=="age"){
        long int number, file_id;
        ss >> number;
        if(file.is_open()){
            while(file){
                //line = "";
                getline(file, line);
                int countSize = wordCount(line);

                int addNumber = 0;
                bool concatWord = false;
                if(countSize>3){
                    concatWord = true;
                }
                if(concatWord){
                    addNumber = 1;
                }else{
                    addNumber = 0;
                }
                word = getWord(line, 2+addNumber, false);
                file_ss << word;
                file_ss >> file_id;
                if(operatorType==">"){
                    if(file_id > number){
                        std::cout<<line<<std::endl;
                    }
                }else if(operatorType=="<"){
                    if(file_id < number){
                        std::cout<<line<<std::endl;
                    }
                }else if(operatorType=="="){
                    if(file_id == number){
                        std::cout<<line<<std::endl;
                    }
                }else{
                    std::cout<<"Conditional Operator couldn't be recognized, it should be '<' ,'>' or '='."<<std::endl;
                }
            file_ss.clear();
            }
        }
    }else{
        std::cout<<"ERR: Datatype Conditional_Operator Value is not given!"<<std::endl;
    }
    ss.clear();
    file.close();
    std::ifstream updateFile("test.txt");
    std::ofstream fileWriter("temp.txt");
    std::string copy_line = "";
    if(updateFile.is_open()){
        if(fileWriter.is_open()){
            while(updateFile){
                getline(updateFile, copy_line);
                if(copy_line.size()>1){
                    fileWriter << copy_line << std::endl;
                }

            }
        }
        updateFile.close();
        fileWriter.close();
        remove("test.txt");
        rename("temp.txt", "test.txt");
    }else{
        std::cout<<"File not opened!"<<std::endl;
    }
}

void MyManager::remover(std::string keyword, std::string operatorType, std::string value){
    std::stringstream ss, file_ss;
    ss << value;
    std::ifstream file("test.txt");
    std::ofstream fileWriter("temp.txt");
    std::string line;
    std::string word;

    if(keyword=="id" || keyword=="student_ID"){
        long int number, file_id;
        ss >> number;
        if(file.is_open()){
            if(fileWriter.is_open()){
                while(file){
                    getline(file, line);
                    word = getWord(line, 0, false);
                    file_ss << word;
                    file_ss >> file_id;
                    if(operatorType==">"){
                        if(!(file_id > number)){
                            fileWriter << line << std::endl;
                        }
                    }else if(operatorType=="<"){
                        if(!(file_id < number)){
                            fileWriter << line << std::endl;
                        }
                    }else if(operatorType=="="){
                        if(file_id != number){
                            fileWriter << line << std::endl;
                        }
                    }else{
                        std::cout<<"Conditional Operator couldn't be recognized, it should be '<' ,'>' or '='."<<std::endl;
                    }
                file_ss.clear();
                }
            }
        }
    }else if(keyword=="name"){
        std::vector<std::string> name = parser(value);
        std::string temp_name = "";
        if(name.size()==2){
            if(value[0]==parser.DOUBLE_QUOTE){
                temp_name = name[0] + " "+name[1];
            }else{
                return;
            }
        }else if(name.size()==1){
            temp_name = name[0];
        }
        if(file.is_open()){
            if(fileWriter.is_open()){
                while(file){
                    getline(file, line);
                    int countSize = wordCount(line);
                    bool concatWord = false;
                    if(countSize>3){
                        concatWord = true;
                    }
                    word = getWord(line, 1, concatWord);
                    if(operatorType=="="){
                        if(word != temp_name){
                            fileWriter << line << std::endl;
                        }
                    }else{
                        std::cout<<"Conditional Operator couldn't be recognized, it should be '='."<<std::endl;
                    }
                file_ss.clear();
                }
            }
        }
    }else if(keyword=="age"){
        long int number, file_id;
        ss >> number;
        if(file.is_open()){
            if(fileWriter.is_open()){
                while(file){
                    getline(file, line);
                    int countSize = wordCount(line);

                    int addNumber = 0;
                    bool concatWord = false;
                    if(countSize>3){
                        concatWord = true;
                    }
                    if(concatWord){
                        addNumber = 1;
                    }else{
                        addNumber = 0;
                    }
                    word = getWord(line, 2+addNumber, false);
                    file_ss << word;
                    file_ss >> file_id;
                    if(operatorType==">"){
                        if(!(file_id > number)){
                            fileWriter << line << std::endl;
                        }
                    }else if(operatorType=="<"){
                        if(!(file_id < number)){
                            fileWriter << line << std::endl;
                        }
                    }else if(operatorType=="="){
                        if(!(file_id == number)){
                            fileWriter << line << std::endl;
                        }
                    }else{
                        std::cout<<"Conditional Operator couldn't be recognized, it should be '<' ,'>' or '='."<<std::endl;
                    }
                file_ss.clear();
                }
            }
        }
    }else{
        std::cout<<"ERR: Datatype Conditional_Operator Value is not given!"<<std::endl;
    }
    ss.clear();
    file.close();
    fileWriter.close();
    remove("test.txt");
    rename("temp.txt", "test.txt");
}

bool MyManager::stopper(std::vector<std::string> collection){
    if(collection.size()==1){
        std::cout<<"Bye!"<<std::endl;
        return true;
    }else{
        std::cout<<"ERR: STOP is followed by other commands or data!"<<std::endl;
        return false;
    }
}

long int MyManager::init_add(std::string number, long int minValue, long int maxValue, std::string err_msg){
    std::stringstream ss;
    ss << number;
    long int value;
    ss >> value;
    if(value>=minValue && value<=maxValue){
        return value;
    }else{
        std::cout<<err_msg<<std::endl;
        return -1;
    }
}

std::string MyManager::getWord(std::string line, int location, bool addPlusLocation){
    std::vector<std::string> collection = parser(line);
    if(collection.size()>1){
         if(addPlusLocation){
            return collection.at(location) + " " + collection.at(location+1);
        }else{
            return collection.at(location);
        }
    }else{
        return "";
    }
}

int MyManager::wordCount(std::string line){
    std::vector<std::string> collection = parser(line);
    return collection.size();
}

MyManager::~MyManager()
{
    //destructor
}
