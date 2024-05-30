#include <iostream>
#include <fstream>
#include "../code/fundamentals.hpp"
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) 
{
    // TODO
    if(argc >= 2)
    {
        ifstream fin(argv[1]);
        if(fin.is_open())
        {
            string line;
            int index = 0;
            stockInfo stocks[6];
            ofstream MyFile(argv[2]);
            while(getline(fin, line))
            {
                stringstream sin(line);
                string company_name, price1, price2, price3, price4, price5;
                getline(sin, company_name, ',');
                getline(sin, price1, ',');
                getline(sin, price2, ',');
                getline(sin, price3, ',');
                getline(sin, price4, ',');
                getline(sin, price5, ',');
                double stock_prices_arr[5];
                stock_prices_arr[0] = stod(price1);
                stock_prices_arr[1] = stod(price2);
                stock_prices_arr[2] = stod(price3);
                stock_prices_arr[3] = stod(price4);
                stock_prices_arr[4] = stod(price5);
                insertStockInfo(stocks, company_name, stock_prices_arr, index);
                displaySortedStocks(stocks[index], MyFile);
                index++;
            }
            fin.close();
            MyFile.close();
            ifstream OutputFile(argv[2]);
            string lines;
            while(getline(OutputFile, lines))
            {
                cout << lines << endl;
            }
            OutputFile.close();
        }
        else
        {
            cout << "File not found." << endl;
            return -1;
        }
    }
    else
    {
        cout << "No input file provided." << endl;
        return -1;
    }

    return 0;
}