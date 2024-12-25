#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 190;
const int MAX_FRIENDS = 6;

// HAFSA ASLAM 
// ye data ko array mai load karne ke liye
void loadData(string students[MAX_STUDENTS][MAX_FRIENDS], int& numStudents, const string& filename) {
    ifstream file("Friends Dataset.csv");
    if (!file.is_open()) {
        cout<< "Unable to open file." <<endl;
        return;
    }

    string line;
    numStudents = 0;
    while (getline(file, line) && numStudents < MAX_STUDENTS) 
    {
        stringstream ss(line);
        string name;
        int friendIndex = 0;

        while (getline(ss, name, ',') && friendIndex < MAX_FRIENDS) 
        {
            students[numStudents][friendIndex++] = name;
        }
        numStudents++;
    }

    file.close();
}

// MUHAMMAD ABDULLAH 
// ye check karne ke liye keh if two students are direct friends
bool areDirectFriends(string students[MAX_STUDENTS][MAX_FRIENDS], int numStudents, const string& studentA, const string& studentB) {
    for (int i = 0; i < numStudents; i++) 
    {
        if (students[i][0] == studentA) 
        {
            for (int j = 1; j < MAX_FRIENDS && !students[i][j].empty(); j++) 
            {
                if (students[i][j] == studentB) 
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// MUHAMMAD DANIYAL IDREES 
// ye potential dhondne ke liye friendships
void findPotentialFriendships(string students[MAX_STUDENTS][MAX_FRIENDS], int numStudents, int alpha) 
{
    cout<< "Potential Friendships (Threshold(alpha): " << alpha << "):" <<endl;
    cout<<endl;

    for (int i = 0; i < numStudents; i++) 
    {
        for (int j = i + 1; j < numStudents; j++) { // duplicate pairs ko chorne ke lioye
            if (!areDirectFriends(students, numStudents, students[i][0], students[j][0])) // checking directfriends 
            {
                int commonFriends = 0;

                for (int k = 1; k < MAX_FRIENDS && !students[i][k].empty(); k++) 
                {
                    for (int l = 1; l < MAX_FRIENDS && !students[j][l].empty(); l++) 
                    {
                        if (students[i][k] == students[j][l]) 
                        {
                            commonFriends++;
                        }
                    }
                }

                if (commonFriends >= alpha) 
                {
                    cout<<students[i][0]<< " - " <<students[j][0]<< " (Common Friends: " <<commonFriends << ")" <<endl;
                }
            }
        }
    }
}

int main() {
    string students[MAX_STUDENTS][MAX_FRIENDS];
    int numStudents = 0;
    int alpha = 2; // common friends ki ginti ke liye

    loadData(students, numStudents, "Friends Data.csv");
    findPotentialFriendships(students, numStudents, alpha);

    return 0;
}
