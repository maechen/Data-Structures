#include <iostream>
#include <cstdlib>
#include <iostream>
#include "MyStack.hpp"

using namespace std;

MyStack::MyStack()
{
	head = NULL;
}

MyStack::~MyStack()
{
	//TODO
	while(head != nullptr){
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

bool MyStack::isEmpty()
{
	//TODO
	if(head == nullptr) return true;
	return false;
}

void MyStack::push(int val)
{
	//TODO
	Node* nn = new Node;
	nn->val = val;
	nn->next = head;
	head = nn;
}

void MyStack::pop()
{   
	//TODO
	if(!isEmpty()){
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	else cout << "Stack empty, cannot pop an item!\n";
}

Node* MyStack::peek()
{
	//TODO
	if(!isEmpty()){
		return head;
	}
	else{
		cout << "Stack empty, cannot peek!\n";
		return NULL;
	}
}
