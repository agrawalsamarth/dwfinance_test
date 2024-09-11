#include <alpha.hh>
#include <alphanum.hh>

#ifndef LEGITFACTORY_HH
#define LEGITFACTORY_HH

namespace dwf_test{

// factory to create legitChar pointer

class legitfactory{

    public:
        legitChar* create_legitchar_style(const std::string style);

};

}

#endif