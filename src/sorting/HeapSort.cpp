/*
    Heapsort (using max-heaps)
    Author: Thiago Sotoriva Lermen
    Complexity: O(n*log n)
    
*/


#include <iostream>
#include <cmath>

using namespace std;

// Print the array
void printArray(int C[], int n){
    for(int i=0;i<n;i++)
        cout << "[" << C[i] << "] ";
    cout << endl;
}
// Return the parent of a[i]
int parent(int i){
    return floor(i/2);
}
// Return the left child of a[i]
int left(int i){
    return 2*i + 1;
}

// Return the right child of a[i]
int right(int i){
    return 2*i + 2;
}

// Maintain the max-heap property
void maxHeapfy(int a[], int i, int size){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if((l < size) && (a[l] > a[largest])){
        largest = l;
    }else{
        largest = i;
    }
    if((r < size) && (a[r] > a[largest])){
        largest = r;
    }
    if(largest != i){
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        maxHeapfy(a, largest, size);
    }

}

// Build the max-heap
void buildMaxHeap(int a[], int size){
    for(int i=(size/2)-1;i>=0;i--){
        maxHeapfy(a, i, size);
    }
}

// Sort the array
void heapsort(int a[], int size){
    buildMaxHeap(a, size);
    for(int i=size-1;i>0;i--){
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        maxHeapfy(a, 0, i);
    }
}

int main(){
    int C[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "CURRENT ARRAY: " << endl;
    printArray(C, 10);
    cout << "SORTED ARRAY: " << endl;
    heapsort(C, 10);
    printArray(C, 10); 

    return 0;
}




