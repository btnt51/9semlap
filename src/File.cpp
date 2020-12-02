//
// Created by btnt51 on 01.12.2020.
//
#define Z "=+*/%"

#include <cstring>
#include "File.h"
File::File()
{

}

void File::string()
{
    std::ifstream iFile("../rcs/input.txt");
    if(iFile)
    {
        std::list<std::string> lines;
        std::string m_string;
        ss << iFile.rdbuf();
        m_string = ss.str();
        int counter = 0, newCommand = 0, counterC = 0;
        while(m_string[counter] != '\0')
        {
            if(m_string[counter] == '\n')
            {
                std::string Command;
                int l = newCommand;
                while(l < counter)
                {
                    Command.push_back(m_string[l]);
                    l++;
                    counterC++;
                }
                Command[Command.size()+1] = '\0';
                replace(Command);
                replace2(Command);
                counterC = 0;
                newCommand = counter;
                lines.push_back(Command);
            }
            counter++;
        }
        iFile.close();
        ss.str(std::string());
        for(auto iter = lines.begin(); iter != lines.end();iter++)
        {
            ss << *iter;
        }
        std::cout << ss.str();
    }
    else
    {
        std::cout << "some problems with iFile" << std::endl;
    }
}

void File::replace(std::string &Command)
{
    std::string string[] = {"=",",","*","/"};
    std::string string1[] = {" = ",", "," * "," / "};
    for(int i = 0; i < 4; i++)
    {
        std::size_t found = Command.find_first_of(string[i]);
        while (found != std::string::npos)
        {
            Command.replace(found, 1, string1[i]);
            found = Command.find_first_of(string[i], found + 2);
        }
    }
    std::size_t found = Command.find("++");
    while (found != std::string::npos)
    {
        if(Command[found-1] == ' ' && Command[found-2] != ' ')
            Command.replace(found-1, 3,"@@");
        else
            Command.replace(found, 3,"@@");
        found = Command.find("++", found + 2);
    }
    found = Command.find("--");
    while (found != std::string::npos)
    {
        if(Command[found-1] == ' ' && Command[found-2] != ' ')
            Command.replace(found-1, 3,"\\\\");
        else
            Command.replace(found, 3,"\\\\");
        found = Command.find("--", found + 2);
    }
    found = Command.find('+');
    while (found != std::string::npos)
    {
        if(Command[found+1] != '+'|| Command[found-1] != '+')
            Command.replace(found, 1," + ");
        found = Command.find('+', found + 2);
    }
    found = Command.find('-');
    while (found != std::string::npos)
    {
        if(Command[found+1] != '-'|| Command[found-1] != '-')
            Command.replace(found, 1," - ");
        found = Command.find('-', found + 2);
    }
}

void File::replace2(std::string &Command)
{
    auto it = Command.find_first_of('@');
    while(it != std::string::npos)
    {
        Command.replace(it,1,"+");
        it = Command.find_first_of('@');
    }
    it = Command.find_first_of('\\');
    while(it != std::string::npos)
    {
        Command.replace(it,1,"-");
        it = Command.find_first_of('\\');
    }
}

void File::wstring()
{
    std::ifstream iFile("../rcs/input.txt");
    if(iFile)
    {
        std::list<std::wstring> lines;
        ss << iFile.rdbuf();
        std::wstring m_string( ss.str().begin(),ss.str().end());
        int counter = 0, newCommand = 0, counterC = 0;
        while(m_string[counter] != '\0')
        {
            if(m_string[counter] == '\n')
            {
                std::wstring Command;
                int l = newCommand;
                while(l < counter)
                {
                    Command.push_back(m_string[l]);
                    l++;
                    counterC++;
                }
                Command[Command.size()+1] = '\0';
                replace(Command.c_str());
                replace2(Command.c_str());
                counterC = 0;
                newCommand = counter;
                lines.push_back(Command);
            }
            counter++;
        }
        iFile.close();
        ss.str(std::string());
        for(auto iter = lines.begin(); iter != lines.end();iter++)
        {
            ss << *iter->c_str();
        }
        std::cout << ss.str();
    }
    else
    {
        std::cout << "some problems with iFile" << std::endl;
    }
}
