#include <legitFactory.hh>

#ifndef WORDPROCESSOR_HH
#define WORDPROCESSOR_HH

namespace dwf_test{

class wordProcessor
{

// class to extract words from text

public:

    std::string get_next_word(const std::string text, int &start, int end);
    wordProcessor(std::string style);

private:

    legitfactory *char_factory;
    legitChar *differentiator;

};


}


#endif