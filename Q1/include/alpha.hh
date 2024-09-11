#include <legitChar.hh>

#ifndef ALPHA_HH
#define ALPHA_HH

namespace dwf_test
{

//derived class is legitChar, which checks if a given character is an alphabet

class alpha: public legitChar{

public:
    bool isLegitCharacter(const char c);

};


}

#endif