#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main()
 {
    const int maxrow = 250, maxcol = 7; //Hafsa Aslam
    ifstream record("Friends Dataset.csv");
    string data[maxrow][maxcol], word;
    int row = 0;
    while (getline(record, word) && row < maxrow)
     {
        stringstream ss(word);
        for (int col = 0; col < maxcol && getline(ss, data[row][col], ','); ++col);
        ++row;
    } //Hafsa Aslam

    for (int p = 0; p < row; ++p) //Muhammad Daniyal Idrees
    {
        bool duplicates = false;
        for (int h = 0; h < row && !duplicates; ++h)
             for (int k = 1; k < maxcol ; ++k)
            if (p != h && data[p][0] == data[h][k] && data[p][k] == data[h][0]) 
                duplicates = true;
        if (!duplicates) 
            cout << data[p][0] << ", " << data[p][k] << endl;
    }
    return 0;
 }    //Muhammad Daniyal Idrees
