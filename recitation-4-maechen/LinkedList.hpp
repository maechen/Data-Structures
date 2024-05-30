#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>

struct Node{
      int key;
      Node *next;
};

class LinkedList
{
  private:
    Node *head;

  public:
    LinkedList(){
    	head = NULL;
    }
    void insert(Node *prev, int newKey);
    Node* searchList(int key);
    bool swapFirstAndLast();
    void printList();
};

#endif
