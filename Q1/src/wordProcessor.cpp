#include <wordProcessor.hh>

namespace dwf_test
{

wordProcessor::wordProcessor(std::string style)
{
    char_factory   = new legitfactory; //create a factory for legitimate characters
    differentiator = char_factory->create_legitchar_style(style); //create a legitimate character class from the factory
}

std::string wordProcessor::get_next_word(std::string text, int &start, int end)
{
    
    static std::string word;
    word = "";
    int counter;

    while (start < end){

        if (differentiator->isLegitCharacter(text[start])) //if the character at the cursor is a legitimate character
            word += text[start++]; //add it to the word

        else if (word.size() > 0) //if not and the word not blank return word
            return word;

        else //otherwise move the cursor ahead
            start++;

    }

    return word;

}



}