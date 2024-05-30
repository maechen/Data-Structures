/**
 * DirectorSkipList - implementing functions of the Skip List class
 */

#include<iostream>
#include <vector>
#include "DirectorSkipList.hpp"
using namespace std;

// Constructor for DirectorSkipList with default capacity and levels
DirectorSkipList::DirectorSkipList() {
    capacity = 2000;
    levels = 10;
    head = new DirectorSLNode("", levels);
    for(int i = 0; i < levels; i++) head->next[i] = nullptr; 
}

// Constructor for DirectorSkipList with given capacity and levels
DirectorSkipList::DirectorSkipList(int _cap, int _levels) {
    capacity = _cap;
    levels = _levels;
    head = new DirectorSLNode("", levels);
    for(int i = 0; i < levels; i++) head->next[i] = nullptr; 
}

// Destructor for DirectorSkipList that deletes all nodes in the skip list (but not the MovieNodes, which are shared with other data structures)
DirectorSkipList::~DirectorSkipList() {
    DirectorSLNode* curr = head;
    DirectorSLNode* temp;
    while(curr != nullptr){
        temp = curr; // store current before we go to next node on regular linked list level
        curr = curr->next[0];
        delete temp;
    }
}

/**
 * insert - inserts a movie node into the skip list with the specified director
 * 
 * @param director, _movie
 * @return void
 */
void DirectorSkipList::insert(string director, MovieNode* _movie) {
    DirectorSLNode* curr = head; // start at head
    vector<DirectorSLNode*> prev(levels, nullptr); // will need to store previous nodes

    for(int i = levels - 1; i >= 0; i--){ // moves through levels vertically
        while(curr->next[i] != NULL && curr->next[i]->director < director){ // moves horizontally through linked lists
            curr = curr->next[i];
        }
        prev[i] = curr; // storing previous nodes as we move through 
    }
    curr = curr->next[0]; // comes down to regular linked list level

    if(curr != nullptr && curr->director == director){ // found director
        curr->addMovie(_movie);
        return;
    }

    // generating random levels for new director
    int rlevels = 1;
    while(rlevels < levels && rand() % 2 == 0){
        rlevels++;
    }

    DirectorSLNode* nd = new DirectorSLNode (director, rlevels); // create new director
    for(int i = rlevels - 1; i >= 0; i--){ // weaving into skip list, i.e. connecting previous nodes with new director and connecting new director with previous' nexts
        nd->next[i] = prev[i]->next[i];
        prev[i]->next[i] = nd;
    }
    nd->addMovie(_movie);
    size++; // increase the size since we added a director
}

/**
 *  search - searches for a node in the skip list with the specified director
 * 
 * @param director
 * @return DirectorSLNode*
 */
DirectorSLNode *DirectorSkipList::search(string director) {
    DirectorSLNode* curr = head; // start at head
    for(int i = levels - 1; i >= 0; i--){ // go from top to bottom, for each level go as far right as possible 
        // check if next node is null and not greater than vector searching for
        while(curr->next[i] != NULL && curr->next[i]->director < director){
            // travels to the right
            curr = curr->next[i];
        }
        // stops before the thing we need
    }
    curr = curr->next[0]; // one more step to right on regular linked list level
    if(curr != NULL && curr->director == director) return curr; // found the director
    else return nullptr;
}

/**
 * prettyPrint - prints nice visual of the skip list
 * 
 * @return void 
 */
void DirectorSkipList::prettyPrint() {
     for(int i = levels - 1; i >= 0; i--){ // starting from the top
        cout << "Level " << i << ": ";
        DirectorSLNode* curr = head->next[i];
        while(curr != nullptr){ // prints directors on each randomly generated height
            cout << "[ " << curr->director << " ] -> ";
            curr = curr->next[i];
        }  
    }
}
