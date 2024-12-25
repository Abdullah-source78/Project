
// module 3 without vectors and unmapped functions/////////////////////////////////////////////



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

const int MAX_STUDENTS = 60; 
int main() {
    string students[MAX_STUDENTS];     
    bool friendship[MAX_STUDENTS][MAX_STUDENTS] = {false}; // 2D Array
    int studentCount = 0;

    ifstream file("Friends Dataset.csv");

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string student1, student2;

            // Read two students who are friends
            getline(ss, student1, ',');
            getline(ss, student2, ',');

            // Find or add student1
            int index1 = -1, index2 = -1;
            for (int i = 0; i < studentCount; i++) {
                if (students[i] == student1) {
                    index1 = i;
                }
                if (students[i] == student2) {
                    index2 = i;
                }
            }

            if (index1 == -1) {
                index1 = studentCount++;
                students[index1] = student1;
            }

            if (index2 == -1) {
                index2 = studentCount++;
                students[index2] = student2;
            }

            // Update the 2D Array
            friendship[index1][index2] = true;
            friendship[index2][index1] = true;
        }
        file.close();
    } else {
        cout << "Unable to open file!" << endl;
        return 1;
    }
////////////////////////////////////////////////////////
    // Get input for the starting student
    string startStudent;
    cout << "Enter the name of the student: ";
    getline(cin, startStudent);

    int startIndex = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i] == startStudent) {
            startIndex = i;
            break;
        }
    }

    if (startIndex == -1) {
        cout << "Student not found in the dataset!" << endl;
        return 1;
    }

    // BFS to calculate hops
    int distances[MAX_STUDENTS];
    for (int i = 0; i < studentCount; i++) {
        distances[i] = -1; // -1 means unvisited
    }

    queue<int> q;
    q.push(startIndex);
    distances[startIndex] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < studentCount; i++) {
            if (friendship[current][i] && distances[i] == -1) { // Not visited
                distances[i] = distances[current] + 1;
                q.push(i);
            }
        }
    }
///////////////////////////////////////
    // Output results
    cout << "1-hop friends of " << startStudent << ": ";
    for (int i = 0; i < studentCount; i++) {
        if (distances[i] == 1) {
            cout << students[i] << " ";
        }
    }
    cout << endl;

    cout << "2-hop friends of " << startStudent << ": ";
    for (int i = 0; i < studentCount; i++) {
        if (distances[i] == 2) {
            cout << students[i] << " ";
        }
    }
    cout << endl;

    cout << "3-hop friends of " << startStudent << ": ";
    for (int i = 0; i < studentCount; i++) {
        if (distances[i] == 3) {
            cout << students[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
