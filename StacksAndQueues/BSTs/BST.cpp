#include<iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10 

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    _destruct(root);
}
void BST::_destruct(Node* &T){
    if(T == NULL){
        return;
    }
    else{
        _destruct(T->left);
        _destruct(T->right);
        delete T;
    }
}
void BST::insert(int k){
    _insert(root, k);
}

void BST::_insert(Node* &T, int k){
    if(T = NULL){
        T = new Node(k);
        return;
    } 
    else{
        if( T->key == k){
            cout << "Duplicate" << endl;
            return;
        }
        else if(k < T->key) return _insert(T->left, k);
        else _insert(T->right, k);
    }

    // if(T == nullptr){
    //     T = new Node(k);
    //     return;
    // }
    // else{
    //     if(k < T->key) _add(T->left, k);
    //     else _add(T->right, k);
    // }
}
void BST::search(int k) {
    return _search(root, k);

    // Node* temp = root;
    // if(root == nullptr){
    //     root = new Node(k);
    //     return;
    // }
    // while(temp != nullptr){
    //     if(k == temp->key){
    //         cout << "Duplicate key" << endl;
    //         return;
    //     }
    //     else if(k < temp->key){
    //         if(temp->left == nullptr){
    //             Node* new_node = new Node(k);
    //             temp->left = new_node;
    //             return;
    //         }
    //         else temp = temp->left;
    //     }
    //     else{
    //         if(temp->right == nullptr){
    //             Node* new_node = new Node(k);
    //             temp->right = new_node;
    //             return;
    //         }
    //         else temp = temp->right;
    //     }
    // }
}  

Node* BST::_search(Node* T, int k) {
    if(T == NULL) return nullptr;
    else{
        if(T->key == k) return T;
        else if(k < T->key) return _search(T->left, k);
        else return _search(T->right, k);
    }

//    Node* temp = root;
//    while(temp != nullptr){
//     if(temp->key == k) return temp;
//     else if (k < temp->key) temp = temp->left;
//     else temp = temp->right;
//    }

//     return temp;
} 

void BST:: _remove(Node* &T, int k){
        if(T == NULL) return;
        else{
            if(k < T->key) return _remove(T->left, k);
            else if(k > T->key) return _remove(T->right, k);
            else{
                // this node is going to be deleted
                if(T->left == NULL && T->right == NULL){
                    delete T;
                    T = nullptr;
                    return;
                }
                else if(T->left != NULL && T->right == NULL){
                    Node* newT = T->left;
                    delete T;
                    T = newT;
                    return;
                }
                else if(T->left == NULL && T->right != NULL){
                    Node* newT = T->right;
                    delete T;
                    T = newT;
                    return;
                }
                else{
                    Node* minRight = _findMin(T->right);
                    T->key = minRight->key;
                    return _remove(T->right, minRight->key); 
                }
            }
        }
}

void BST::remove(int k) {
   _remove(root, k); 
} 

Node* BST::_findMin(Node* T){
    if(T == nullptr) return NULL;
    else{
        if (T->left == NULL) return T;
        else return _findMin(T->left);
    }
}

void BST::_print(Node* T, int space)
{
    // Base case 
    if (T == 0) return;
    // Increase distance between levels
    space += COUNT;
    
    // Process right child first 
    _print(T->right, space); 
    // Print current node after space                                                                                                                                               
    printf("\n");                                                                                                                                                                   
    for (int i = COUNT; i < space; i++)                                                                                                                                             
        printf(" ");                                                                                                                                                                  
     printf("%d\n", T->key);                                                                                                                                                    

    // Process left child                                                                                                                                                           
    _print(T->left, space);                                                                                                                                                    
}                                                                                                                                                                                 
                                                                                                                                                                                  
void BST::print()                                                                                                                                                           
{                                                                                                                                                                                 
  _print(root, 1);                                                                                                                                                           
} 


Node* BST::find_prev(Node* d_node) {
    Node* prev = root;
    Node* curr = root;

    while(curr != nullptr){
        if(curr == d_node){
            return prev;
        }
        else if (d_node->key < curr->key){
            prev = curr;
            curr = curr->left;
        }
        else{
            prev = curr;
            curr = curr->right;
        }
    }
    return nullptr;
}

void BST::inOrder(){
    _inOrder(root);
}

void BST::_inOrder(Node* T){
    if(T == nullptr){
        return
    }
    else{
        _inOrder(T->left);
        cout << T->key << " ";
        _inOrder(T->right);
    } 
}

void BST::preOrder(){
    _preOrder(root);
}

void BST::_preOrder(Node* T){
    if(T == nullptr){
        return
    }
    else{
        _preOrder(T->left);
        cout << T->key << " ";
        _preOrder(T->right);
    } 
}

int BST::size(){
    _size(root);
}

int BST:: _size(Node* T){
    if(T == NULL return 0;
    else{
        return 1 += _size(T->left) + size(T->right);
    })
}

void BST::rotateLeft(){
    _rotateLeft(root);
}

void BST::rotateRight(){
    _rotateRight(root);
}

void BST::_rotateLeft(Node* &T){
    if(T == nullptr) return;
    else{
        if(T->right == nullptr) return;
        else{
            Node* rightT = T->right;
            Node* rightLeftT = T->right->left;

            rightT->left = T;
            T->right = rightLeftT;
            T = rightT;
        }
    }
}
        
void BST::_rotateRight(Node* &T){
    if(T == nullptr) return;
    else{
        if(T->left == nullptr) return;
        else{
            Node* leftT = T->left;
            Node* leftRightT = T->left->right;

            leftT->right = T;
            T->left = leftRightT;
            T = leftT;
        }
    }
}

// Node* BST::findMin(Node *node) {
//     Node* temp = root;
//     while(temp != nullptr){
//         if(temp->left == nullptr) return temp;
//         else temp = temp->left;
//     }
//     return nullptr;
// }