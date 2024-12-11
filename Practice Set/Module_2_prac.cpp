#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {

    // const int SIZE = 170;
    // string arr[SIZE];
    // int studentCount = 0;

    // ifstream in("Friends Dataset.csv");

    // string line;
    // while (getline(in, line)) {
    //     stringstream ss(line);
    //     // string name;


    //     while (getline(ss, line, ',')) {
    //         if (!line.empty() && studentCount < SIZE) {
    //             arr[studentCount++] = line;
    //             cout <<line<<endl;
    //         }
    //     }
    // }

    /////////////
    const int maxRows = 190;  
    const int maxCol = 6;
    string arr[maxRows][maxCol];
    int rows = 0;
    string line;
    ifstream in("Friends Dataset.csv");
    
       while (getline(in,line) && rows < maxRows){
        stringstream ss(line);
        string name ;
        int cols = 0;

        while(getline(ss,name,',') && cols < maxCol){
            arr[rows][cols] = name;
            cols++;
            // cout<<name;

        }
        rows++;
        }
    in.close();



    for (int i =0;i<rows;i++){
        bool symetric = false;
        for(int k =0;k<rows;k++){
            if(arr[i][0]==arr[k][1] && arr[i][1] == arr[k][0]){
                symetric = true;
                break;
            }
            
        }
        if(!symetric){
                cout << arr[i][0] << ", " << arr[i][1] <<endl;
            }
    }




    // string line;
    // while (getline(file, line) && row < maxRows) {
    //     stringstream ss(line);
    //     string value;
    //     int col = 0;

    //     while (getline(ss, value, ',') && col < maxColumns) {
    //         data[row][col] = value;
    //         col++;
    //     }
    //     row++;
    // }
    // file.close();

    //  string line;
    // ifstream in ("Friends Dataset.csv");

    // while (getline(in,line) && rows < maxRows){
    //     stringstream ss(line);
    //     string name ;
    //     int cols = 0;

    //     while(getline(ss,name,',') && cols < maxCol){
    //         arr[rows][cols] = name;
    //         cols++;
    //         // cout<<name;

    //     }
    //     rows++;
    //     }



    // by using for loop/////////////////
     // for (int rows = 0;rows < maxRows && getline(in , line);rows++){
        //     stringstream ss(line);
        //     string name;
        //     for(int cols = 0 ; cols < maxCol && getline(ss, name, ',');cols++){
        //         arr[rows][cols] = name;
        //         cout <<name<<endl;
        //     }
        // }

    
////////////////////////////////////////////////////

// MODULE - 1 Working 
    
    // const int SIZE = 170;
    // string arr[SIZE];
    // int studentcount = 0;
    
    
    // string line;
    // ifstream in ("Friends Dataset.csv");

    // while (getline(in,line)){
    //     stringstream ss(line);
    //     string name ;
    //     while(getline(ss,name,',')){
    //         if(!name.empty() && studentcount<SIZE){
    //             arr[studentcount++] = name;
    //         }
    //     }
    // }
 
    // in.close();
    //  int popstd = 0;
        
    // string name;

    // for (int i = 0 ;i < studentcount;i++){
    //     int dup = 0;
    //     for(int k = 0;k<studentcount;k++){
    //         if(arr[i]==arr[k]){
    //             dup++;

    //         }
    //     }
        
    //     if(popstd < dup){
    //         popstd = dup;
    //         name = arr[i];
    //     }
    // }
    // cout <<name << popstd;





// while (getline(in, line)) {
        //     stringstream stm(line);
        //     string name;


        //     while (getline(stm, name, ',')) {
        //         if (!name.empty() && studentCount < SIZE) {
        //             arr[studentCount++] = name;
        //             // cout<<name<<endl;
        //         }
        //     }
        // }
   
//     ////////////////////////////////////////////////////


// while(getline(in,line)){
//         stringstream ss(line);
//         string stdname;
//         while(getline(ss,stdname,',')){
//             if(!stdname.empty() && studentCount < SIZE){
//                 arr[studentCount++] = stdname;
//                 // cout<<stdname<<endl;
//             }
//         }

