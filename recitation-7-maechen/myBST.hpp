#pragma once
#include<iostream>
using namespace std; 

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
};

class BST {
    private:
        TreeNode* root;
        int counter;

        void _insertHelper(TreeNode*&, int);
        void _destructBST(TreeNode *T);
        TreeNode* _searchHelper(TreeNode* T, int);
        void _prettyPrintHelper(TreeNode* T);
        TreeNode* mthLargestHelper(TreeNode* T, int k);

    public:
        BST();
        ~BST();
        
        void insert(int key);
        TreeNode* search(int key);

        TreeNode* findMthLargest(int k);
        void prettyPrint(); 
};
