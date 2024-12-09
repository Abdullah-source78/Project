#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {

    const int SIZE = 190; 
    string arr[SIZE]; 
    int studentCount = 0; 
    ifstream in("Friends Dataset.csv");
    if(in.is_open()){

        string line;
         while (getline(in,line)){
            stringstream stm(line);
            string name ;
            while(getline(stm,name,',')){
                if(!name.empty() && studentCount < SIZE){
                    arr[studentCount++] = name;
                }
            }
        }
        
    } else {
        cout << "Unable to open File!" << endl;
    }
    in.close();
    int maxDup = 0;
    string popularStd;

    for (int i = 0; i < SIZE; i++) {
        int duplicate = 0;
        for (int k = 0; k < SIZE; k++) {
            if (arr[i] == arr[k]) {
                duplicate++;
            }
        }

        if(maxDup < duplicate){

            maxDup = duplicate -1;
            popularStd = arr[i];
        }

    }
    
    cout <<"Popular student "<<popularStd<< " appears " << maxDup << " times!!" << endl;

    return 0;
}

