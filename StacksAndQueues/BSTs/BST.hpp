#pragma once
#include<iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;

    Node() {left = nullptr; right = nullptr;}
    Node(int k) {left = nullptr; right = nullptr; key = k;}
};

class BST {
    private:
        Node *root;

    public:
        BST();
        ~BST();
        void insert(int k);  // keep unique 
        Node* find(int k); // pointer to the node
        void search(int k);
        void remove(int k);
       
        void print();
        Node* _findMin(Node *node);

        void remove(Node* d_node); // remove the node pointed by d_node from the BST

        void inOrder();
        int size();

        void rotateLeft();
        void rotateRight();


    private:
        Node* find_prev(Node* d_node);
        void _print(Node* T, int space);
        void _destruct(Node* &T);
        void _insert(Node* &T, int k);
        Node* _search(Node* &T, int k);
        void _remove(Node* &T, int k);
        void _inOrder(Node* T);
        int _size(Node* T);
        void _rotateLeft(Node* &T);
        void _rotateRight(Node* &T);

};