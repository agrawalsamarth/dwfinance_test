#include <parserForBinance.hh>

namespace dwf_test
{

parserForBinance::parserForBinance(std::string response)
{
    text = response;

    //search to the point where the trades information begins

    for (loc = 0; loc < text.size();loc++){ 
        if (text[loc]==start_char)
            break;
    }    
    
    //initialize all the comments for the different parameters

    comments.push_back(",\t// Aggregate tradeId\n  ");
    comments.push_back(",\t// Price\n  ");
    comments.push_back(",\t// Quantity\n  ");
    comments.push_back(",\t// First tradeId\n  ");
    comments.push_back(",\t// Last tradeId\n  ");
    comments.push_back(",\t// Timestamp\n  ");
}

inline void parserForBinance::printNextTrade()
{
    std::string trade = prefix; //initialize the string with the set prefix
    counter = 0;

    while (text[loc] != '}'){ //search until } when a single trade information closes

        if (text[loc] == '{'){ //already added in prefix
            loc++;
            continue;
        }

        if (text[loc] == ','){ //if there is , then parameter changes
            trade += comments[counter++]; //a comment is added and the counter is incremented for comments
            loc++;
        }

        else{ //otherwise added in the parsing
            trade += text[loc++];
        }

    }

    trade += suffix; //when } is found the preset suffix is added
    std::cout<<trade;
}

void parserForBinance::printAllTrades(int &num_trades)
{
    while (loc < text.size()){
        if (text[loc] == '{'){ //call printNextTrade when the cursor is at { and a new trade information begins
            printNextTrade();
            num_trades++;
        }
        else{
            loc++;
        }
    }
}



}