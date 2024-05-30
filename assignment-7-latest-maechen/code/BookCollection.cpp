#include "BookCollection.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

BookCollection::BookCollection() {
    //TODO
    root = nullptr;
}

BookCollection::~BookCollection() {
    //TODO
    _destructor(root);
}

void BookCollection::_destructor(Book* B){
    if(B == nullptr) return;
    else{
        _destructor(B->left);
        _destructor(B->right);
        delete B;
    }
}

void BookCollection::removeBook(string bookName) {
    //TODO
    Book* found = _searchBookName(root, bookName);
    if(found == nullptr){
        cout << "Book not found!" << endl;
        return;
    }
    _remove(root, bookName);
}

void BookCollection::_remove(Book* &B, string bookName){
    if(B == nullptr) return;
    else if(bookName < B->bookName) _remove(B->left, bookName);
    else if(bookName > B->bookName) _remove(B->right, bookName);
    else{
        if(B->left == nullptr && B->right == nullptr){
            delete B;
            B = 0;
        }
        else if(B->left == 0 && B->right != 0){
            Book* temp = B->right;
            delete B;
            B = temp;
        }
        else if(B->left != 0 && B->right == 0){
            Book* temp = B->left;
            delete B;
            B = temp;
        }
        else{
            Book* min = _findMin(B->right);
            B->bookName = min->bookName;
            B->author = min->author;
            B->rating = min->rating;
            _remove(B->right, min->bookName);
        }
    }
}

Book* BookCollection::_findMin(Book* B){
    if(B == nullptr) return nullptr;
    else if(B->left == 0) return B; 
    else return _findMin(B->left);
}


void BookCollection::rotateLeftCollection(string bookName) {
    //TODO
    Book* x = _searchBookName(root, bookName);
    if(x == nullptr) return;
    Book* xp = _findParent(root, x); 
    Book* y = x->right;
    if(y == nullptr) return;
    x->right = y->left;
    y->left = x;
    if(xp != nullptr){
        if(xp->bookName > y->bookName) xp->left = y;
        else if(xp->bookName < y->bookName) xp->right = y;
    }
    if(x == root){
        root = y;
    }
}
Book* BookCollection::_searchBookName(Book* B, string bookName){
    if(B == nullptr) return nullptr;
    else{
        if(B->bookName == bookName) return B;
        else if(bookName < B->bookName) return _searchBookName(B->left, bookName);
        else return _searchBookName(B->right, bookName);
    }

}
Book* BookCollection::_findParent(Book* B, Book* child){
    if(child == B || B == nullptr) return nullptr;
    else if(B->left == child || B->right == child) return B;
    else if(B->bookName > child->bookName) return _findParent(B->left, child);
    else return _findParent(B->right, child);
}

string BookCollection::closestParent(string book1, string book2) {
    string path1[100];
    int size1 = 0;
    bool flag1 = true;
    _findPath(root, book1, path1, size1, flag1);
    if(flag1 == false) return "Error - wrong book name";

    string path2[100];
    int size2 = 0;
    bool flag2 = true;
    _findPath(root, book2, path2, size2, flag2);
    if(flag2 == false) return "Error - wrong book name";

    int i;
    for(i = 0; i < size1 && i < size2; i++){
        if(path1[i] != path2[i]) break;
    }
    return path2[i-1];
}
void BookCollection::_findPath(Book* B, string bookName, string arr[100], int& size, bool &flag){ // flag is did you find book or not
    if(B == nullptr) {
        cout << "Book not found!" << endl;
        flag = false;
        return;
    }
    if(B->bookName == bookName){
        arr[size] = B->bookName;
        size++;
        return;
    }
    if(B->bookName < bookName){
        arr[size] = B->bookName;
        size++;
        return _findPath(B->right, bookName, arr, size, flag);
    }
    else if(B->bookName > bookName){
        arr[size] = B->bookName;
        size++;
        return _findPath(B->left, bookName, arr, size, flag);
    }  
}
