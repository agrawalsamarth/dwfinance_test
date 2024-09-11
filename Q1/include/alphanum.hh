#include <legitChar.hh>

#ifndef ALPHANUM_HH
#define ALPHANUM_HH

namespace dwf_test
{

//derived class is legitChar, which checks if a given character is alphanumeric


class alphaNum: public legitChar{

public:
    bool isLegitCharacter(const char c);

};


}

#endif