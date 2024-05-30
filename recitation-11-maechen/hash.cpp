// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);
    if(index < 0) return nullptr;

    //TODO: Search the list at that specific index and return the node if found
    node* curr = table[index];
    while(curr != nullptr){
        if(curr->key == key) return curr;
        curr = curr->next;
    }
    return nullptr;
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        // TODO :
        // Use the hash function on the key to get the index/slot,
        int index = hashFunction(key);

        // create a new node with the key and insert it in this slot's list
        node* nn = new node;
        nn->key = key;
        nn->next = table[index];
        table[index] = nn;
        return true;

     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }

}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        node* curr = table[i];
        while(curr != nullptr){
            cout << curr->key << " || ";
            curr = curr->next;
        }
        cout << endl;
        //TODO
    }
 }
