#include <completeDatabase.hh>

using namespace dwf_test;

int main()
{
    completeDatabase *db_test = new completeDatabase;
    std::string ex_text = "This sentence is a test case. This should help us evaluate the project.";
    std::cout<<ex_text<<"\n\n---------------------------------------------------------------------\n\n";
    db_test->fillText(ex_text);

    std::string key;
    int val;

    std::cout<<"The expected most recent modified word is -- project\n";
    db_test->get_last(key, val);
    std::cout<<"The answer from the code is found to be -- "<<key<<"\n";

    std::cout<<"The expected least recent modified word is -- sentence\n";
    db_test->get_first(key, val);
    std::cout<<"The answer from the code is found to be -- "<<key<<"\n";

    std::cout<<"We now remove sentence from the database\n";
    db_test->remove("sentence");
    db_test->get_first(key,val);
    std::cout<<"The updated least recent modified word from the code now is -- "<<key<<"\n";


    return 0;

}