#include <iostream>
#include "myBST.hpp"
#define COUNT 10 

using namespace std;

BST::BST() {
    root = 0;
}

void BST::_destructBST(TreeNode *T) {
  if (T == 0) return;
    else {
        _destructBST(T->left);
        _destructBST(T->right);
        delete T;
    }
}

BST::~BST() {
    _destructBST(root);
}

void BST::_insertHelper(TreeNode* &T, int key, int count) {
    if (T == 0) {
        T = new TreeNode();
        T->key = key;
        T->left = 0;
        T->right = 0;
        T->count = count;
    } 
    else if (key < T->key) _insertHelper(T->left, key, count);
    else _insertHelper(T->right, key, count);
}

void BST::insert(int key, int count) {
    _insertHelper(root, key, count);
}


//------------------------------------------------SEARCH A KEY------------------------------------------
 /** This function will search the data in a tree
     We will call this function from search.
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

//---------------------------- TODO: DELETE NODE FROM THE TREE WHOSE COUNT IS EQUAL TO 1 --------------------------------------

/**
This function will delete the data from the tree rooted at T whose count is 1.
We will call this function from remove.
**/

void BST::_removeHelper(TreeNode* &T, int key) {
    if (T == 0) return;
    else if (key < T->key) _removeHelper(T->left, key);
    else if (key > T->key) _removeHelper(T->right, key);
    else {
        // TODO_1:
        // Wrap the below code in an IF-ELSE condition to check for counts!
        // When the count of the element is 1 only then delete the element from the tree else decrement the count by 1.
            if(T->count == 1){
                if (T->left == 0  && T->right == 0) {
                    delete T;
                    T = 0;
                }
                else if (T-> left == 0 && T->right != 0) {
                    TreeNode* child = T->right;
                    delete T;
                    T = child;
                }
                else if (T-> left != 0 && T->right == 0) {
                    TreeNode* child = T->left;
                    delete T;
                    T = child;
                }
                else {
                    //TODO_2:
                    // Need to get the minimum element from the right-most subtree and copy the key, and the count!
                    // (Hint: Check _hardDelete to get some code)
                    /*
                    //TODO_3:
                    Explain why do we need to use _hardDelete function here?
                    Write your answer here as a comment :)

                    ANSWER: we need to use _hardDelete here because you are deleting the minimum node, but the minium node might not have a count of 1, so the count would decrement, but the node will not be fully deleted.
                    */
                    TreeNode* temp = _searchMinHelper(T->right); // finds the smallest element in right subtree
                    T->key = temp->key;
                    T->count = temp->count;
                    _hardDelete(T->right, T->key);
                }
            }
            else T->count -= 1;
        
    }
}



void BST::remove(int key) {
    _removeHelper(root, key);
}


void BST::_hardDelete(TreeNode* &T, int key) {
    if (T == 0) return;
    else if (key < T->key) _hardDelete(T->left, key);
    else if (key > T->key) _hardDelete(T->right, key);
    else {
            if (T->left == 0  && T->right == 0) {
                delete T;
                T = 0;
            }
            else if (T-> left == 0 && T->right != 0) {
                TreeNode* child = T->right;
                delete T;
                T = child;
            }
            else if (T-> left != 0 && T->right == 0) {
                TreeNode* child = T->left;
                delete T;
                T = child;
            }
            else {
                TreeNode* temp = _searchMinHelper(T->right);
                T->key = temp->key;
                T->count = temp->count;
                _hardDelete(T->right, T->key);
            }
    }
}


//-----------------------------------------PRINT TREE (INORDER TRAVERSAL)--------------------------------

/** This function will traverse the tree in-order and print out the node elements.
printTree() function will call this function.
**/

void BST::_prettyPrintHelper(TreeNode* T, string& inorder)                                                                                                                                         
{          
    if(T)
    {
        _prettyPrintHelper(T->left,inorder);
        inorder += " " + to_string(T->key);
        _prettyPrintHelper(T->right,inorder);
    }                                                                                                                                                                                                                                                                                                                           
}                                                                                                                                                                                 
                                                                                                                                                                                  
string BST::prettyPrint()                                                                                                                                                           
{       
  string inorder = "";                                                                                                                                                                          
  _prettyPrintHelper(root,inorder); 
    return inorder;                                                                                                                                                        
}  


TreeNode* BST::_searchMinHelper(TreeNode* T) {
    if (T == 0) return 0;
    else if (T->left == 0) return T;
    else return _searchMinHelper(T->left);
}

TreeNode* BST::searchMin() {
    return _searchMinHelper(root);
}

void BST::_inOrderHelper(TreeNode* T) {
    if (T == 0) {
        return;
    }
    else {
        _inOrderHelper(T->left);
        cout << T->key << " ";
        _inOrderHelper(T->right);
    }
}

void BST::inOrder() {
    _inOrderHelper(root);
}

void BST::_preOrderHelper(TreeNode* T) {
    if (T == 0) {
        return;
    }
    else {
        cout << T->key << " ";
        _preOrderHelper(T->left);
        _preOrderHelper(T->right);
    }
}

void BST::preOrder() {
    _preOrderHelper(root);
}


void BST::_postOrderHelper(TreeNode* T) {
    if (T == 0) {
        return;
    }
    else {
        _postOrderHelper(T->left);
        _postOrderHelper(T->right);
         cout << T->key << " ";
    }
}

void BST::postOrder() {
    _postOrderHelper(root);
}
