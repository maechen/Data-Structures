#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../code/array_double.hpp"

using namespace std;

int main(int argc, char* argv[])
{
   
    if(argc != 6){
        cout << "Usage: ./run_app <inputfilename> <Query_Location> <Query_Variant> <Query_Start_Age> <Query_End_Age>" << endl;
        return -1;
    }
    ifstream fin(argv[1]);
    int capacity = 10;
    CovidCase *caseArr = new CovidCase[capacity];
    string params[4];
    int doubledCounter = 0;
    int caseIdx = 0;
    for(int i = 0; i < 4; i++) params[i] = argv[i+2];
    parseFile(fin, params, caseArr, capacity, caseIdx, doubledCounter);
    sortCases(caseArr, caseIdx);
    cout << "Array doubled: " << doubledCounter << endl;
    cout << "Total number of cases returned after the query: " << caseIdx << endl;
    printQueriedCases(caseArr, caseIdx);

    return 0;
}