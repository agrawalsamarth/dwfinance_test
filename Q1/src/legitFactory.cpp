#include <legitFactory.hh>

namespace dwf_test
{

legitChar* legitfactory::create_legitchar_style(std::string style)
{
    if (style == "alpha") // if alphabets are the only legitimate characters allowed
        return new alpha; // then return alpha derived class
    else if (style == "alpha_num") // if alphanumerics are legitimate characters allowed
        return new alphaNum; // then return alphanumeric derived class
    else { //otherwise error message and exit
        std::cout<<"unknown character type, exiting program"<<std::endl;
        exit(EXIT_FAILURE);
    }
}

}