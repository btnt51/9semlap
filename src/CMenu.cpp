//
// Created by btnt51 on 12/2/2020.
//

#include "CMenu.h"

void CMenu::menu()
{
    while (true)
    {
        std::cout    << "Choose which type of data you want to work with. \n"
                     << "To do this, enter the appropriate number. \n"
                     << "1)string\n"
                     << "2)wstring\n"
                     << "3)char\n"
                     << "4)wchar_t\n"
                     << "To exit, enter \"5\".\n";

        char item;
        std::cin >> item;
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
