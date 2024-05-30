#include<iostream>
#include "BST.hpp"
using namespace std;

int main() {
    int A[] = {22,33,11,13,5};
    //int A[] = {2,3,11,13,16,25,32,33,47,56,96}; // imbalanced
    // int A[] = {96,56,47,33,32,25,16,13,11,3,2}; // imbalanced
    BST T;

    for (int i = 0; i < 5; i++) {
        cout << "inserting " << A[i] << endl;
        //getchar();
        T.insert(A[i]);
        //T.print();
    }    
    T.print();

    // if(T.find(33)) cout << "Found 33" << endl;
    // else cout << "Not Found 33" << endl;

    // if(T.find(105)) cout << "Found 105" << endl;
    // else cout << "Not Found 105" << endl;

    return 0;
}