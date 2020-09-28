/*
    Shell Sort
    Author: Thiago Sotoriva Lermen
    Complexity: O(n²) or Θ(n*log n)
*/

#include <iostream>

using namespace std;

void shellSort(int C[], int n){
    int gap = 1;
    do{
        gap = 3*gap+1;
    }while(gap < n);

    do{
        gap /= 3;
        for(int i=gap;i<n;i++){
            int value = C[i];
            int j = i-gap;

            while(j>=0 && value < C[j]){
                C[j+gap] = C[j];
                j-=gap;
            }
            C[j+gap] = value;
        }
    }while(gap > 1);
}

void printArray(int C[], int n){
    for(int i=0;i<n;i++)
        cout << "[" << C[i] << "] ";
    cout << endl;
}

int main(){
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int a_size = sizeof(a) / sizeof(a[0]);
    cout << "CURRENT ARRAY: " << endl;
    printArray(a, a_size);
    cout << "SORTED ARRAY: " << endl;
    shellSort(a, a_size);
    printArray(a, a_size); 

    return 0;
}