#include "array_double.hpp"
#include <sstream>

void parseFile(ifstream& input,string queryParams[], CovidCase *&cases, int &arrCapacity,  int &recordIdx, int &doublingCounter){
    string line; 
    while(getline(input,line)){
        stringstream sin(line);
        string name, varient, location, age;
        CovidCase newCase;
        getline(sin, name, ',');
        getline(sin, varient, ',');
        getline(sin, location, ',');
        getline(sin, age, ',');
        newCase.name = name;
        newCase.variant = varient;
        newCase.location = location;
        newCase.age = stoi(age);
        if(isCaseQueried(newCase, queryParams[0], queryParams[1], stoi(queryParams[2]), stoi(queryParams[3]))){
            addCase(cases, newCase, arrCapacity, recordIdx, doublingCounter);
            recordIdx++;
        }

    }
}

bool isCaseQueried(CovidCase covidCase, string queryLocation, string queryVariant, int startAge, int endAge) {
    if(covidCase.location == queryLocation && covidCase.variant == queryVariant){
        if(covidCase.age >= startAge && covidCase.age <= endAge) return true;
    }
    return false;
}

void resizeArr(CovidCase *&cases, int *arraySize) {
    CovidCase *newArr = new CovidCase[*arraySize * 2];
    for(int i = 0; i < *arraySize; i++) newArr[i] = cases[i];
    delete [] cases;
    cases = newArr;
    int newSize = *arraySize * 2;
    *arraySize = newSize;

}

void addCase(CovidCase *&cases, CovidCase covidCase, int &arrCapacity, int &recordIdx, int &doublingCounter) {
    if(arrCapacity - 1 < recordIdx){
        resizeArr(cases, &arrCapacity);
        doublingCounter++;
    }
    cases[recordIdx] = covidCase;
}

void sortCases(CovidCase* cases, int length) {
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - 1; j++){
            if(cases[j].age > cases[j+1].age){
                CovidCase temp = cases[j];
                cases[j] = cases[j+1];
                cases[j+1] = temp;
            }
            if(cases[j].age == cases[j+1].age){
                if(cases[j].name > cases[j+1].name){
                    CovidCase temp = cases[j];
                    cases[j] = cases[j+1];
                    cases[j+1] = temp;
                }
            }
        }
    }
}

void printQueriedCases(CovidCase* cases, int numOfRecords) {
    cout << "Queried Cases\n---------------------------------------" << endl;
    for(int i = 0; i < numOfRecords; i++) cout << cases[i].name << " " << cases[i].age << endl;
}