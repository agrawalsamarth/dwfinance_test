#include <webCrawler.hh>

namespace dwf_test{

//curl initialization
webCrawler::webCrawler()
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
}

//writecallback function for curl
size_t webCrawler::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t totalSize = size * nmemb;
    userp->append((char*)contents, totalSize);
    return totalSize;
}

//destructor to cleanup curl
webCrawler::~webCrawler()
{
    curl_global_cleanup();
}

std::string webCrawler::get_contents(const std::string websiteName)
{
    if(curl) {
        // setup curl for url
        curl_easy_setopt(curl, CURLOPT_URL, websiteName.c_str());

        // setup curl for handle data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // function to write the data
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // to perform the request
        res = curl_easy_perform(curl);

        // error check
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }         curl_easy_cleanup(curl);
    }

    return readBuffer;

}



}