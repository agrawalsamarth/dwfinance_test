#include <connector.hh>
#include <vector>

#ifndef PARSERFORBINANCE_HH
#define PARSERFORBINANCE_HH

namespace dwf_test
{

class parserForBinance
{
    public:

        void printAllTrades(int &num_trades);
        inline void printNextTrade();
        parserForBinance(std::string response);

    private:

        std::string text;
        std::string prefix="[\n {\n  "; //prefix for the parsing
        std::string suffix=",\t// Was the buyer the maker?\n }\n].\n"; //suffix for the parsing
        int loc=0;
        std::vector<std::string> comments; //vector of strings, as comments for each parameter
        char start_char='['; //start point of where the trades information begin
        int counter;
        
};


}


#endif