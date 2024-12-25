#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 190;
const int MAX_FRIENDS = 6;

// data ko array mai load krwane kie liye
void loadData(string students[MAX_STUDENTS][MAX_FRIENDS],int& numStudents,const string& filename)
{
    ifstream file("Friends Dataset.csv");
    if (!file.is_open()) 
    {
        cout << "Unable to open file!" << endl;
        return;
    }
    string line;
    numStudents =0;
    while (getline(file, line) && numStudents < MAX_STUDENTS)
    {
        stringstream ss(line);
        string name;
        int friendIndex = 0;
        while(getline(ss, name, ',') && friendIndex < MAX_FRIENDS) 
        {
            students[numStudents][friendIndex++] = name;
        }
        numStudents++;
    }
    file.close();
}

// ye multiplicity graph baanne ke liye function hi
void createMultiplicityGraph(string students[MAX_STUDENTS][MAX_FRIENDS], int numStudents) 
{
    cout << "Multiplicity Graph (Weighted Graph):"<<endl;
    for(int i=0; i<numStudents; i++) 
    {
        for(int j=i+1; j<numStudents; j++) 
        { 
            int commonFriends=0;
            for(int k=1; k<MAX_FRIENDS && !students[i][k].empty(); k++) 
            {
                for(int l = 1; l<MAX_FRIENDS && !students[j][l].empty(); l++) 
                {
                    if(students[i][k] == students[j][l]) 
                    {
                        commonFriends++;
                    }
                }
            }
            if (commonFriends > 0) 
            {
                cout << students[i][0] << " - " << students[j][0] << " : " << commonFriends << endl;
            }
        }
    }
}

int main() {
    string students[MAX_STUDENTS][MAX_FRIENDS];
    int numStudents = 0;

    loadData(students, numStudents, "Friends Data.csv");
    createMultiplicityGraph(students, numStudents);

    return 0;
}
