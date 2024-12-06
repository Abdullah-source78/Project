#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    const int maxRows = 60;  
    const int maxColumns = 7;  
    string data[maxRows][maxColumns]; 
    int row = 0;

    ifstream file("Friends Dataset.csv");

    if (file.is_open()) {
        string line;
        while (getline(file, line) && row < maxRows) {
            stringstream ss(line);
            string value;
            int col = 0;

            while (getline(ss, value, ',') && col < maxColumns) {
                data[row][col] = value;
                col++;
            }
            row++;
        }
        file.close();
    } else {
        cout << "Unable to open file!" << endl;
    }

   for (int i = 0; i < maxRows; i++) {
        for (int j = 0; j < maxColumns; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }

    
    cout << "Asymmetric friendship pairs:" << endl;
    for (int i = 0; i < row; i++) {
        bool symmetric = false;
        for (int j = 0; j < row; j++) {
            if (data[i][0] == data[j][1] && data[i][1] == data[j][0]) {
                symmetric = true; 
                break;
            }
        }
        if (!symmetric) {
            cout << "(" << data[i][0] << ", " << data[i][1] << ")" << endl;
        }
    }

   

    return 0;
}


