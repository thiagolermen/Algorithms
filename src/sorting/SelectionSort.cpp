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
    int min_index;
    for (int i = 0 ; i < n-1 ; i++){
        // Find minimum element
        min_index = i;
        for (int j = i + 1 ; j < n ; j++)
            if(a[j] < a[min_index])
                min_index = j;

        swap(&a[i], &a[min_index]);
    }
    
}

int main(){

    int a[] = {8,3,2,6,1,4,7,5};
    int a_size = sizeof(a) / sizeof(a[0]);

    cout << "CURRENT ARRAY: " << endl;
    printArray(a, a_size);
    selectionSort(a, a_size);
    cout << "SORTED ARRAY: " << endl;
    printArray(a, a_size); 
    return 0;
}