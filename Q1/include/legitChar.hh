#include <iostream>

#ifndef LEGITCHAR_HH
#define LEGITCHAR_HH

namespace dwf_test
{

//base class to check if a character could be a part of a word

class legitChar
{
    public:
        virtual bool isLegitCharacter(const char c) {}; //function is virtual as it could possibly take on many definitions

};

}

#endif