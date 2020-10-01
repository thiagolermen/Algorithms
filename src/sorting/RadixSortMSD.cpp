/*
    Radix Sort MSD String Sort
    Author: Thiago Sotoriva Lermen
    Complexity: O(n*w)
*/

#include <iostream>
#include <string>
#include <vector>




using namespace std;


void printVector(vector<string> words){
    int size = words.size();
    for (int i = 0 ; i < size ; i++){
        cout << words[i] << " ";
    }
    cout << endl;
}

void printArray(int a[], int size){
    cout << "[";
    for (int i=0;i<size;i++){
        cout << a[i] << " ";
    }
    cout << "]" << endl;
}

int charAt(string word, int d){
    if (d < word.size()){
        return toascii(word[d]);
    }else{
        return -1;
    }
}

void radixSortMSD(vector<string> &input, vector<string> &output, int lo, int hi, int d){
    if (hi <= lo)
        return;

    int R = 256;
    int count[R+2] = {0};


    for (int i = lo ; i <= hi ; i++){
        count[charAt(input[i], d) + 2]++;
    }

    for (int r = 0; r < R + 1 ; r++){
        count[r+1] += count[r];
    }

    for (int i = lo ; i <= hi ; i++){
        output[count[charAt(input[i], d)+1]++] = input[i];
    }

    for (int i = lo ; i <= hi ; i++){
        input[i] = output[i - lo];
    }

    for (int r = 0 ; r < R ; r++){
        radixSortMSD(input, output, lo + count[r], lo + count[r+1] - 1, d+1);
    }
}

int main(){

    vector<string> a = {"FORTUNE", "OF", "MY", "COUSIN", "AND", "MY", "THOUGHTS", "WERE", "TURNED", "INTO" "THE", "CHANNEL", "OF", "THEIR", "EARLIER", "BENT", "SIX", "YEARS", "PRESENT"};
    vector<string> b (a.size());

    radixSortMSD(a, b, 0, a.size()-1, 0);
    printVector(a);

    return 0;
}