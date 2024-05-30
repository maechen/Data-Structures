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
    _destructor(B->left);
    _destructor(B->right);
    delete B;
}

void BookCollection::addBook(string bookName, string author, double rating) {
    //TODO
    _addBook(root, bookName, author, rating);
}

void BookCollection::_addBook(Book *&B, string bookName, string author, double rating){
    if(B == nullptr) B = new Book(bookName, author, rating);
    else if (bookName < B->bookName) _addBook(B->left, bookName, author, rating);
    else _addBook(B->right, bookName, author, rating);
}

void BookCollection::showBookCollection() {
    //TODO
    if(root == nullptr) cout << "Collection is empty." << endl;
    else _inOrder(root);
}

void BookCollection::_inOrder(Book* B){
    if(B == nullptr) return;
    _inOrder(B->left);
    cout << "BOOK: " << B->bookName << " BY: " << B->author << " RATING: " << B->rating << endl;
    _inOrder(B->right);
}

void BookCollection::showBook(string bookName) {
    //TODO
    Book* found = _searchBookName(root, bookName);
    if (found == nullptr) cout << "Book not found." << endl;
    else{
        cout << "Book:" << endl;
        cout << "==================" << endl;
        cout << "Name :" << found->bookName << endl;
        cout << "Author :" << found->author << endl;
        cout << "Rating :" << found->rating << endl;
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

void BookCollection::showBooksByAuthor(string author) {
    //TODO
    cout << "Books By: " << author << endl;
    _searchAuthor(root, author);
}

void BookCollection::_searchAuthor(Book* B, string author){
    if(B == nullptr) return;

    _searchAuthor(B->left, author);

    if(B->author == author){
        cout << B->bookName << " RATING: " << B->rating << endl;
    } 

    _searchAuthor(B->right, author);
}

void BookCollection::showHighestRatedBooks() {
    //TODO
    Book* highest = _highest(root);
    if(highest != nullptr){
        cout << "Highest Rating: " << highest->rating << endl;
        _searchRating(root, highest->rating);
    } 
}

Book* BookCollection::_highest(Book *B){
    Book* highest = B;
    Book* highestL = nullptr;
    Book* highestR = nullptr;
    
    if (B == nullptr){
        cout << "Collection is empty." << endl;
        return nullptr;
    }
    if(B->left != nullptr){
        highestL = _highest(B->left);
        if(highestL->rating > highest->rating) highest = highestL;
    }
    if(B->right != nullptr){
        highestR = _highest(B->right);
        if(highestR->rating > highest->rating) highest = highestR;
    }

    return highest;
    
}

void BookCollection::_searchRating(Book* B, double rating){
    if(B == nullptr) return;

    _searchRating(B->left, rating);

    if(B->rating == rating){
        cout << B->bookName << " BY: " << B->author << endl;
    } 

    _searchRating(B->right, rating);
}

int BookCollection::getHeightOfBookCollection() {
    //TODO
    return _height(root);
}

int BookCollection::_height(Book* B){
    if(B == nullptr) return 0;
    else{
        int left = _height(B->left);
        int right = _height(B->right);

        if(left > right) return (left + 1);
        else return (right + 1);
    }
}
