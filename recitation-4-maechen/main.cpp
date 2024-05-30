#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main()
{
	/*******************************
	Mandatory: Silver Problem - Implement the insert and search functions
	********************************/

	LinkedList li;
	cout << "Adding nodes to List:"<<endl;
	// 2
	li.insert(NULL,2);
	li.printList();
	// -1->2
	li.insert(NULL, -1);
	li.printList();
	// -1->2->-7
	li.insert(li.searchList(2),-7);
	li.printList();
	// -1->2->-7->10
	li.insert(li.searchList(-7),10);
	li.printList();
	// -1->2->-7->10->3
	li.insert(li.searchList(10),3);
	li.printList();
	// -1->2->-7->10->3->5
	li.insert(li.searchList(3),5);
	li.printList();
	// -1->2->-7->10->3->5->-4
	li.insert(li.searchList(5),-4);
	li.printList();
	cout << endl;


	/*******************************
	Optional: Gold Problem - Implement the swapFirstAndLast function
	********************************/

    cout << "Swapping First and last nodes" << endl;

    if(!li.swapFirstAndLast()) {
        cout << "Swapping Failed!" << endl;
    }
    li.printList();

	// Test case when the number of nodes = 2
	LinkedList li2;
	cout << endl;
	cout << "Swapping a Linked List with 2 nodes"<<endl;
	// -1->2
	li2.insert(NULL,2);
	li2.insert(NULL, -1);
	li2.printList();

	cout << endl;
    cout << "Swapping First and last nodes" << endl;
    if(!li2.swapFirstAndLast()) {
        cout << "Swapping Failed!" << endl;
    }
	li2.printList();
    cout << endl;
}
