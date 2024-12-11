#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

int main() {
    const int MAX_ROWS = 60;  
    unordered_map<string, unordered_set<string>> graph; 
    unordered_map<string, unordered_set<string>> studentFriends; // To track each student's friends
    ifstream file("Friends Dataset.csv");

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string student1, student2;

            // Assume each row contains two students who are friends
            getline(ss, student1, ',');
            getline(ss, student2, ',');

            // Add the friendship to the graph
            studentFriends[student1].insert(student2);
            studentFriends[student2].insert(student1);
        }
        file.close();
    } else {
        cout << "Unable to open file!" << endl;
        return 1;
    }

    // Calculate the (common friends) between all pairs
    unordered_map<string, unordered_map<string, int>> edgeWeights;

   
    for (const auto& pair1 : studentFriends) {
        for (const auto& pair2 : studentFriends) {
            if (pair1.first != pair2.first) {
                // common friends between pair1.first and pair2.first
                unordered_set<string> commonFriends;
                for (const string& friend1 : pair1.second) {
                    if (pair2.second.find(friend1) != pair2.second.end()) {
                        commonFriends.insert(friend1);
                    }
                }
                int commonCount = commonFriends.size();
                if (commonCount > 0) {
                    edgeWeights[pair1.first][pair2.first] = commonCount;
                    edgeWeights[pair2.first][pair1.first] = commonCount;  // Symmetric edge
                }
            }
        }
    }

    // Display the graph with weighted edges
    cout << "Graph Representation (Weighted Edges based on common friends):" << endl;
    for (const auto& student : edgeWeights) {
        for (const auto& neighbor : student.second) {
            cout << student.first << " - " << neighbor.first << " with weight: " << neighbor.second << endl;
        }
    }

    return 0;
}
