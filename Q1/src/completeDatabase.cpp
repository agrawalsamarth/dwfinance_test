#include <completeDatabase.hh>

namespace dwf_test{

//create necessary pointer objects
completeDatabase::completeDatabase()
{
    webCrawler_ptr = new webCrawler;
    wordProcessor_ptr = new wordProcessor(char_style);
}

completeDatabase::~completeDatabase()
{
    delete webCrawler_ptr;
    delete wordProcessor_ptr;
    delete customHashTable_ptr;
    all_words.clear();
}

void completeDatabase::scrapeData()
{
    text  = webCrawler_ptr->get_contents(website_name); //fill text with the data scraped from the url
    start = 0;
    end   = text.size(); 
    customHashTable_ptr = new customHashTable(end); //initialize the hash table by the size of the string. As it is impossible to have more words 
                                                    // than the size of the text itself 

    buildDB();
}

void completeDatabase::fillText(std::string text_fill)
{
    text = text_fill; //fill text by a script
    start = 0;
    end   = text.size();
    customHashTable_ptr = new customHashTable(end);

    buildDB();
}

void completeDatabase::buildDB()
{
    std::string word;
    std::string l_word;
    int word_count=0;

    while (start < end){ //iterate until cursor reaches the end

        word = wordProcessor_ptr->get_next_word(text, start, end); //get the next word 

        if(word.size() >= minLen){ //if the word is greater than the minimum length
            l_word = convert_str_to_lower(word); //convert the word to lower case
            insert(l_word, word_count++); //insert the word in the hash table and with the value being the word count
        }
    }
}

std::string completeDatabase::convert_str_to_lower(std::string str)
{
   std::string l_str="";

   for (auto c : str){
        l_str += tolower(c); //convert each character to lower case
   }

   return l_str;
}

void completeDatabase::insert(std::string key, int val)
{
    customHashTable_ptr->insertViaLinearCollision(key, val); //insert a given key-value pair to the hash table
    all_words.push_back(key); //add the word to the vector of all words found sequentially going through the text
}

int completeDatabase::get(std::string key)
{
    std::string lowercase_key = convert_str_to_lower(key);
    return customHashTable_ptr->getKeyVal(key);
}

void completeDatabase::get_last(std::string &key, int &val)
{
    //Since the words are added sequentially the one at the back of the vector were added at last
    //therefore they were modified at last 

    for (long int i = all_words.size()-1; i >=0; i--){

        if (get(all_words[i]) != -1){ //check if the word still exists in db and not removed externally
            key = all_words[i];
            val = i;
            return;
        }
    }

    return;
}

void completeDatabase::get_first(std::string &key, int &val)
{

    //Since words are added sequentially the ones at the top were added first and modified least recently 
    //unless they were modified again. If the key-value pair is the same as the word count, that implies 
    //the word was not found in the text again, thereby being the least recently modified word.   

    while (true){
        if (get(all_words[topCount]) == topCount){
            key = all_words[topCount];
            val = topCount;
            return;
        }
        else{
            topCount++;
        }
    }

    return;
    
}

void completeDatabase::remove(std::string key)
{

    std::string lowercase_key = convert_str_to_lower(key);

    if (customHashTable_ptr->getKeyVal(lowercase_key) != -1) //if key exists then
        customHashTable_ptr->insertViaLinearCollision(lowercase_key,-1); //set to -1
    else
        std::cout<<"key does not exist cannot be removed"<<std::endl;


}


}