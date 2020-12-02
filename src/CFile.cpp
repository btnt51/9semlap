//
// Created by btnt51 on 01.12.2020.
//
#define Z "=+*/%"

#include <cstring>
#include "CFile.h"
CFile::CFile()
{

}

void CFile::string()
{
    std::ifstream iFile("../rcs/input.txt");
    if(iFile)
    {
        std::list<std::string> lines;
        std::string m_string;
        ss << iFile.rdbuf();
        m_string = ss.str();
        ss.str(std::string());
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
        for(auto iter = lines.begin(); iter != lines.end();iter++)
        {
            ss << *iter;
        }
        ss << "\n";
        std::cout << ss.str();
    }
    else
    {
        std::cout << "some problems with iFile" << std::endl;
    }
}

template<typename  T>
void CFile::replace(T &Command)
{
    std::string str;
    for(char x : Command)
        str += x;
    std::string string[] = {"=",",","*","/"};
    std::string string1[] = {" = ",", "," * "," / "};
    for(int i = 0; i < 4; i++)
    {
        std::size_t found = str.find_first_of(string[i]);
        while (found != std::string::npos)
        {
            str.replace(found, 1, string1[i]);
            found = str.find_first_of(string[i], found + 2);
        }
    }
    std::size_t found = str.find("++");
    while (found != std::string::npos)
    {
        if(str[found-1] == ' ' && str[found-2] != ' ')
            str.replace(found-1, 3,"@@");
        else
            str.replace(found, 3,"@@");
        found = str.find("++", found + 2);
    }
    found = str.find("--");
    while (found != std::string::npos)
    {
        if(str[found-1] == ' ' && str[found-2] != ' ')
            str.replace(found-1, 3,"\\\\");
        else
            str.replace(found, 3,"\\\\");
        found = str.find("--", found + 2);
    }
    found = str.find('+');
    while (found != std::string::npos)
    {
        if(str[found+1] != '+'|| str[found-1] != '+')
            str.replace(found, 1," + ");
        found = str.find('+', found + 2);
    }
    found = str.find('-');
    while (found != std::string::npos)
    {
        if(str[found+1] != '-'|| str[found-1] != '-')
            str.replace(found, 1," - ");
        found = str.find('-', found + 2);
    }
    Command.clear();
    for(wchar_t x : str)
        Command += x;
}



template<typename  T>
void CFile::replace2(T &Command)
{
    std::string str;
    for(char x : Command)
        str += x;
    auto it = str.find_first_of('@');
    while(it != std::string::npos)
    {
        str.replace(it,1,"+");
        it = str.find_first_of('@');
    }
    it = str.find_first_of('\\');
    while(it != std::string::npos)
    {
        str.replace(it,1,"-");
        it = str.find_first_of('\\');
    }
    Command.clear();
    for(wchar_t x : str)
        Command += x;
}

void CFile::wstring()
{
    std::ifstream iFile("../rcs/input.txt");
    if(iFile)
    {
        std::list<std::wstring> lines;
        ss << iFile.rdbuf();
        std::string buf = ss.str();
        std::wstring m_string(buf.begin(), buf.end());
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
            std::string str;
            for(char x : *iter)
                str += x;
            ss << str;
        }
        ss << "\n";
        std::cout << ss.str();
    }
    else
    {
        std::cout << "some problems with iFile" << std::endl;
    }
}

void CFile::cstring()
{
    std::ifstream iFile("../rcs/input.txt");
    if(iFile)
    {
        ss << iFile.rdbuf();
        std::string buf = ss.str();
        const char * m_string = buf.c_str();
        ss.str("");
        int counter = 0, newCommand = 0, counterC = 0;
        while(m_string[counter] != '\0')
        {
            if(m_string[counter] == '\n')
            {
                std::string Command;
                int l = newCommand;
                while(l < counter)
                {
                    Command += m_string[l];
                    l++;
                    counterC++;
                }
                Command[counterC+1] = '\0';
                replace(Command);
                replace2(Command);
                counterC = 0;
                newCommand = counter;
                ss << Command;
            }
            counter++;
        }
        iFile.close();
        ss << "\n";
        std::cout << ss.str();
        delete m_string;
    }
    else
    {
        std::cout << "some problems with iFile" << std::endl;
    }
}

void CFile::wcstring()
{
    std::ifstream iFile("../rcs/input.txt");
    if(iFile)
    {
        std::list<std::wstring> lines;
        ss << iFile.rdbuf();
        std::string buf = ss.str();
        std::wstring buf2(buf.begin(), buf.end());
        auto *m_string = const_cast<wchar_t *>(buf2.c_str());
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
            std::string str;
            for(char x : *iter)
                str += x;
            ss << str;
        }
        ss << "\n";
        std::cout << ss.str();
        delete m_string;
    }
    else
    {
        std::cout << "some problems with iFile" << std::endl;
    }
}
