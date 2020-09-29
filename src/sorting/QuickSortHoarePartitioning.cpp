/*
    Quicksort Algorithm using Hoare's partitioning
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
int hoarePartition(int a[], int p, int r){
    int x = a[p]; // Set the pivot value
    int i = p-1;
    int j = r+1;
    while(true){
        do{
            i++;
        }while(a[i] < x);

        do{
            j--;
        }while(a[j] > x);

        if (i >= j)
            return j;
            
        swap(&a[i], &a[j]);
    }

}

void quicksort(int a[], int p, int r){
    if (p < r){
        int q = hoarePartition(a, p, r);
        quicksort(a, p, q);
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