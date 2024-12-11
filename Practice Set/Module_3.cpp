#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
    const int MAX_ROWS = 60;
    unordered_map<string, unordered_set<string>> graph; 
    ifstream file("Friends Dataset.csv");

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string student1, student2;

   
            getline(ss, student1, ',');
            getline(ss, student2, ',');

          
            graph[student1].insert(student2);
            graph[student2].insert(student1);
        }
        file.close();
    } else {
        cout << "Unable to open file!" << endl;
        return 1;
    }

  
    string startStudent;
    cout << "Enter the name of the student: ";
    getline(cin, startStudent);

    if (graph.find(startStudent) == graph.end()) {
        cout << "Student not found in the dataset!" << endl;
        return 1;
    }


    unordered_map<string, int> distance;
    queue<string> q;

    q.push(startStudent);
    distance[startStudent] = 0;

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        for (const string& neighbor : graph[current]) {
            if (distance.find(neighbor) == distance.end()) { 
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }

    // Output results
    vector<string> oneHop, twoHop, threeHop;

    for (const auto& pair : distance) {
        if (pair.second == 1) {
            oneHop.push_back(pair.first);
        } else if (pair.second == 2) {
            twoHop.push_back(pair.first);
        } else if (pair.second == 3) {
            threeHop.push_back(pair.first);
        }
    }

    cout << "1-hop friends of " << startStudent << ": ";
    for (const string& friendName : oneHop) {
        cout << friendName << " ";
    }
    cout << endl;

    cout << "2-hop friends of " << startStudent << ": ";
    for (const string& friendName : twoHop) {
        cout << friendName << " ";
    }
    cout << endl;

    cout << "3-hop friends of " << startStudent << ": ";
    for (const string& friendName : threeHop) {
        cout << friendName << " ";
    }
    cout << endl;

    return 0;
}
