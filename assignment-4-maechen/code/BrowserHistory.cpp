
#include "BrowserHistory.hpp"
#include <iostream>
using namespace std;

BrowserHistory::BrowserHistory()
{
    // No changes needed
}

BrowserHistory::~BrowserHistory()
{
    // No changes needed
}

/*
 * Purpose: Has to detect if a defect is present in the linkedlist pointed by head
 * @param none
 * @return integer length of defect if one exists. If defect not present return -1
 */
int BrowserHistory::findDefectLength(){

    // TODO START =============================================
    WebPage* fast = head;
    WebPage* slow = head;
    int len = 1;

    if(head == nullptr || head->next == nullptr) return -1;

    while(fast->next != nullptr && fast != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            slow = slow->next;
            while(slow != fast){
                slow = slow->next;
                len++;
            }
            return len;
        }
    }
    return -1;
    // TODO END ==================================================
}

/*
 * Purpose: Has to remove all the WebPage nodes from [start, end] inclusive.
 * Has to print appropriate messages on cout like below if the linkedlist is empty
 * or if the values of start/ end are improper
 * follow the same order for couts in the writeup - check empty list first, then check wrong start/end values
 * @param integers start and end (1 based indexing not 0 based)
 * @return none
 */
void BrowserHistory::removeWebPages(int start, int end){

    // TODO START ===================================================
    if(head == nullptr){
        cout << "Browsing history is Empty" << endl;
        return;
    }
    WebPage* temp = head;
    int len = 0;
    while(temp != nullptr){
        ++len;
        temp = temp->next;
    }
    if(start < 1 || end > len || start > end){
        cout << "Invalid start or end values" << endl;
        return;
    }
    else if(start == 1){ // deleting from head
        int count = 0;
        while(count != (end-start+1)){
            WebPage* gone = head;
            head = head->next;
            delete gone;
            count++;
        }
        return;
    }
    else if(start == end){ // deleting just one index
        int count = 1;
        WebPage* prev = head;
        WebPage* cur = head;
        while(cur->next != nullptr && count != start){
            prev = cur;
            cur = cur->next;
            count++;
        }
        WebPage* gone = cur;
        prev->next = cur->next;
        delete gone;
    }
    else{ // deleting anywhere
        int count = 1;
        int startIndex = 1;
        int endIndex = 1;
        WebPage* prev = head;
        WebPage* cur = head;
        WebPage* last = head;
        while(cur != nullptr && startIndex != start){
            prev = cur;
            cur = cur->next;
            startIndex++;
        }
        while(last != nullptr && endIndex != end){
            last = last->next;
            endIndex++;
        }
        while(count != (end-start+1)){
            WebPage* gone = cur;
            cur = cur->next;
            delete gone;
            count++;
        }
        prev->next = last->next;
        return;
    }
    // TODO END ===================================================
}


/*
 * Purpose: Interweave the webpages alternatively into a new linkedlist 
 * starting with the first webpage in the list one
 * Assign the head of the new interweaved list to the head of this BrowserHistory
 * DO NOT create new nodes and copy the data, just use the same nodes from one and two and change pointers
 * If one of them runs out of length append the remaining of the other one at end
 * @param two linkedlist heads one and two
 * @return none
 */
void BrowserHistory::mergeTwoHistories(WebPage *headOne, WebPage * headTwo){

    // TODO START =============================================
    
    if(headOne != nullptr && headTwo == nullptr) head = headOne;
    else if(headOne == nullptr && headTwo != nullptr) head = headTwo;
    else{
        WebPage* curr1 = headOne;
        WebPage* curr2 = headTwo;
        WebPage* temp1;
        WebPage* temp2;

        while(curr1 != nullptr && curr2 != nullptr){
            temp1 = curr1->next;
            temp2 = curr2->next;
            curr1->next = curr2;
            curr2->next = temp1;
            curr1 = temp1;
            curr2 = temp2;
        }
        head = headOne;
    }

    // TODO END ==================================================
}
