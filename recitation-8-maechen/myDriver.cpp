#include <iostream>
#include "myBST.hpp"
using namespace std;
#define COUNT 10


#define EXPECTED_OUT_AFTER_ADD " 5 10 12 21 22 30 50 55 60 100"
#define EXPECTED_OUT_AFTER_DEL_50 " 5 10 12 21 22 30 55 60 100"
#define EXPECTED_OUT_AFTER_DEL_5 " 10 12 21 22 30 55 60 100"
#define EXPECTED_OUT_AFTER_DEL_100 " 10 12 21 22 30 55 60"


int main()
{
    int arr[10][2] = {{50,2},{12,2},{21,2},{10,2},{60,2},{30,2},{5,3},{100,1},{22,2},{55,3}};
    int len = 10;
    

    BST* T = new BST();
    for(int i=0;i<len;i++)
    {
        T->insert(arr[i][0],arr[i][1]);
    }
    cout<< "inorder traversal:"<<endl;
    string out = T->prettyPrint();
    cout<<out<<endl;
    cout << ((out == EXPECTED_OUT_AFTER_ADD) ? "Pass\n" : "Fail\n");
    
    T->remove(50);
    string outAfterDel50 = T->prettyPrint();
    cout << ((outAfterDel50 == EXPECTED_OUT_AFTER_ADD) ? "Pass\n" : "Fail\n");

    T->remove(50);
    outAfterDel50 = T->prettyPrint();
    cout << ((outAfterDel50 == EXPECTED_OUT_AFTER_DEL_50) ? "Pass\n" : "Fail\n");


    T->remove(5);
    string outAfterDel5 = T->prettyPrint();
    cout << ((outAfterDel5 == EXPECTED_OUT_AFTER_DEL_50) ? "Pass\n" : "Fail\n");

    T->remove(5);
    outAfterDel5 = T->prettyPrint();
    cout << ((outAfterDel5 == EXPECTED_OUT_AFTER_DEL_50) ? "Pass\n" : "Fail\n");

    T->remove(5);
    outAfterDel5 = T->prettyPrint();
    cout << ((outAfterDel5 == EXPECTED_OUT_AFTER_DEL_5) ? "Pass\n" : "Fail\n");



    T->remove(100);
    string outAfterDel100 = T->prettyPrint();
    cout << ((outAfterDel100 == EXPECTED_OUT_AFTER_DEL_100) ? "Pass\n" : "Fail\n");


  return 0;
}
