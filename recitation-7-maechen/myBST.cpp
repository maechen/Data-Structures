#include <iostream>
#include "myBST.hpp"
#define COUNT 10 

using namespace std;

BST::BST() {
    root = 0;
    // counter to keep track of the total number of the visited nodes
    counter = 0;
}

/**
 This function will destroy the subtree rooted at currNode.
 Think about in what order should you destroy?
 **/
//TODO:1
void BST::_destructBST(TreeNode *T){
 // check for empty tree
    if(T == nullptr) return;
    else{
        _destructBST(T->left);
        _destructBST(T->right);
        delete T;
    }
    //else traverse and delete
 }

BST::~BST() {
    _destructBST(root);
}

//---------------------------- INSERT NODE IN THE TREE --------------------------------------

/**
This function will add the data in the tree rooted at T.
We will call this function from insert.
**/

void BST::_insertHelper(TreeNode* &T, int key) {
    if (T == 0) {
        T = new TreeNode();
        T->key = key;
        T->left = 0;
        T->right = 0;
    } 
    else if (key < T->key) _insertHelper(T->left, key);
    else _insertHelper(T->right, key);
}

void BST::insert(int key) {
    _insertHelper(root, key);
    cout<<key<<" has been added"<<endl;
}

//------------------------------------------------SEARCH A KEY------------------------------------------
 /** This function will search the data in a tree
     We will call this function from searchKey.
 **/

TreeNode* BST::_searchHelper(TreeNode* T, int key) {
    if (T == 0) return 0;
    else if (key == T->key) return T;
    else if (key < T->key) return _searchHelper(T->left, key);
    else return _searchHelper(T->right, key);
}

TreeNode* BST::search(int key) {
    return _searchHelper(root, key);
}


//-----------------------------------------PRINT TREE (INORDER TRAVERSAL)--------------------------------

/** This function will traverse the tree in-order and print out the node elements.
printTree() function will call this function.
**/

void BST::_prettyPrintHelper(TreeNode* T)                                                                                                                                         
{          
    if(T)
    {
        _prettyPrintHelper(T->left);
        cout << " "<< T->key;
        _prettyPrintHelper(T->right);
    }                                                                                                                                                                                                                                                                                                                           
}                                                                                                                                                                                 
                                                                                                                                                                                  
void BST::prettyPrint()                                                                                                                                                           
{                                                                                                                                                                                 
  _prettyPrintHelper(root); 
  cout<<endl;                                                                                                                                                          
}  



//----------------Silver Problem ---------------------------

TreeNode*  BST::mthLargestHelper(TreeNode* T, int m)
{
    // base case
    if ( T == NULL || counter >= m) {
        return NULL;
    }
 
    // recur for the right subtree
    TreeNode* right = mthLargestHelper(T->right, m);
 
    // if m'th largest node is found in right return
    if(right != nullptr) return right;
    
 
    //for current node increment counter
    ++(counter);
    // if the root is m'th largest node
    if(counter == m) return T;
 
    // recur for the left subtree only if m'th largest node is not found
    // in the right subtree
    return mthLargestHelper(T->left, m);
    
}
 
// Function to find the m'th largest node in a BST
TreeNode*  BST::findMthLargest(int m)
{
    // counter to keep track of the total number of the visited nodes
    counter = 0;
    // recursively find the m'th largest node
    return mthLargestHelper(root, m);
}
//--------------------------------------------------------------------