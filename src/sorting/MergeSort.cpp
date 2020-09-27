/*
    Merge Sort Algorithm
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

void merge(int a[], int left, int middle, int right){
    int i,j,k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temp arrays
    int sub_left_array[n1];
    int sub_right_array[n2];

    // Copy data to temp arrays sub_left_array and sub_right_array
    for (i = 0 ; i < n1 ;i ++)
        sub_left_array[i] = a[left + i];
    for (j = 0 ; j < n2 ;j ++)
        sub_right_array[j] = a[middle+1+j];

    // Merge the temp arrays back into a[left...right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2){
        if(sub_left_array[i] <= sub_right_array[j]){
            a[k] = sub_left_array[i];
            i++;
        }else{
            a[k] = sub_right_array[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of sub_left_array if there any
    while (i < n1){
        a[k] = sub_left_array[i];
        i++;
        k++;
    }

    // Copy the remaining elements of sub_left_array if there any
    while (j < n2){
        a[k] = sub_right_array[j];
        j++;
        k++;
    }
}

// Mergesort function where a is the input array,
// left is the left index and r is the right index
// of the sub-array of a to be sorted
void mergeSort(int a[], int left, int right){
    if (left < right){
        int middle = left + (right-left) / 2;

        // Sort the first and second halves
        mergeSort(a, left, middle);
        mergeSort(a, middle+1, right);

        merge(a, left, middle, right);
    }
}

int main(){

    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int a_size = sizeof(a) / sizeof(a[0]);

    cout << "CURRENT ARRAY: " << endl;
    printArray(a, a_size);
    cout << "SORTED ARRAY: " << endl;
    mergeSort(a, 0, a_size - 1);
    printArray(a, a_size); 
    return 0;
}