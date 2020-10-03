/*
    Bucket Sort Algorithm
    Author: Thiago Sotoriva Lermen
    Complexity: O(n)

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(float C[], int n){
    for(int i=0;i<n;i++)
        cout << "[" << C[i] << "] ";
    cout << endl;
}

void insertionSort(vector<float> a, int n){
    int i, key, j;
    for(j=1;j<n;j++){
        key = a[j];
        // insert the key in the ordered sequence C[1..j-1]
        i = j-1;
        while((i>=0) && (a[i]>key)){
            a[i+1] = a[i];
            i = i-1;
        }
        a[i+1] = key;
    }
}


void bucketSort(float a[], int n){

    // n empty buckets
    vector<float> b[n];

    // Put array elements in different buckets
    for (int i = 0 ; i < n ; i++){
        int bi = n * a[i];
        b[bi].push_back(a[i]);
    }

    // Sort individual buckets
    for (int i = 0 ; i < n ; i++){
        sort(b[i].begin(), b[i].end());
    }  
    
    // Concatenate all buckets into a[]
    int index = 0;
    for (int i = 0; i < n ; i++){
        for(int j = 0 ; j < b[i].size() ; j++){
            a[index++] = b[i][j];
        }
    }
}


int main(){
    float C[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int a_size = sizeof(C) / sizeof(C[0]);
    cout << "CURRENT ARRAY: " << endl;
    printArray(C, a_size);
    bucketSort(C, a_size);
    cout << "SORTED ARRAY: " << endl;
    printArray(C, a_size); 

    return 0;
}
