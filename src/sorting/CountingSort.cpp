/*
    Counting Sort Algorithm
    Author: Thiago Sotoriva Lermen
    Complexity: Θ(n)
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

void countingSort(int input[], int output[], int h, int input_size){
    int aux[h+1]; // Aux array

    // Init aux vector with 0
    for (int i=0; i < h+1;i++){
        aux[i] = 0;
    }

    // aux[i] contains the number of elements equal to i
    for (int j = 0 ; j < input_size ; j++){
        aux[input[j]]++;
    }

    // aux[i] contains the number of elements less than or equal to i
    for (int i = 1 ; i < h+1 ; i++){
        aux[i] = aux[i-1] + aux[i];
    }

    for (int j = input_size-1; j >= 0 ; j--){
        output[aux[input[j]] - 1] = input[j];
        aux[input[j]]--;

    }
}

int main(){
    int a[] = {3,4,1,4,1,3};
    int a_size = sizeof(a) / sizeof(a[0]);
    int b[a_size] = {0};
    cout << "CURRENT ARRAY: " << endl;
    printArray(a, a_size);
    cout << "SORTED ARRAY: " << endl;
    int h = findHighest(a, a_size);
    countingSort(a,b,h,a_size);
    printArray(b, a_size);
    return 0;
}