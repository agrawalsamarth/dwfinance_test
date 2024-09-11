#include <alphanum.hh>

namespace dwf_test
{

bool alphaNum::isLegitCharacter(const char c)
{
    return (isalnum(c)); //returns if character is alphanumeric
}


}