#include <completeDatabase.hh>

using namespace dwf_test;

void perform_action(completeDatabase *db_test, int choice)
{

    std::string key;
    int val;

    std::cout<<"\n\n--------------------------------------\n";

    switch(choice){

        case 1:
            std::cout<<"please enter the word for fetching the key: ";
            std::cin>>key;
            val = db_test->get(key);

            if (val==-1)
                std::cout<<"the word does not exist in the database\n";
            else
                std::cout<<"the key for the word is -- "<<val<<"\n";
            break;

        case 2:
            std::cout<<"please enter the word to remove from the database: ";
            std::cin>>key;
            std::cout<<"word to be removed is "<<key<<std::endl;
            db_test->remove(key);
            std::cout<<"\n";
            break;

        case 3:
            db_test->get_last(key, val);
            std::cout<<"the key that was most recently changed is -- "<<key<<"\n";
            break;

        case 4:
            db_test->get_first(key, val);
            std::cout<<"the key that was least recently changed is -- "<<key<<"\n";
            break;

        case 5:
            std::cout<<"exiting program\n";
            break;

        default:
            std::cout<<"please enter a valid choice\n";
            break;

    }

    std::cout<<"--------------------------------------\n\n";

}


int main()
{
    completeDatabase *db_test = new completeDatabase; 
    db_test->scrapeData(); //to scrape data from the website

    std::cout<<"-------------------web data scraping is complete-------------------\n";

    int choice;
    std::string choice_str;

    //subroutine for implementing various functions of the module

    do{
        std::cout<<"Please enter the action to be performed\n";
        std::cout<<"1. Get value of key\n";
        std::cout<<"2. Remove key from database\n";
        std::cout<<"3. Get word that was most recently changed\n";
        std::cout<<"4. Get word that was least recently changed\n";
        std::cout<<"5. Exit program\n";
        std::cout<<"Your input: ";

        std::cin>>choice_str;

        try {
            choice = std::stoi(choice_str);
            perform_action(db_test, choice);            
        } catch (const std::invalid_argument& e) {
            std::cout<<"\n\n--------------------------------------\n";std::cout<<"please enter a valid choice\n";
            std::cout<<"--------------------------------------\n\n";choice=6;
        } catch (const std::out_of_range& e) {
            std::cout<<"\n\n--------------------------------------\n";std::cout<<"please enter a valid choice\n";
            std::cout<<"--------------------------------------\n\n";choice=6;
        }

    }while(choice != 5);


    return 0;

}