//     }


    // for (int i = 0; i < maxRows; i++) {
    //         for (int j = 0; j < maxCol; j++) {
    //             cout << arr[i][j] << " ";
    //         }
    //         // cout << endl;
    //     }

    // cout << "Data from the file:" << endl;
    // for (int i = 0; i < studentCount; i++) {
    //     cout << arr[i] << endl;  
    // }
    // for (int i = 0;i< SIZE;i++){
    //     cout<<arr[i]<<", ";
        
    // }



    // ofstream out("abd.txt",ios::trunc);
    // cout << "File existing content cleared successfully!" << endl<<endl;
    // cout << "New addition to the file!" << endl;
    // string name , address;
    // int age;
    // for(int i = 1;i<=3;i++){


    //     cout<<"Enter the data of "+to_string(i)+" Student :"<<endl;
    //     cout<<endl;
    //     cout<<"Enter the Name of Student :";
    //     getline(cin,name);
    //     cout<<"Enter the age of Student :";
    //     cin>>age;

    //     cout<<"Enter the address of Student :";
    //     getline(cin,address);


    //     string dataName = "Enter the name of Student :";
    //     string dataAge = "Enter the age of Student :";
    //     string dataAddress = "Enter the address of Student :";
    //     string data = "Enter the data of "+to_string(i)+" Student :";
        
        
    //     out << data << endl;
    //     out << dataName << name << endl;
    //     out << dataAge << age << endl;
    //     out << dataAddress << address << endl;
    //     out << endl;

    //     cout << endl << endl;


    // }



    // ifstream in("Friends Dataset.csv");
    // ofstream out("abd.txt");

    
    // string line;
    // while(getline(in,line) && row<maxRows){
    //     cout<<line<<endl;
    //     out<<line<<endl;



    // }
    // in.close();


//    for (int i = 0; i < maxRows; i++) {
//         for (int j = 0; j < maxColumns; j++) {
//             cout << data[i][j] << " ";
//         }
//         cout << endl;
//     }

    
    // cout << "Asymmetric friendship pairs:" << endl;

    
    // for (int i = 0; i < row; i++) {
    //     bool symmetric = false;
    //     for (int j = 0; j < row; j++) {
    //         if (data[i][0] == data[j][1] && data[i][1] == data[j][0]) {
    //             symmetric = true; 
    //             break;
    //         }
    //     }
    //     if (!symmetric) {
    //         cout << "(" << data[i][0] << ", " << data[i][1] << ")" << endl;
    //     }
    // }

        //    using for loop /////////////////////
        // string line;
        // for (int rows = 0;rows < MaxRow && getline(file , line);rows++){
        //     stringstream ss(line);
        //     string studentname;
        //     for(int cols = 0 ; cols < MaxCol && getline(ss, studentname, ',');cols++){
        //         data[rows][cols] = studentname;
        //         cout <<studentname<<endl;
        //     }
        // }

    return 0;
}




////////////////////////////////////

// for modeule 2



    //     while (getline(in,line) && rows < maxRows){
    //         stringstream stm(line);
    //         string name ;
    //         int cols = 0;

    //         while(getline(stm,name,',') && cols < maxCols){
    //             data[rows][cols] = name;
    //             cols++;
    //         }
    //         rows++;
    //     }
    //     in.close();
    // } else {
    //     cout << "Unable to open in!" << endl;
    // }





    // cout << "Asymmetric friendship pairs:" << endl;
    // for (int i = 0; i < rows; i++) {
    //     bool symmetric = false;
    //     for (int j = 0; j < rows; j++) {
    //         if (data[i][0] == data[j][1] && data[i][1] == data[j][0]) {
    //             symmetric = true; 
    //             break;
    //         }
    //     }
    //     if (!symmetric) {
    //         cout << "(" << data[i][0] << ", " << data[i][1] << ")" << endl;
    //     }
    // }

   
//    for (int i = 0; i < maxRows; i++) {
//         for (int j = 0; j < maxCols; j++) {
//             cout << data[i][j] << " ";
//         }
//         cout << endl;
//     }
// MODULE 2 WORKING ///////////////////



        // while (getline(in, line) && row < maxRows) {
        //     stringstream ss(line);
        //     string value;
        //     int col = 0;

        //     while (getline(ss, value, ',') && col < maxCols) {
        //         data[row][col] = value;
        //         col++;
        //     }
        //     row++;
        // }
        
        // string line;
        // for (int rows = 0;rows < maxRows && getline(in , line);rows++){
        //     stringstream ss(line);
        //     string name;
        //     for(int cols = 0 ; cols < maxCols && getline(ss, name, ',');cols++){
        //         data[rows][cols] = name;
        //         cout <<name<<endl;
        //     }
        // }




        ////////////////////////////