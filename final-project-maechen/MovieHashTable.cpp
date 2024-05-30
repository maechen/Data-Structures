/**
 * MovieHashTable - implementing functions of the Hash Table class
 */

#include<iostream>
#include <vector>
#include "MovieHashTable.hpp"
using namespace std;

// Constructor for MovieHashTable with default size
MovieHashTable::MovieHashTable() {
    table_size = 2000; // capacity
    table = new MovieNode*[table_size];
    for(int i = 0; i < table_size; i++) table[i] = nullptr;
    n_collisions = 0;
}

// Constructor for MovieHashTable with given size
MovieHashTable::MovieHashTable(int s) {
    table_size = s;
    table = new MovieNode*[table_size];
    for(int i = 0; i < table_size; i++) table[i] = nullptr;
    n_collisions = 0;
}

// Destructor for MovieHashTable that deletes all nodes in the hash table
MovieHashTable::~MovieHashTable() {
    MovieNode* curr;
    MovieNode* temp;
    for(int i = 0; i < table_size; i++){ // iterate through hash table
        if(table[i] != nullptr){ // if the slot is not empty
            curr = table[i]; // current is at that index
            while(curr != nullptr){
                temp = curr->next; // store what is current's next, so we don't lose it when we delete current
                delete curr;
                curr = temp; // keep iterating through that linked list until nullptr
            }
            table[i] = nullptr; // setting the head of the linked list
        }
    }
    delete [] table;
}

/**
 * hash - returns an index in the hash table for a given movie title.
 *        students must use their identikey to come up with a creative hash function that minimizes collisions
 *        for the given IMDB-Movie database to ensure efficient insertion and retrieval of movie nodes.
 * 
 * @param title
 * @return int
 */
int MovieHashTable::hash(string title) {
    int hash = 0;
    string id = "mach";

    for (int i = 0; i < title.length(); i++) hash += title[i]; // adding ASCII decimal values
    for(int i = 0; i < id.length(); i++) hash += id[i];

    return hash % table_size;
}

/** 
 * insert - inserts a movie node into the hash table with the specified title
 * 
 * @param title, movie
 * @return void
 */
void MovieHashTable::insert(string title, MovieNode* movie) {
    int i = hash(title); // get index of where title should go after hashing

    if(table[i] != nullptr){ // if that index is not empty
        setCollisions(); // increment the number of collisions
        movie->next = table[i]; // putting movie node at the head of linked list chaining
        table[i] = movie; // sets head to inserted movie 
    }
    else table[i] = movie;
}

/**
 * search - searches for a node in the hash table with the specified title
 * 
 * @param title
 * @return MovieNode*
 */
MovieNode* MovieHashTable::search(string title) {
    int i = hash(title); // finds where the title was mapped to

    MovieNode* curr = table[i]; // begin at head
    while(curr != nullptr){ // iterate through linked list
        if(curr->title == title) return curr; // finds title
        curr = curr->next; // crawling
    }

    return nullptr; // if no matching title
}

/**
 * getCollisions - returns the number of collisions that have occurred during insertion into the hash table
 * 
 * @return int
 */
int MovieHashTable::getCollisions() {
    return n_collisions; // since private data member
}

/**
 * setCollisions - increments the number of collisions that have occurred during insertion into the hash table
 * 
 * @return void
 */
void MovieHashTable::setCollisions() {
    n_collisions++;
}