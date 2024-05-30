#include "MyQueue.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

MyQueue::MyQueue(){
    queueFront = -1;
	queueEnd = -1;
}

bool MyQueue::isEmpty(){
	//TODO
	if(counter == 0) return true;
    return false;
}

bool MyQueue::isFull(){
	//TODO
	if(counter == SIZE) return true;
    return false;
}

void MyQueue::enqueue(char ch){
	//TODO
	if(!isFull()){
		queueEnd = (queueEnd+1)%SIZE;
		queue[queueEnd] = ch;
		counter++;
		if(queueFront == -1) queueFront = 0;
	}
	else cout << "Queue full, cannot add!\n";
}


void MyQueue::dequeue(){
	//TODO
	if(!isEmpty()){
		if(queueFront == queueEnd){ // or counter == 1
			queueFront = -1;
			queueEnd = -1;
			counter = 0; // or counter--;
			return;
		}
		queueFront = (queueFront+1)%SIZE;
		counter--;
	}
	else cout << "Queue empty, cannot dequeue!\n";
}

char MyQueue::peek(){
	//TODO
	if(!isEmpty()){
		return queue[queueFront];
	}
	else{
		cout << "Queue empty, cannot peek!\n";
		return '\0';
	} 
}

int MyQueue::queueSize(){
    //TODO
    return counter;
}
