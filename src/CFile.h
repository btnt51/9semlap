//
// Created by btnt51 on 01.12.2020.
//

#ifndef INC_9SEMLAP_CFILE_H
#define INC_9SEMLAP_CFILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <strstream>
#include <sstream>
#include <list>

class CFile
{
public:
    CFile();
    void string();
    void cstring();
    void wstring();
    void wcstring();

    template<typename  T>
    void replace(T &Command);
    template<typename  T>
    void replace2(T &Command);

private:
    std::stringstream ss;
};


#endif //INC_9SEMLAP_CFILE_H
