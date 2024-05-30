#include <iostream>
#include <cstdlib>
#include "MessageDecoder.hpp"

using namespace std;
# define SIZE 50

MessageDecoder::MessageDecoder()
{
	my_queue = new MyQueue();
	my_stack = new MyStack();
}

MessageDecoder::~MessageDecoder()
{
    delete my_queue;
    delete my_stack;	
}

/*
    generate_operator_queue(string jumbled_str)

    Takes the jumbled string as the input parameter and stores all the allowed operators in my_queue
*/
void MessageDecoder::generate_operator_queue(std::string jumbled_str){
    //TODO
    for(int i = 0; i < jumbled_str.length(); i++){
        if(jumbled_str[i] == '+' || jumbled_str[i] == '-' || jumbled_str[i] == '*') my_queue->enqueue(jumbled_str[i]);
    }
}

/*
    generate_postfix(string jumbled_str)

    Takes the jumbled string as the input parameter and computes a postfix expression using the populated my_queue
    returns a postfix expression
*/
string MessageDecoder::generate_postfix(std::string jumbled_str){
    //TODO
	string postfix = "";
    int counter = 0;
    for(int i = 0; i < jumbled_str.length(); i++){
        if(counter == 2 && my_queue->isEmpty() == false){
            char c = my_queue->peek();
            postfix += c;
            my_queue->dequeue();
            counter = 0;
        }
        else if(jumbled_str[i] >= '0' && jumbled_str[i] <= '9'){
            postfix+=jumbled_str[i];
            counter++;
        }
    }
    int size = my_queue->queueSize();
    for(int i = 0; i < size; i++){
       char c = my_queue->peek();
       postfix += c;
       my_queue->dequeue();
    }
    return postfix;
}

/* 
    evaluate_postfix(string postfix) 

    Takes the post fix string as an input parameter and evaluates the post fix string. 
    returns an integer after evaluating the postfix expression
*/

int MessageDecoder::evaluate_postfix(std::string postfix){
    //TODO
    for(int i = 0; i < postfix.length(); i++){
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            string s = "";
            s += postfix[i];
            int val =  stoi(s);
            my_stack->push(val);
        }
        else{
            Node* na = my_stack->peek();
            int a = na->val;
            my_stack->pop();
            Node* nb = my_stack->peek();
            int b = nb->val;
            my_stack->pop();

            if(postfix[i] == '+'){
                int sum = a + b;
                my_stack->push(sum);
            }
            else if(postfix[i] == '-'){
                int dif = b - a;
                my_stack->push(dif);
            }
            else if(postfix[i] == '*'){
                int prod = a * b;
                my_stack->push(prod);
            }
        }
    }
    int result = -1;
    Node* res = my_stack->peek();
    result = res->val;
    my_stack->pop();

    return result;
}

//For Testing purposes only!
MyQueue* MessageDecoder::getQueue(){
    return my_queue;
}

//For Testing purposes only!
MyStack* MessageDecoder::getStack(){
    return my_stack;
}