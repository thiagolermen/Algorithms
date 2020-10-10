/*
    Author: Thiago Sotoriva Lermen

    Implementation of a hash table using separate chaining method
    with a linked list for collision handling

*/

#include <iostream>
#include <list>

using namespace std;

// Hash Map, using separate chaining, declaration
class SeparateChainingHash{
    // Data members accessed using methods
    private:
        int TABLE_SIZE;
        list<int> *table; // Pointer to an array containing the lists
    
    // Methods
    public:

        SeparateChainingHash(int sz); // Constructor
        
        // Inserts a key into hash table
        void insertKey(int x);

        // Deletes a key from hash table
        void deleteKey(int x);

        // Hash function to map values to (hash) key
        int hashFunction(int value){
            return value % TABLE_SIZE;
        }

        void printHashTable();

};

SeparateChainingHash::SeparateChainingHash(int sz){
    this->TABLE_SIZE = sz;
    table = new list<int>[TABLE_SIZE];
}

void SeparateChainingHash::insertKey(int key){

    int index = hashFunction(key); // Get the hash index
    table[index].push_back(key); // Insert 'key' to the linked list at 'index'

}

void SeparateChainingHash::deleteKey(int key){

    // Get the hash index
    int index = hashFunction(key);

    // Find the key in the list
    list<int>::iterator i;
    for (i = table[index].begin() ; i != table[index].end() ; i++){
        if (*i == key) // The key has been found
            break;
    }

    // If the key is found in hash table, delete it
    if (i != table[index].end())
        table[index].erase(i);

}

bool isPrime(int n){
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i=5 ; i*i <= n ; i = i+6){
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int nextPrime(int n){
    if (n <= 1)
        return 2;

    int prime = n;
    bool found = false;

    while (!found){
        prime++;

        if (isPrime(prime))
            found = true;
    }

    return prime;
}

void SeparateChainingHash::printHashTable(){
    for (int i = 0 ; i < TABLE_SIZE ; i++){
        cout << i;
        for (auto x : table[i]){
            cout << "-->" << x;
        }
        cout << endl;
    }
}

int main(){
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a)/sizeof(a[0]);
    int table_size = nextPrime(n);

    SeparateChainingHash h (table_size);

    for (int i = 0 ; i < n ; i++)
        h.insertKey(a[i]);
    
    h.deleteKey(12);

    h.printHashTable();

    return 0;
}

