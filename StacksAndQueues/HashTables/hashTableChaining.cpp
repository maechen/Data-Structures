#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

#include "hashTable.hpp"

#include <math.h>       /* modf */

using namespace std;

HashTable::HashTable() {
    size = 10;
    table = new HashNode *[size];

    for(int i = 0; i < size; i++) table[i] = nullptr;
}
  
HashTable::HashTable(int s) {
    size = s;
    table = new HashNode *[size];

    for(int i = 0; i < size; i++) table[i] = nullptr;
}

HashTable::~HashTable() {
    HashNode* curr;
    HashNode* prev;
    for( int i = 0; i < size; i++){
        curr = table[i];
        prev = nullptr;

        while(curr != nullptr){
            prev = curr;
            curr = curr->next;

            delete prev;
        }
    }

    delete table;
}

HashNode* HashTable::search(string key) {
    int k = hashCode(key, size);

    if(table[k] == nullptr) return nullptr;
    HashNode* curr = table[k];

    while(curr != nullptr){
        if(curr->key == key) return curr;
        curr = curr->next;
    }

    return nullptr;
}

void HashTable::insert(string key, string value) {
    HashNode* temp = search(key);
    if(temp != nullptr){
        cerr << "Key alr exisists" << endl;
        return;
    }
    else{
        HashNode * newNode = new HashNode(key, value);
        HashNode* head = table[hashCode(key, size)];
        newNode->next = head;
        table[hashCode(key, size)] = newNode;
    }
}

void HashTable::remove(string key) {
    return;
}

  
int HashTable::hashCode(string k, int table_size) {
    int hash = 0;

    for (int i = 0; i< k.length();  i++) 
      hash = hash + k[i];
    
    return hash % table_size;
  }

  /******************************************************************************
   *
   *  1. Given a key k (k is a string), generate the sum of the ASCII values
   *      for the characters in k.
   *  2. Multiply k by a constant A, where 0 < A < 1.
   *  3. Store the fractional part of kA.
   *  4. Multiply fractional part of kA by a constant, m, and take the floor of the result. 
   *
   *********************************************************************************/

  int HashTable::hashCode2(string k, int table_size) {
    int hash = 0;
    double A = 13.0/32.0;
    double hA;
    int m = 1024;
    
    for (int i = 0; i< k.length();  i++) 
      hash = hash + k[i];
    
    hA = hash * A;

    double fractpart, intpart;
    //get the fractional part of hash 
    fractpart = modf (hA , &intpart);

    fractpart = fractpart*m;
    hash = floor(fractpart);
    return hash % table_size;
  }


void HashTable::printHashTable() {
    for (int i = 0; i < size; i++) {
      if (table[i] != 0) {
	    cout << "[" << i << "] ";
	    HashNode* curr = table[i];
	    while (curr != 0) {
	    cout << "-> Key: " << curr->key << " (#" << hashCode(curr->key, size)<< ") Value: " << curr->value; 	  
	    curr = curr->next;
	    }
	    cout << endl;
      }
      else cout << "[" << i << "] -> Empty" << endl;
    }
}