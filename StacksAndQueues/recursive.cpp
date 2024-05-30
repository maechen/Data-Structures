#include<iostream>

using namespace std;

int Fib(int n)
{
    if(n == 0) return 0; // base case
    if(n == 1) return 1; // base case
    else return Fib(n-1) + Fib(n-2);
}

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    
    for(int i = 0; i < n; i++){
        cout << "F(" << i << ") = " << Fib(i) << endl;
    }

    return 0;
}