#include <SFML/Graphics.hpp>
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
    unordered_map<string, unordered_set<string>> graph; // Adjacency list
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
            graph[student1].insert(student2);
            graph[student2].insert(student1);
        }
        file.close();
    } else {
        cout << "Unable to open file!" << endl;
        return 1;
    }

    // Get input for the starting student
    string startStudent;
    cout << "Enter the name of the student: ";
    getline(cin, startStudent);

    if (graph.find(startStudent) == graph.end()) {
        cout << "Student not found in the dataset!" << endl;
        return 1;
    }

    // BFS to calculate hops
    unordered_map<string, int> distance; // To track the distance of each student
    queue<string> q;

    q.push(startStudent);
    distance[startStudent] = 0;

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        for (const string& neighbor : graph[current]) {
            if (distance.find(neighbor) == distance.end()) { // If not visited
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

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Friendship Hops");

    // Set up text display in the window
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/msttcorefonts/arial.ttf")) {
        cout << "Could not load font!" << endl;
        return 1;
    }

    // Prepare text for displaying
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);

    // Construct the text output string
    string result;
    result += "1-hop friends of " + startStudent + ": ";
    for (const string& friendName : oneHop) {
        result += friendName + " ";
    }
    result += "\n2-hop friends of " + startStudent + ": ";
    for (const string& friendName : twoHop) {
        result += friendName + " ";
    }
    result += "\n3-hop friends of " + startStudent + ": ";
    for (const string& friendName : threeHop) {
        result += friendName + " ";
    }

    // Set the string to the text object
    text.setString(result);

    // Set text position
    text.setPosition(10, 10);  // Start at the top left corner of the window

    // Main SFML window loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();  // Clear the window with black color
        window.draw(text);  // Draw the text
        window.display();  // Display the window contents
    }

    return 0;
}
