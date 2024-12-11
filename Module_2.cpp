#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    const int maxRows = 190;  
    const int maxCol = 6;
    string arr[maxRows][maxCol];
    int rows = 0;
    
    ifstream in("Friends Dataset.csv");

    if (in.is_open()) {
        string line;

   
        getline(in, line);  //ye line add ki take wo pele lline ya row ko 
        // read kar le aur next step mai skip ho jae

        while (getline(in,line) && rows < maxRows){
            stringstream stm(line);
            string name ;
            int cols = 0;

            while(getline(stm,name,',') && cols < maxCol){
                arr[rows][cols] = name;
                cols++;
            }
            rows++;
        }
    in.close();
    for (int i =0;i<rows;i++){
        bool symetric = false;
        for(int k =0;k<rows;k++){
            if(arr[i][0]==arr[k][1] && arr[i][1] == arr[k][0]){
                symetric = true;
                break;  /// agar dono aps mai dost ho toh loop statement se bhr aa aje
            }
            
        }
        if(!symetric){
                cout << arr[i][0] << ", " << arr[i][1] <<endl;
            }
    }

    
    return 0;
}}


