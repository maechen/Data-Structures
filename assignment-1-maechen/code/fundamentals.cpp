#include "fundamentals.hpp"

void insertStockInfo(stockInfo stocks[], string company_name, double stock_prices_arr[], int index) {
    // TODO
    double total = 0;
    for(int i = 0; i < 5; i++)
    {
        total += stock_prices_arr[i];
    }
    double average = total / 5;

    stockInfo newStock;
    newStock.company_name = company_name;
    for(int i = 0; i < 5; i++)
    {
        newStock.stock_prices_arr[i] = stock_prices_arr[i];
    }
    newStock.average = average;

    stocks[index] = newStock;

    return;
}

void displaySortedStocks(stockInfo stock, ofstream& file){
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(stock.stock_prices_arr[j] > stock.stock_prices_arr[j + 1])
            {
                double temp = stock.stock_prices_arr[j];
                stock.stock_prices_arr[j] = stock.stock_prices_arr[j + 1];
                stock.stock_prices_arr[j + 1] = temp;
            }
        }
    }

    file << stock.company_name << "," << stock.average << ",";
    for(int i = 0; i < 4; i++){
        file << stock.stock_prices_arr[i] << ",";
    }
    file << stock.stock_prices_arr[4] << endl;
    
    return;
}