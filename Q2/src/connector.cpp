#include <connector.hh>

namespace dwf_test
{

//initialize ssl functions
void connector::init_openssl()
{
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

//cleanup ssl functions
void connector::cleanup_openssl()
{
    EVP_cleanup();
}

connector::~connector()
{
    SSL_CTX_free(ctx);
    cleanup_openssl();    
}

void connector::create_context()
{
    const SSL_METHOD *method;
    method = SSLv23_client_method();

    ctx = SSL_CTX_new(method);
    if (!ctx) {
        std::cerr << "Unable to create SSL context" << std::endl;
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
}

connector::connector()
{
    init_openssl();
    create_context();
}

void connector::perform_request(std::string &result)
{
    struct addrinfo hints, *res;
    int sock;
    SSL *ssl;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Resolve the host name
    if (getaddrinfo(HOST_NAME.c_str(), HOST_PORT.c_str(), &hints, &res) != 0) {
        std::cerr << "Could not resolve host: " << HOST_NAME << std::endl;
        exit(EXIT_FAILURE);
    }

    // Create a socket
    sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock < 0) {
        std::cerr << "Could not create socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sock, res->ai_addr, res->ai_addrlen) != 0) {
        close(sock);
        std::cerr << "Could not connect to host" << std::endl;
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    // Create SSL object
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    

    // Perform SSL handshake
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    } else {
        // Prepare the HTTP GET request
        std::string request = "GET " + std::string(REQUEST_PATH) + " HTTP/1.1\r\n"
                              "Host: " + std::string(HOST_NAME) + "\r\n"
                              "Connection: close\r\n\r\n";

        // Send the request
        SSL_write(ssl, request.c_str(), request.size());

        // Read the response
        char buffer[4096];
        int bytes;
        result = "";
        //int counter=0;
        while ((bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
        
            buffer[bytes] = 0;
            result += buffer; //add received information to result string
        }
        //std::cout<<counter<<std::endl;
    }

    // Cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    //return buffer;

}


}