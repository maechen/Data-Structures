#include <iostream>
#include "myBST.hpp"
using namespace std;
#define COUNT 10



int main()
{
    int arr[]= {50,12,21,10,60,30,5,100,22,55};
    int len = 10;
    

    BST* T = new BST();
    for(int i=0;i<len;i++)
    {
        T->insert(arr[i]);
    }
    cout<< "inorder traversal:"<<endl;
    T->prettyPrint();
    TreeNode* mth = T->findMthLargest(5);
    if(mth && mth->key == 30)
    {
        cout<< "Pass:"<<mth->key<<endl;
    }
    else{
        cout<<"Fail"<<endl;
    }
    
    
    mth = T->findMthLargest(10);
    if(mth && mth->key == 5)
    {
        cout<< "Pass:"<< mth->key<<endl;
    }
    else{
        cout<<"Fail"<<endl;
    }
    
    
    mth = T->findMthLargest(12);
    if(mth==NULL)
    {
        cout<< "Pass: Tree does not have 12 elements"<<endl;
    }
    else{
        cout<<"Fail"<<endl;
    }
  return 0;
}
