#include <webCrawler.hh>
#include <wordProcessor.hh>
#include <customHashTable.hh>

#ifndef COMPLETEDATABASE_H
#define COMPLETEDATABASE_H

namespace dwf_test
{

//The structure to build and maintain the database.


class completeDatabase
{
    public:

        void insert(std::string key, int val);
        int  get(std::string key);
        void remove(std::string key);
        void get_last(std::string &key,  int &val);
        void get_first(std::string &key, int &val);
        void scrapeData(); //function to scrape data using the webcrawler class 
        void fillText(std::string text_fill); //function to fill in text using a string defined in main
        void buildDB();

        completeDatabase();
        ~completeDatabase();
        std::string convert_str_to_lower(std::string str);

    private:

        webCrawler *webCrawler_ptr; //pointer object to the webcrawler class for scraping data
        wordProcessor *wordProcessor_ptr; //pointer object to wordprocessor class for processing the data that is scraped by the webcrawler class
        customHashTable *customHashTable_ptr; //pointer object to custom hash table to store the keys and associated values for the words in the text
        
        std::string website_name="https://www.gutenberg.org/files/98/98-0.txt"; //name of the website to scrape text from
        std::string char_style="alpha"; //to check legitimacy of characters to form words
        std::string text; //string type variable to store data from the website
        std::vector<std::string> all_words; //string vector to store all the words that are found while processing

        int minLen=1; // minimum length of the words to be added in the database. default value is 1.
        int start; //int variable to track the index of the cursor to process the data word wise 
        int end; // the maximum possible value attainable by the cursor
        int topCount=0; // counter to keep track of the least recently used word



};


}

#endif