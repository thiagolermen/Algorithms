/*
    Insertion Sort Algorithm
    Author: Thiago Sotoriva Lermen
    Complexity: O(n²)

    Insertion sort is a simple sorting algorithm 
    that works the way we sort playing cards in our hands.
*/


#include <iostream>

using namespace std;

void insertionSort(int C[], int n){
    int i, key, j;
    for(j=1;j<n;j++){
        key = C[j];
        // insert the key in the ordered sequence C[1..j-1]
        i = j-1;
        while((i>=0) && (C[i]>key)){
            C[i+1] = C[i];
            i = i-1;
        }
        C[i+1] = key;
    }
}

void printArray(int C[], int n){
    for(int i=0;i<n;i++)
        cout << "[" << C[i] << "] ";
    cout << endl;
}


int size(){
    return 100;
    //return 1000
}

int main(){
    int C[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "CURRENT ARRAY: " << endl;
    printArray(C, 10);
    cout << "SORTED ARRAY: " << endl;
    insertionSort(C, 10);
    printArray(C, 10); 

    return 0;
}