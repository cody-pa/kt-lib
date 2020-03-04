/*********************************************************************************
* a bunch of things i've defined for my own convenience.
* I store this file in source control and link it from multiple projects
*********************************************************************************/

#ifndef KP_LIB_CPP_H
#define KP_LIB_CPP_H

#include <string>
#include <ostream>
#include <iostream>
#include "../C/lib.h"
#include <cctype>

namespace kp
{
    template <typename T>
    bool yn_prompt(T prompt, bool clear_screen, std::ostream& out=std::cout, std::istream& in = std::cin)
    {
        char input = '\0';
        while (input != 'y' && input != 'n')
        {
            if (clear_screen)
                CLEAR_SCREEN;

            out << prompt;

            try
            {
                in >> input;
                input = tolower(input);
            }
            catch(...)
            {

            }
        }
        return input == 'y';
    }
}

#endif


