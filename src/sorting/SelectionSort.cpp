/*
    Selection Sort Algorithm
    Author: Thiago Sotoriva Lermen
    Complexity: O(n²)
*/

#include <iostream>

using namespace std;

void printArray(int C[], int n){
    for(int i=0;i<n;i++)
        cout << "[" << C[i] << "] ";
    cout << endl;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int a[], int n){
    int i, j, min_index;

    for (i = 0; i< n-1; i++){
        // Find minimum element
        min_index = i;
        for (j=i+1;j< n;j++){
            if(a[j] < a[min_index])
                min_index = j;
            swap(&a[min_index], &a[i]);
        }
    }
}

int main(){

    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int a_size = sizeof(a) / sizeof(a[0]);

    cout << "CURRENT ARRAY: " << endl;
    printArray(a, a_size);
    cout << "SORTED ARRAY: " << endl;
    selectionSort(a, a_size);
    printArray(a, a_size); 
    return 0;
}