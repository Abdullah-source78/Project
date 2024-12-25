#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {

    const int Length = 190; //Muhammad Daniyal idrees
    string arr[Length];

    string word;
    int stdCount = 0;

    ifstream file("Friends Dataset.csv");

        while (getline(file,word)){
        stringstream ss(word);
        string value ;
        while(getline(ss,value,',')){
            if(!value.empty() && stdCount < Length){
                arr[stdCount++] = value;
            }
        }
    }

    file.close(); //Muhammad Daniyal Idrees
    int exists = 0;    //Hafsa Aslam
    string popularStudent;

    for (int i = 0; i < Length; i++) {
        int StdDup = 0;
        for (int k = 0; k < Length; k++) {
            if (arr[i] == arr[k]) {
                StdDup++;
            }
        }

        if(exists < StdDup){
            exists = StdDup -1;
            popularStudent = arr[i];
        }
    }

    cout <<popularStudent<<" is the most Popular student who appears " << exists << " times." << endl;

    return 0;
} //Hafsa Aslam
