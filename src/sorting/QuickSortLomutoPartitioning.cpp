/*
    Quicksort Algorithm using Lomuto's partitioning
    Author: Thiago Sotoriva Lermen
    Complexity: Θ(n*log n)

    Description of Quicksort (by Indroduction of Algorithms, T. Cormen):
    Quicksort, like merge sort, applies the divide-and-conquer paradigm
    for a typical subarray A[p...r]. The Quicksort algorithm has a worst-
    case running time of Θ(n²) on an input array of n numbers. Despite this
    slow worst-case running time, quicksort is often the best practical choice
    for sorting because it is remarkably efficient on the average: its expected
    running time is Θ(n*log n) [...].
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

// Rearranges the subarray a[p...r] in place
int lomutoPartition(int a[], int p, int r){
    int x = a[r]; // Pivot
    int i = p-1; // Index of smaller element
    int j = 0;
    for (j = p ; j <= r-1 ; j++){
        if (a[j] <= x){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[r]);
    return i+1;
}

void quicksort(int a[], int p, int r){
    if (p < r){
        int q = lomutoPartition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}

int main(){
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int a_size = sizeof(a) / sizeof(a[0]);
    cout << "CURRENT ARRAY: " << endl;
    printArray(a, a_size);
    cout << "SORTED ARRAY: " << endl;
    quicksort(a, 0, a_size-1);
    printArray(a, a_size);
    return 0;
}