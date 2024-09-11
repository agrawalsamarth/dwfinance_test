#include <iostream>
#include <string>
#include <curl/curl.h> // this class uses the curl library to establish connection with the website

#ifndef WEBCRAWLER_HH
#define WEBCRAWLER_HH

namespace dwf_test{

// class to scrape data from a website

class webCrawler
{

private:

    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp);

public:

    webCrawler();
    ~webCrawler();
    std::string get_contents(const std::string websiteName); 


};

}

#endif