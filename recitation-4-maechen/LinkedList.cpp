#include "LinkedList.hpp"

using namespace std;

/*******************************
Mandatory: Silver Problem - Implement the insert and search functions
********************************/

// Search for a specified key and return a pointer to that node
//MANDATORY_TODO: complete this function
// Given the key this function will find the node where the key is present
// If found it will return the node, else NULL
Node* LinkedList::searchList(int key) {

    Node* ptr = NULL;
    Node* temp = head;

    while(temp != nullptr){
      if(temp->key == key) return temp;
      temp = temp->next;
    }

    return ptr;
}


// Add a new node to the list
//MANDATORY_TODO: complete this function
// This function will add a node with newKey after the prev node in the linked list
// if prev is null insertion is to be made at head
void LinkedList::insert(Node* prev, int newKey){
  Node* temp = new Node();
  temp->key = newKey;
  temp->next = nullptr;
  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = temp;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
    temp->next = head;
    head = temp;
  }
  //general insertion
  else{
    temp->next = prev->next;
    prev->next = temp;
  }
}


/*******************************
Optional: Gold Problem - Implement the swapFirstAndLast function
********************************/

// Swap the first and last nodes (don't just swap the values). Swap the Nodes
bool LinkedList::swapFirstAndLast()
{
    bool isSwapped = false;
    Node* first = head;
    Node* prev_last = new Node();
    Node* temp = head;
    while(temp->next != nullptr){
      prev_last = temp;
      temp = temp->next;
    }
    head = temp;
    temp->next = first->next;
    prev_last->next = first;
    first->next = nullptr;
    
    isSwapped = true;

    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;
  int count = 0;

  while(temp->next != NULL & count < 21){
    cout<< temp->key <<" -> ";
    temp = temp->next;
    count++;
  }

  cout<<temp->key<<endl;
}
