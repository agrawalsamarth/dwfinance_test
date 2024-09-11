#include <iostream>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <cstring>
#include <unistd.h>
#include <netdb.h>

#ifndef CONNECTOR_HH
#define CONNECTOR_HH

namespace dwf_test{

class connector
{

public:

    void init_openssl(); 
    void cleanup_openssl(); 
    void create_context();
    void perform_request(std::string &result);
    connector();
    ~connector();


private:

    SSL_CTX *ctx;
    std::string HOST_NAME    = "fapi.binance.com"; //baseURL
    std::string HOST_PORT    = "443"; 
    std::string REQUEST_PATH = "/fapi/v1/aggTrades?symbol=BTCUSDT"; //GET connectivity as mentioned in the test
};

}

#endif