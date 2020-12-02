//
// Created by btnt51 on 12/2/2020.
//

#include "CMenu.h"

void CMenu::menu()
{
    while (true)
    {
        std::cout << "1)string\n"
                  << "2)wstring\n"
                  << "3)char\n"
                  << "4)wchar_t\n"
                  << "5)exit\n";

        char item;
        std::cin >> item;

        //std::string str;
        //std::getline(std::cin, str);
        CFile file;
        switch (item)
        {
            case'1':
                file.string();
                break;
            case'2':
                file.wstring();
                break;
            case'3':
                file.cstring();
                break;
            case'4':
                file.wcstring();
                break;
            case'5':
                exit(0);
            default:
                break;
        }
    }
}
