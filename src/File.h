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
#include <list>

class File
{
public:
    File();
    void InputFile();
    void string();
    std::list<std::string> OutText();
    void OutputFile();

private:
    std::string m_string;
    std::stringstream ss;
    std::list<std::string> lines;
};


#endif //INC_9SEMLAP_FILE_H
