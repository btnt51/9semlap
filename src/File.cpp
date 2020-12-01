//
// Created by btnt51 on 01.12.2020.
//
#define Z "=+*/%"

#include <cstring>
#include "File.h"
File::File()
{

}

void File::InputFile()
{
    std::ifstream iFile("../rcs/input.txt");
    if(iFile)
    {
        int line = 0;
        int i = 0;
        ss << iFile.rdbuf();
        m_string = ss.str();
        while(m_string[i] != '\0')
        {
            if(m_string[i] == '\n')
                line++;
            i++;
        }
        std::cout << m_string;
        iFile.close();
    }
    else
    {
        std::cout << "some shit iFile" << std::endl;
    }

}

std::list<std::string> File::OutText() {
    int counter = 0, newCommand = 0, counterC = 0;
    while(m_string[counter] != '\0')
    {
        if(m_string[counter] == '\n')
        {
            std::string Command;
            for(int i = newCommand; i < counter;i++)
            {
                Command.push_back(m_string[i]);
                counterC++;
            }
            Command[counterC] = '\0';
            counterC = 0;
            newCommand = counter;
            lines.push_back(Command);
        }
        if(m_string[counter+1] == '\0')
            lines.push_back("\n}");
        counter++;
    }
    counter = 0;
    return lines;
}

void File::OutputFile()
{
    std::ofstream oFile("../rcs/output.txt");
    if(oFile)
    {
        oFile << ss.str();
    }
    else
    {
        std::cout << "some shit oFile" << std::endl;
    }
    oFile.close();
}

void File::string()
{
    std::ifstream iFile("../rcs/input.txt");
    if(iFile)
    {
        int line = 0;
        int i = 0;
        ss << iFile.rdbuf();
        m_string = ss.str();
        int counter = 0, newCommand = 0, counterC = 0;
        while(m_string[counter] != '\0')
        {
            bool TR = true;
            if(m_string[counter] == '\n')
            {
                int k = 0;
                std::string Command;
                int l = newCommand;
                while(l < counter)
                {
                    if(m_string[l] == ',' && m_string[l+1] != ' ')
                    {
                        Command.push_back(m_string[l]);
                        Command.push_back(' ');
                        l++;
                        counterC++;
                        k +=1;
                    }
                    if(strchr(Z,m_string[l]) && m_string[l+1] != ' ' && m_string[l-1] != ' ')
                    {
                            Command.push_back(' ');
                            Command.push_back(m_string[l]);
                            Command.push_back(' ');
                            l++;
                            counterC++;
                            k +=2;
                    }
                    if(m_string[l] == '+' && m_string[l+1] == ' ' && m_string[l-1] == '+'  && TR)
                    {
                            Command.push_back(m_string[l]);
                            l += 2;
                            counterC++;
                            TR = false;
                    }
                    if(m_string[l] == ' ' && m_string[l+1] == '+' && m_string[l+2] == '+' && !TR)
                    {
                        Command.push_back(m_string[++l]);
                        l++;
                        counterC++;
                        TR= !TR;
                    }
                    if(m_string[l] == ' ' && m_string[l+1] == '-' && m_string[l+2] == '-')
                    {
                        Command.push_back(m_string[++l]);
                        l++;
                        counterC++;
                    }
                    if(m_string[l] == '-' && m_string[l+1] == ' ' && m_string[l-1] == '-')
                    {
                        Command.push_back(m_string[l]);
                        l += 2;
                        counterC++;
                    }
                    Command.push_back(m_string[l]);
                    l++;
                    counterC++;
                }
                Command[counterC+k] = '\0';
                counterC = 0;
                newCommand = counter;
                line++;
                lines.push_back(Command);
            }
            if(m_string[counter+1] == '\0')
            {
                lines.push_back("\n}");
                line++;
            }
            counter++;
        }
        std::for_each(lines.begin(), lines.end(),[](auto Element){
           std::cout << Element;
        });
        /*for(auto element = lines.begin(); element != lines.end(); element++)
        {
                i = element->find(',');
                std::string str(*element);
                int len = str.size();
                str.resize(len + 5);
                str.erase(i);
                str.insert(i,1,'@');
                //str.insert(i+1,1,' ');
                std::cout << str;
                *element = str;
        }*/
        iFile.close();

    }
    else
    {
        std::cout << "some shit iFile" << std::endl;
    }
    std::ofstream oFile("../rcs/output.txt");
    if(oFile)
    {
        oFile << ss.str();
    }
    else
    {
        std::cout << "some shit oFile" << std::endl;
    }
    oFile.close();

}
