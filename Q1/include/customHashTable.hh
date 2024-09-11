#include <iostream>
#include <vector>

#ifndef CUSTOMHASHTABLE_H
#define CUSTOMHASHTABLE_H

namespace dwf_test
{

class customHashTable{

    public:

        long int  basicHashFunction(std::string key); //the hash function to for key-val pairs
        void insertViaLinearCollision(std::string key, long int val); //function to insert new key-val pair
        long int  getKeyVal(std::string key); //function to get the value based on the key
        customHashTable(long int table_size);
        ~customHashTable();

    private:

        std::vector<std::string> keys; //string vector to hold the keys
        std::vector<long int> vals; // int vector to hold the corresponding values
        std::vector<bool> isTaken; //to see if an index has already been taken
        long int size;

};


}

#endif