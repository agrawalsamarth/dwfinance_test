#include <connector.hh>
#include <parserForBinance.hh>
#include <chrono>

using namespace dwf_test;

int main()
{
    
    std::chrono::steady_clock::time_point cp_1;
    std::chrono::steady_clock::time_point cp_2;
    std::chrono::steady_clock::time_point cp_3;
    std::chrono::steady_clock::time_point cp_4;

    double time_1=0.;
    double time_2=0.;
    int num_trades=0;
    
    cp_1 = std::chrono::steady_clock::now();
    connector *test = new connector; //new connector class opinter object
    std::string buffer;
    test->perform_request(buffer); //get the information,
    //std::cout<<buffer;
    cp_2 = std::chrono::steady_clock::now();
    time_1=std::chrono::duration_cast<std::chrono::nanoseconds>(cp_2 - cp_1).count();

    cp_3 = std::chrono::steady_clock::now();
    parserForBinance *p_test = new parserForBinance(buffer); //new parserForBinance class pointer object
    p_test->printAllTrades(num_trades); //print all trades in parsed format
    cp_4 = std::chrono::steady_clock::now();
    time_2=std::chrono::duration_cast<std::chrono::nanoseconds>(cp_4 - cp_3).count();
    std::cout<<"time taken to read from binance = "<<(time_1*1e-6)<<" milliseconds\n";
    std::cout<<"time taken to parse "<<num_trades<<" trades = "<<(time_2*1e-6)<<" millisseconds\n";
    std::cout<<"total time taken = "<<((time_1+time_2)*1e-6)<<" millisseconds\n";

    delete test;
    delete p_test;

    return 0;
}