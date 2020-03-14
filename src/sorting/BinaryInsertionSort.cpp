/*
    Binary Insertion Sort
    Author: Thiagop Sotoriva Lermen
    Complexity: O(n²)
    
*/

#include <iostream>

using namespace std;

int binarySearch(int C[], int item, int l, int h){
    if(h <= l)
        return (item > C[l])? (l+1): l;
    int mid = (l+h)/2;
    if(item == C[mid])
        return mid+1;
    if(item > C[mid])
        return binarySearch(C, item, mid+1, h);
    return binarySearch(C, item, l, mid-1);
}

void binaryInsertionSort(int C[], int n){
    int i, loc, j, k, selected;
    for(i=1;i<n;i++){
        j = i-1;
        selected = C[i];
        loc = binarySearch(C, selected, 0, j);
        while(j>=loc){
            C[j+1] = C[j];
            j--;
        }
        C[j+1] = selected;
    } 
}
void printArray(int C[], int n){
    for(int i=0;i<n;i++)
        cout << "[" << C[i] << "] ";
    cout << endl;
}

int main(){
    int C[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "CURRENT ARRAY: " << endl;
    printArray(C, 10);
    cout << "SORTED ARRAY: " << endl;
    binaryInsertionSort(C, 10);
    printArray(C, 10); 

    return 0;
}