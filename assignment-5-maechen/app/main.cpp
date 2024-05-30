#include<iostream>
#include <fstream>
#include<cmath>
#include<iomanip>
#include "../code/MessageDecoder.hpp"

using namespace std;


int main(int argc, char* argv[])
{
   if (argc < 2) {
        cout << "Usage: ./run_app <inputfilename>" << endl;
        return 0;
    } else {
        // TODO 
        ifstream fin(argv[1]);
        string line;
        if(fin.fail()){
          cout << "Error: Could not open file.\n";
        }
        else{
          while(getline(fin, line)){
            string jumbled = line;
            MessageDecoder decoder;
            decoder.generate_operator_queue(jumbled);
            string postfix = decoder.generate_postfix(jumbled);
            int answer = decoder.evaluate_postfix(postfix);
            cout << "Postfix Notation::" << postfix << endl;
            cout << "Final Answer::" << answer << endl;
          }
        }
        return 0;
    }
    
  return 0;
}