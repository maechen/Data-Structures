/*************************************************************/
/*                BrowserHistory Definition                  */
/*************************************************************/
/* TODO: Implement the member functions of BrowserHistory    */
/*     This class uses a linked-list of WebPage structs to   */
/*     represent the schedule of web pages                   */
/*************************************************************/

#include "browserHistory.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
BrowserHistory::BrowserHistory() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool BrowserHistory::isEmpty() {
    /* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: prints the current list of pages 
 * in the given format.
 * [ID::1]-(URL::url1) -> ... -> NULL
 * @param none
 * @return none
 */
void BrowserHistory::displayHistory() {
    // TODO
    WebPage* temp = head;
    cout << "== CURRENT BROWSER HISTORY ==" << endl;
    if(temp != nullptr){
        while(temp != nullptr){
            cout << "[ID:: " << temp->id << "]-(URL::" << temp->url << ") -> ";
            temp = temp->next;
        }
    }
    else{
        cout << "Empty History" << endl;
    }
    cout << "NULL\n===" << endl;  
    return;
}

/*
 * Purpose: Add a new webpage to the browser history LL
 *   between the previous and the page that follows it in the list.
 * @param previousPage, the show that comes before the new page
 * @param newPage, the webpage to be added. 
 * @return none
 */
void BrowserHistory::addWebPage(WebPage* previousPage, WebPage* newPage) {
    // TODO
    // if(head == nullptr){
    //     head = newPage;
    //     cout << "adding: " << "[" << newPage->id << "]-" << newPage->url << " (HEAD)\n";
    // }
    if(previousPage == nullptr){
        newPage->next = head;
        head = newPage;
        cout << "adding: " << "[" << newPage->id << "]-" << newPage->url << " (HEAD)\n";
    }
    else{
        newPage->next = previousPage->next;
        previousPage->next = newPage;
        cout << "adding: " << "[" << newPage->id << "]-" << newPage->url << " (prev: " << "[" << previousPage->id << "])\n";
    }
}

/*
 * Purpose: populates the BrowserHistory with the predetermined pages
 * @param none
 * @return none
 */
void BrowserHistory::buildBrowserHistory() {
    // TODO
    WebPage* num = new WebPage {14, 0, "https://www.numberphile.com/", "", nullptr};
    WebPage* khan = new WebPage {13, 0, "https://www.khanacademy.org/", "", num};
    WebPage* brilliant = new WebPage {12, 0, "https://brilliant.org/", "", khan};
    WebPage* wiki = new WebPage {11, 0, "https://www.wikipedia.org/", "", brilliant};
    WebPage* cu = new WebPage {10, 0, "https://www.colorado.edu/", "", wiki};
    

    addWebPage(nullptr, cu);
    addWebPage(cu, wiki);
    addWebPage(wiki, brilliant);
    addWebPage(brilliant, khan);
    addWebPage(khan, num);
}


/*
 * Purpose: Search the BrowserHistory for the specified 
 * web page by ID and return a pointer to that node.
 * @param int id - ID of the web page to look for in LL.
 * @return pointer to node of page, or NULL if not found
 *
 */
WebPage* BrowserHistory::searchPageByID(int id) {
    // TODO
    if(head == nullptr) return nullptr;

    WebPage* temp = head;

    while(temp != nullptr){
        if(temp->id == id) return temp;
        temp = temp->next;
    }

    return nullptr;
}


/*
 * Purpose: Search the BrowserHistory for the specified 
 * web page by the URL and return a pointer to that node.
 * @param string url - url of the web page to look for in LL.
 * @return pointer to node of page, or NULL if not found
 *
 */
WebPage* BrowserHistory::searchPageByURL(std::string url) {
    // TODO
    if(head == nullptr) return nullptr;

    WebPage* temp = head;

    while(temp != nullptr){
        if(temp->url == url) return temp;
        temp = temp->next;
    }

    return nullptr;
}

/*
 * Purpose: Give an owner to a web page.
 * @param receiver - name of the show that is receiving the rating
 * @param rating - the rating that is being given to a show
 * @return none
 */
void BrowserHistory::addOwner(std::string url, string owner) {
    // TODO
    WebPage* temp = searchPageByURL(url);

    if(temp != nullptr){
        temp->owner = owner;
        cout << "The owner (" << temp->owner << ") has been added for the ID - "<< temp->id << "\n";
    }else{
        cout << "Page not found\n";
    }
}

void BrowserHistory::updateViews(string url) {
    // TODO
    WebPage* temp = head;
    while(temp != nullptr){
        if(searchPageByURL(url) == temp) temp->views++;
        temp = temp->next;
    }
}
