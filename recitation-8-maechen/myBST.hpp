#pragma once
#include<iostream>
using namespace std; 

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    int count;
};

class BST {
    private:
        TreeNode* root;

        void _insertHelper(TreeNode*&, int, int);
        void _destructBST(TreeNode *T);
        TreeNode* _searchHelper(TreeNode* T, int);
        void _removeHelper(TreeNode*&, int);
        void _prettyPrintHelper(TreeNode*, string&);
        TreeNode* _searchMinHelper(TreeNode*);
        void _inOrderHelper(TreeNode*);
        void _preOrderHelper(TreeNode*);
        void _postOrderHelper(TreeNode*);
        void _hardDelete(TreeNode*&, int key);

    public:
        BST();
        ~BST();
        
        void insert(int key, int count);
        TreeNode* search(int key);
        void remove(int key);

        TreeNode* searchMin();
        void inOrder();
        void preOrder();
        void postOrder();
        string prettyPrint(); 
};
