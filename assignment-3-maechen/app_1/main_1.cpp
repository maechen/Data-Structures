#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "../code_1/browserHistory.hpp"

using namespace std;

void displayMenu();

int main(int argc, char* argv[]) {

    // DO NOT MODIFY THIS.
    if(argc>1) 
    {
        freopen(argv[1],"r",stdin);
    }
    // DO NOT MODIFY ABOVE.

    // TODO
    BrowserHistory b;
    int input = 0;

    do{
        displayMenu();
        cin >> input;
        if(input == 1){
            b.buildBrowserHistory();
            b.displayHistory();
        }
        else if(input == 2){
            b.displayHistory();
        }
        else if(input == 3){
            WebPage* add = new WebPage;
            string url, prev;
            int id;
            cout << "Enter the new web page's url:\n";
            cin >> url;
            WebPage* exists = b.searchPageByURL(url);
            if(exists == nullptr){
                add->url = url;
            }
            else{
                do{
                    cout << "INVALID" << url << "... Please enter a VALID page url!\n";
                    cin >> url;
                    exists = b.searchPageByURL(url);
                }while(exists != nullptr);
                add->url = url;
            }
            cout << "Enter the new web page's id:\n";
            cin >> id;
            exists = b.searchPageByID(id);
            if(exists == nullptr){
                add->id = id;
            }
            else{
                do{
                    cout << "This ID already exists. Try again.\n";
                    cout<< "Enter the new web page's id:\n";
                    cin >> id;
                    exists = b.searchPageByID(id);
                }while(exists != nullptr);
                add->id = id;
            }
            cout << "Enter the previous page's url (or First):\n";
            cin >> prev;
            if(prev == "First"){
                b.addWebPage(nullptr, add);
                b.updateViews(url);
            }
            else{
                WebPage* prev_page = b.searchPageByURL(prev);
                if(prev_page == nullptr){
                    do{
                        cout << "INVALID(previous page url)... Please enter a VALID previous page url!\n";
                        cout << "Enter the previous page's url (or First):\n";
                        cin >> prev;
                        prev_page = b.searchPageByURL(prev);
                    }while(prev_page == nullptr && prev != "First"); 
                } 
                if(prev == "First"){
                    b.addWebPage(nullptr, add);
                    b.updateViews(url);
                }
                else{
                    b.addWebPage(prev_page, add);
                    b.updateViews(url);
                }  
            }
        }
        else if(input == 4){
            string url, owner;
            cout << "Enter url of the web page to add the owner:\n";
            cin >> url;
            WebPage* temp = b.searchPageByURL(url);
            if(temp == nullptr){
                do{
                    cout << "Page not found. Try again.\n";
                    cout << "Enter url of the web page to add the owner:\n";
                    cin >> url;
                    temp = b.searchPageByURL(url);

                }while(temp == nullptr);
            }
            cout << "Enter the owner:";
            cin.ignore();
            getline(cin, owner);
            b.addOwner(url, owner);
        }
        else if(input == 5){
            string url;
            cout << "Enter url of the web page to check the view count: \n";
            cin >> url;
            WebPage* temp = b.searchPageByURL(url);
            if(temp == nullptr){
                do{
                    cout << "Page not found. Try again.\n";
                    cout << "Enter url of the web page to check the view count: \n";
                    cin >> url;
                    temp = b.searchPageByURL(url);
                }while(temp == nullptr);
            }
            
            cout << "View count for URL - " << temp->url << " is " << temp->views << endl;
            

        }
    }while(input > 0 && input < 6);

    if(input == 6){
        cout << "Quitting...Goodbye!\n";
    }

    return 0;
}




/************************************************
           Definitions for main_1.cpp
************************************************/
void displayMenu()
{
    // COMPLETE: You DO NOT need to edit this
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build history " << endl;
    cout << " 2. Display history " << endl;
    cout << " 3. Add web page " << endl;
    cout << " 4. Add owner" << endl;
    cout << " 5. View count for a web page" << endl;
    cout << " 6. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
