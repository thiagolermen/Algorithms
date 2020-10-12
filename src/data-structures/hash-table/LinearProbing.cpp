/*
    Author: Thiago Sotoriva Lermen

    Implementation of a hash table using linear probing 
    method for collision handling

*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class HashNode{
    public:
        string key;
        int value;

    HashNode(string key, int value){// Constructor
        this->value = value;
        this->key = key;
    } 

};

class LinearProbingHash{
    
    private:
        // Hash element array
        HashNode **arr;
        int TABLE_SIZE;
        // Current size
        int sz;
        // Dommy node
        HashNode *dummy;

    public:
    
        LinearProbingHash(int table_size){
            this->TABLE_SIZE = table_size;

            this->sz = 0;

            arr = new HashNode* [TABLE_SIZE];

            //Init all alements as NULL
            for (int i = 0 ; i < TABLE_SIZE ; i++)
                arr[i] = NULL;

            // Dummy node with key (string) and value (int) -1
            dummy = new HashNode("-1", -1);
        }

        unsigned hashCode(string key){
            unsigned hash = 0;
            for (int i = 0 ; i < key.length() ; i++){
                hash = key[i] + (31 * hash);
            }
            return hash;
        }

        // Hash function from map values to (hash) key
        int hashFunction1(string s){

            int index = 0;
            unsigned hash_code = hashCode(s);

            index = (hash_code & 0x7fffffff) % TABLE_SIZE;

            return index;
        }

        int hashFunction2(string s){
            int hash = 0;
            for (int i = 0 ; i < s.length() ; i++){
                hash += s[i];
            }

            return hash % TABLE_SIZE;
        }

        void insertKey(string key, int value){
            HashNode *temp = new HashNode(key, value);

            int index = hashFunction1(key);
            //int index = hashFunction2(key);

            // Find next free space (probing)
            while (arr[index] != NULL && arr[index]->key != key && arr[index]->key != "-1"){
                index++;
                index %= TABLE_SIZE;
            }

            // Valid position
            if (arr[index] == NULL || arr[index]->key == "-1")
                sz++;

            arr[index] = temp; 

        }

        int  deleteKey(string key){
            int index = hashFunction1(key);
            //int index = hashFunction2(key);

            // Finding the node with given key
            while (arr[index] != NULL){
                // if node found
                if (arr[index]->key == key){
                    HashNode *temp = arr[index];

                    // INsert dummy node
                    arr[index] = dummy;

                    sz--;

                    return temp->value;
                }
                index++;
                index %= TABLE_SIZE;
            
            }
        }


        int searchKey(string key){
            int index = hashFunction1(key);
            //int index = hashFunction2(key);

            int count = 0;

            // find node with given key
            while (arr[index] != NULL){

                // Avoid infinite loop
                if (count++ > TABLE_SIZE)
                    return -2;

                // If the key has been found
                if (arr[index]->key == key)
                    return arr[index]->value;

                index++;
                index %= TABLE_SIZE;
            }

            // If not found return -2
            return -2;
        }

        void printHashTable(){
            for (int i = 0 ; i < TABLE_SIZE ;i++){
                if (arr[i] != NULL && arr[i]->key != "-1")
                    cout << "key = " << arr[i]->key << " value = " << arr[i]->value << endl;
            }
        }
};

void printVector(vector<string> a){
    for (int i  = 0 ; i < a.size() ; i++){
        cout << a[i] << endl;
    }
    cout << endl;
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

int main(){
    
    vector<string> w = {"Lorem", "ipsum", "dolor", "sit", "amet", 
    "consectetur", "adipiscing", "elit", "Quisque", "ultrices", "eros", "ex",
    "a", "suscipit", "nibh", "consequat", "quis", "Etiam", "venenatis",
    "aliquet", "imperdiet"};

    int n = w.size();
    int table_size = nextPrime(n);

    LinearProbingHash h = LinearProbingHash(table_size);

    //---------------------------------------------------------
    //                 LINEAR PROBING HASH
    //---------------------------------------------------------

        printVector(w);
        for (int i = 0 ; i < n ; i++)
            h.insertKey(w[i], i+1);

        h.printHashTable();

    //---------------------------------------------------------



    return 0;
}