/*
    Binary Search Algorithm (recursive)
    Author: Thiago Sotoriva Lermen
    Complexity: 0(log n)

    Definition by Wikipedia:
    In computer science, binary search, also known as half-interval search, 
    logarithmic search, or binary chop,[3] is a search algorithm that finds 
    the position of a target value within a sorted array. Binary search compares 
    the target value to the middle element of the array. If they are not equal, 
    the half in which the target cannot lie is eliminated and the search continues 
    on the remaining half, again taking the middle element to compare to the target 
    value, and repeating this until the target value is found. If the search ends 
    with the remaining half being empty, the target is not in the array. 
    Font: https://en.wikipedia.org/wiki/Binary_search_algorithm
*/
#include <iostream>

using namespace std;

// A recursive binary search function
// Returns location of x in given array
// C[l..r] if present, otherwise -1
int binarySearch(int C[], int l, int r, int x){
    if(r >= 1){
        int mid = l + (r-1)/2;

        //If the element is present at the middle
        if(C[mid] ==  x)
            return mid;

        // If the element is smaller than mid
        // the element can be present in the left subarray
        if(C[mid] > x)
            return binarySearch(C, l, mid-1, x);

        // Else the element is present in tge right subarray
        return binarySearch(C, mid+1, r, x);
    }

    // If the element is nor present in the array
    return -1;
}

void printArray(int C[], int n){
    for(int i=0;i<n;i++)
        cout << "[" << C[i] << "] ";
    cout << endl;
}

int main(){
    int x;
    int C[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(C)/sizeof(C[0]);
    cout << "CURRENT ARRAY: " << endl;
    printArray(C, n);
    cout << "ENTER THE ELEMENT: ";
    cin >> x;

    int i = binarySearch(C, 0, n, x);
    if(i != -1){
        cout << "ELEMENT IS PRESENT AT THE INDEX: " << i << endl;
    }else{
        cout << "ELEMENT IS NOT PRESENT IN THE ARRAY" << endl;
    }

}