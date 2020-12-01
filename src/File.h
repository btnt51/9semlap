//
// Created by btnt51 on 01.12.2020.
//

#ifndef INC_9SEMLAP_FILE_H
#define INC_9SEMLAP_FILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <strstream>
#include <sstream>

class File
{
public:
    File();
    void InputFile();
    std::stringstream OutText();
    void OutputFile();

private:
    std::stringstream ss{};
};


#endif //INC_9SEMLAP_FILE_H
