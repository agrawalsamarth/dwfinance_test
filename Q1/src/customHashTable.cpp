#include <customHashTable.hh>

namespace dwf_test
{


//initialize the hash table with constant size
customHashTable::customHashTable(long int table_size)
{
    size = table_size;
    keys.resize(size);
    vals.resize(size,-1); //initialize all values with -1
    isTaken.resize(size, false);
}

customHashTable::~customHashTable()
{
    keys.clear();
}

long int customHashTable::basicHashFunction(std::string key) //ideally we should create a factory to have multiple hash functions, 
                                                            // a simple idea is to consider all characters to be different prime numbers. And each word is a product of these characters. I'd implement that if I had more time
{
    long int sum=0;

    for (char c : key)
        sum = (sum+c)%size; //the hash function is sum of all characters in the functions modulo table size

    return sum;
}

void customHashTable::insertViaLinearCollision(std::string key, long int val)
{
    long int i=basicHashFunction(key);

    while (isTaken[i] == true){ //if key already exists
        
        if (keys[i] == key){ //and if the key is the same as passed in the fucntion then modify the associated value of the key
            vals[i] = val;
            isTaken[i] = true;
            return;
        }

        i = (i+1)%size; //if the key value is not the same as the one stored move the index one step ahead
    }

    keys[i] = key; //insert new value of key-val pair if index is unoccupied
    vals[i] = val;
    isTaken[i] = true; //set index to taken

}

long int customHashTable::getKeyVal(std::string key)
{
    long int i=basicHashFunction(key); //get first index from hash function

    while (isTaken[i] == true){
        if (keys[i] == key) //move index ahead until next key is found
            return vals[i];
        i = (i+1)%size;
    }

    return -1; // return -1 (equal to not found) if key is not found

}



}