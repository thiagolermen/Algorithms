#include <iostream>

using namespace std;



int main(){

    int rows;
    int cols;
    cout << "Let A mxn a matrix and m and n are, respectively, the number of rows and cols of A" << endl;
    cout << "Enter the number of rows: " ;
    cin >> rows;
    cout << "Enter the number of cols: ";
    cin >> cols;    
    int A[rows][cols];

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << "Row " << i+1 << ", " << "Col " << j+1 << ": ";
            cin >> A[i][j];
        }
    }

    int AT[cols][rows];
     
     for(int j=0;j<cols;j++){
        for(int i=0;i<rows;i++){
            AT[j][i] = A[i][j];
        }
    }
    cout << "Transpose of matrix A: " << endl;
    for(int i=0;i<cols;i++){
        for(int j=0;j<rows;j++){
            cout << "|" << AT[i][j];
        }
        cout << "|" << endl;
    }
}