#include "worldMap.hpp"
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

WorldMap::WorldMap() {}

void WorldMap::createWorldMap(string fileName)
{
    // TODO START

    ifstream fin(fileName);
    string line;
    
    getline(fin, line);
    istringstream iss(line);
    iss >> rows >> cols;

    worldMap = new int* [rows];
    for(int i = 0; i < rows; i++) worldMap[i] = new int [cols];

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            fin >> worldMap[i][j];
        }
    }

    // TODO END
}

void WorldMap::printWorldMap()
{
    // TODO START
    for(int i = 0; i < rows; i++){
        cout << "|";
        for(int j = 0; j < cols; j++){
            cout << " " << worldMap[i][j] << " |";
        }
        cout << endl;
    }
    // TODO END
}

void WorldMap::addRegion(int x, int y)
{
    // TODO START
    for(int i = 0; i < regions.size(); i++){
        if(regions[i]->x == x && regions[i]->y == y) return;
    }
    Region* newRegion = new Region;
    newRegion->x = x;
    newRegion->y = y;

    regions.push_back(newRegion);
    // TODO END
}

bool checkIfEdgeExists(Region *r, int x2, int y2)
{

    for (int i = 0; i < r->neighbors.size(); i++) {
        if (r->neighbors[i].region->x == x2 && r->neighbors[i].region->y == y2) {
            return true;
        }
    }

    return false;
}

void WorldMap::addEdgeBetweenRegions(int x1, int y1, int x2, int y2)
{
    // TODO START
    for (unsigned int i = 0; i < regions.size(); i++)
    {
        if (regions[i]->x == x1 && regions[i]->y == y1)
        {
            for (unsigned int j = 0; j < regions.size(); j++)
            {
                if (i != j && regions[j]->x == x2 && regions[j]->y == y2)
                {
                    if (!checkIfEdgeExists(regions[i], x2, y2))
                    {
                        NeighboringRegion av;
                        av.region = regions[j];
                        regions[i]->neighbors.push_back(av);
                        // another vertex for edge in other direction
                        NeighboringRegion av2;
                        av2.region = regions[i];
                        regions[j]->neighbors.push_back(av2);
                    }
                }
            }
        }
    }
    // TODO END
}

vector<vector<int>> WorldMap::findAdjacentLandRegions(int x, int y)
{
    // TODO START
    // identify the open paths that are adjacent to the vertex at x, y
    // fill adjArr array with the numbers of the adjacent vertices
    vector<vector<int>> neighbors;
    for (int i = x - 1; i <= x + 1; i++)
    {
        if (i < 0 || i >= this->rows)
        {
            continue;
        }
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (j < 0 || j >= this->cols)
            {
                continue;
            }
            // if there is an open path at this adjacent position, add to adjArray
            if (!(i == x && j == y) && worldMap[i][j] == 1)
            {
                neighbors.push_back({i, j});
            }
        }
    }
    return neighbors;
    // TODO END
}

void WorldMap::convertWorldMapToAdjacencyListGraph()
{
    // TODO START
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (worldMap[i][j] == 1){
                addRegion(i, j);
            }
        }
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
        {
            if (worldMap[i][j] == 1)
            {
                vector<vector<int>> land_neighbors = findAdjacentLandRegions(i, j);
                for(int k = 0; k < land_neighbors.size(); k++){
                    vector<int> land_neighbor = land_neighbors[k];
                    addEdgeBetweenRegions(i, j, land_neighbor[0], land_neighbor[1]);
                }
            }
        }
    }
    // TODO END
}

// helper function to check if v2 is a neighbor of verter v1
bool isNeighbor(int x1, int y1, int x2, int y2, const vector<Region *> regions)
{
    return false;
}

WorldMap::~WorldMap()
{
    // TODO START
    for(int i = 0; i < rows; i++){
        delete [] worldMap[i];
    }
    delete [] worldMap;

    for(int i = 0; i < regions.size(); i++) delete regions[i];

    // TODO END
}

void WorldMap::displayEdges()
{
    // TODO START
    for(int i = 0; i < regions.size(); i++){
        Region * r = regions[i];
        cout << "(" << r->x << "," << r->y << ") --> ";
        for(int j = 0; j < r->neighbors.size(); j++){
            cout << "(" << r->neighbors[j].region->x << "," << r->neighbors[j].region->y << ") ";
        }
        cout << endl;
    }

    // TODO END
}

// HELPER FOR findNumOfIslands
void findNumOfIslandsHelper(Region *r)
{
    r->visited = true;
    for(int i = 0; i < r->neighbors.size(); i++ )
    {
        if(r->neighbors[i].region->visited == false) findNumOfIslandsHelper(r->neighbors[i].region);
    }
    return;
}

int WorldMap::findNumOfIslands()
{
    // TODO START
    int count = 0;
    for(int i = 0; i < regions.size(); i++){
        Region* r = regions[i];
        if(r->visited == false){
            findNumOfIslandsHelper(r);
            count++;
        }

    }
    return count;
    // TODO END
}

vector<Region *> &WorldMap::getRegions()
{
    return regions;
}
