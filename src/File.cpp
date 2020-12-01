//
// Created by btnt51 on 01.12.2020.
//

#include "File.h"
File::File()
{

}

void File::InputFile()
{
    std::ifstream iFile("../rcs/input.txt");
    if(iFile)
    {
        ss << iFile.rdbuf();
        std::cout << ss.str() << std::endl;
    }
}

std::stringstream File::OutText() {
    return std::stringstream();
}
