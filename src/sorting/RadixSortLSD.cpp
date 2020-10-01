/*
    Radix Sort Algorithm
    Author: Thiago Sotoriva Lermen
    Complexity: Θ(n*log n)
*/

#include <iostream>

using namespace std;

void printArray(int C[], int n){
    for(int i=0;i<n;i++)
        cout << "[" << C[i] << "] ";
    cout << endl;
}

int findHighest(int a[], int size){
    int h = a[0];
    for(int i = 0 ; i < size ; i++){
        if (a[i] > h){
            h = a[i];
        }
    }
    return h;
}

void countingSort(int input[], int output[], int exp, int input_size){
    int aux[10] = {0}; // Aux array

    // Init aux vector with 0
    for (int i=0; i < input_size;i++){
        aux[i] = 0;
    }

    // aux[i] contains the number of elements equal to i
    for (int j = 0 ; j < input_size ; j++){
        aux[(input[j]/exp)%10]++;
    }

    // aux[i] contains the number of elements less than or equal to i
    for (int i = 1 ; i < 10 ; i++){
        aux[i] = aux[i-1] + aux[i];
    }

    for (int j = input_size-1; j >= 0 ; j--){
        output[aux[(input[j]/exp)%10] - 1] = input[j];
        aux[(input[j]/exp)%10]--;

    }

    for (int i = 0; i < input_size ; i++){
        input[i] = output[i];
    }
}

void radixSort(int a[], int b[], int size){
    
    int m = findHighest(a, size); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m/exp > 0; exp *= 10){
        countingSort(a, b, exp, size); 
    }
}

int main(){
    int a[] = {532, 254, 14, 58, 8};
    int a_size = sizeof(a) / sizeof(a[0]);
    int b[a_size] = {0};
    cout << "CURRENT ARRAY: " << endl;
    printArray(a, a_size);
    cout << "SORTED ARRAY: " << endl;
    radixSort(a, b, a_size);
    printArray(a, a_size); 

    return 0;
}
