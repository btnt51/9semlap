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
    void string();
    void wstring();
    void replace(std::string &Command);
    void replace2(std::string &Command);

private:
    std::stringstream ss;

};


#endif //INC_9SEMLAP_FILE_H
