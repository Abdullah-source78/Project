#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    const int MAX_ROWS = 60;  // Maximum number of rows
    const int MAX_COLS = 7;  // Maximum number of columns
    string data[MAX_ROWS][MAX_COLS]; // Static 2D array
    int row = 0;

    ifstream file("Friends Dataset.csv");

    if (file.is_open()) {
        string line;
        while (getline(file, line) && row < MAX_ROWS) {
            stringstream ss(line);
            string value;
            int col = 0;

            while (getline(ss, value, ',') && col < MAX_COLS) {
                data[row][col] = value;
                col++;
            }
            row++;
        }
        file.close();
    } else {
        cout << "Unable to open file!" << endl;
    }

    // Print the array content
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < MAX_COLS && !data[i][j].empty(); j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
