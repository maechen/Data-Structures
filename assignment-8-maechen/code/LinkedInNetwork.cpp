#include "LinkedInNetwork.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void LinkedInNetwork::addProfessional(string name){
    //TODO
    bool found = false;

    for(int i = 0; i < professionals.size(); i++){
        if(professionals[i]->name == name){
            found = true;
            cout << name << " found." << endl;
        }
    }
    if(found == false){
        Professional *p = new Professional;
        p->name = name;
        professionals.push_back(p);
    }
}

void LinkedInNetwork::addConnection(string v1, string v2){
    //TODO
    for(int i = 0; i < professionals.size(); i++){
        if(professionals[i]->name == v1){
            for(int j = 0; j < professionals.size(); j++){
                if(professionals[j]->name == v2 && i != j){
                    neighbor n;
                    n.v = professionals[j];
                    professionals[i]->neighbors.push_back(n);
                    neighbor n2;
                    n2.v = professionals[i];
                    professionals[j]->neighbors.push_back(n2);
                }
            }
        }
    }
}

void LinkedInNetwork::displayConnections(){
    //TODO
    for(auto professional : professionals){
        cout << professional->name << " --> ";
        for(auto neighbor : professional->neighbors){
            cout << neighbor.v->name << " ";
        }
        cout << endl;  
    }
}

void LinkedInNetwork::breadthFirstTraverse(string sourceProfessional){
    //TODO
    Professional *src;

    for(int i = 0; i < professionals.size(); i++){
        if(professionals[i]->name == sourceProfessional) src = professionals[i];
    }

    src->visited = true;
    queue<Professional*> q;
    q.push(src);
    Professional *p;

    cout << "Starting Professional (root): " << sourceProfessional << "-> ";

    while(!q.empty()){
        p = q.front();
        q.pop();
        for(int i = 0; i < p->neighbors.size(); i++)
        {
            Professional* neighbor = p->neighbors[i].v;
            if(neighbor->visited == false){
                neighbor->visited = true;
                q.push(neighbor);
                neighbor->connectionOrder = p->connectionOrder + 1;

                cout << p->neighbors[i].v->name <<"("<< p->neighbors[i].v->connectionOrder <<")"<< " ";
            }
        }
    }
}

void bfs_helper(string source, vector<Professional*> &professionals) {
    Professional *src;

    for(int i = 0; i < professionals.size(); i++)
    {
        if(professionals[i]->name == source) src = professionals[i];
    }

    src->visited = true;
    queue<Professional*> q;
    q.push(src);
    Professional *p;

    while(!q.empty()){
        p = q.front();
        q.pop();
        for(int i = 0; i < p->neighbors.size(); i++)
        {
            Professional* neighbor = p->neighbors[i].v;
            if(neighbor->visited == false){
                neighbor->visited = true;
                q.push(neighbor);
                neighbor->connectionOrder = p->connectionOrder + 1;
            }
        }
    }
}

vector<string> LinkedInNetwork::suggestProfessionalsWithinKthOrder(string professionalName, int k){
    vector<string> professionalsWithinK;
    bfs_helper(professionalName, professionals);

    Professional* p;
    
    for(auto professional : professionals)
    {
        if(professional->name == professionalName){
            p = professional;
            break;
        }
    }

    if(p == nullptr) return professionalsWithinK;

    bfs_helper(professionalName, professionals);
    for (auto professional : professionals)
    {
        if (professional != p && professional->connectionOrder <= k && professional->connectionOrder > 0)
        {
            professionalsWithinK.push_back(professional->name);
        }
    }

    return professionalsWithinK;
}