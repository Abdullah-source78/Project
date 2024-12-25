#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {

//    const int SIZE = 170;
//     string data[SIZE] = {  "Abdul Wasey", "Muhammad Samiullah", "Abdullah Bin Nazar", 
//   "Fahad Hameed", "Rehan Ahmad", "Muhammad Burhan Faisal", "Muhammad Anus Javed", "Muhammad Ahmad",
//   "Muhammad Hussnain", "Mudassar Hassan", "Abdullah Bin Nazar", 
//   "Muhammad Haseeb Aslam", "Rehan Ahmad", "Laban Maseeh", "Muhammad Ahmad", "Muhammad Anus Javed",
//   "Abdullah Bin Nazar", "Mudassar Hassan", "Muhammad Ahmad", "Ahmad Hassan", "Zia Ur Rehman",
//   "Muhammad Abdullah", "Hafsa Aslam", "Muhammad Faisal Ghaffar", "Mohid Hussain", "Rana Mustehsin Hussain",
//   "Nisma", "Rafiah", "Mehwish Samreen", "Seerat Ul Noor", "Rimsha Ahmad",
//   "Anus Khan Burki", "Abdul Wasey", "Rana Mustehsin Hussain", 
//   "Mudassar Hassan", "Muhammad Hussnain", "Abdullah Bin Nazar", 
//   "Rimsha Ahmad", "Adina Tariq", "Dua Fatima", "Tuba Rani", "Hafsa Aslam",
//   "Muhammad Hussain Abbas", "Muhammad Ahmad", "Farwah Tasleem", 
//   "Rana Mustehsin Hussain", "Muhammad Samiullah", "Abdullah Bin Nazar", "Mudassar Hassan", "Anus Khan Burki",
//   "Khadija Asghar", "Khadija Imam", "Farwah Tasleem", 
//   "Aiman Mahmood", "Rafiah", "Mehwish Samreen", 
//   "Muhammad Shehroz Hameed", "Muhammad Haseeb Aslam", "Fahad Hameed", "Muhammad Ahmad", "Zia Ur Rehman",
//   "Seerat Ul Noor", "Rafiah", "Aiman Mahmood", 
//   "Seerat Ul Noor", "Mehwish Samreen", "Aiman Mahmood", 
//   "Laban Maseeh", "Abdullah Bin Nazar", "Muhammad Haseeb Aslam", "Muhammad Ammar", "Muhammad Shehroz Hameed",
//   "Muhammad Ammar", "Muhammad Ahmad", "Muhammad Haseeb Aslam", 
//   "Aiman", "Bismah Raees", "Muqadas Fatima", 
//   "Warda Ali", "Khadija Imam", "Muqadas Fatima", "Shaiman Anwar", "Maheen Fatima",
//   "Farwah Tasleem", "Nisma", "Khadija Imam", 
//   "Muhammad Ahmad", "Rehan Ahmad", "Anus Khan Burki", "Muhammad Ammar", "Muhammad Shehroz Hameed",
//   "Muhammad Faisal Ghaffar", "Azhar Khan", "Muhammad Daniyal Idrees", "Muhammad Hussnain", "Ahmad Hassan",
//   "Nisma", "Khadija Asghar", "Khadija Imam", 
//   "Muqadas Fatima", "Nisma", "Khadija Asghar", "Farwah Tasleem", "Zainab Sandhu",
//   "Muhammad Hussnain", "Zia Ur Rehman", "Muhammad Abdullah", "Muhammad Anus Javed", "Muhammad Haseeb Aslam",
//   "Muhammad Hussnain", "Mohid Hussain", "Muhammad Ahmad", "Muhammad Muneeb Ur Rehman", "Abdullah Bin Nazar",
//   "Adina Tariq", "Hiba Sajid", "Muqadas Fatima", "Warda Ali", "Aiman Mahmood",
//   "Ruhma Fatima", "Anus Khan Burki", "Zainab Sandhu", "Mudassar Hassan", "Zia Ur Rehman",
//   "Muhammad Daniyal Idrees", "Muhammad Abdullah", "Hafsa Aslam", 
//   "Muhammad Haseeb Aslam", "Muhammad Burhan Faisal", "Rehan Ahmad", 
//   "Bismah Raees", "Rafiah", "Zainab Sandhu", "Muqadas Fatima", "Seerat Ul Noor",
//   "Muhammad Samiullah", "Laban Maseeh", "Muhammad Burhan Faisal", "Muhammad Ahmad", "Azhar Khan",
//   "Muhammad Anus Javed", "Farwah Tasleem", "Rehan Ahmad", "Muhammad Ammar", "Muhammad Shehroz Hameed",
//   "Rimsha Ahmad", "Khadija Asghar", "Muhammad Haseeb Aslam", "Hiba Sajid", "Muhammad Hussnain",
//   "Muhammad Ammar", "Hiba Sajid", "Abdullah Bin Nazar", "Muhammad Hussnain", "Khadija Asghar",
//   "Maheen Fatima", "Dua Fatima", "Hiba Sajid", "Hafsa", "Eeshal Ahmad",
//   "Aiman", "Adina Tariq", "Muqadas Fatima", "Mahnoor Ejaz", "Warda Ali",
//   "Azhar Khan", "Muhammad Daniyal Idrees", "Mohid Hussain", "Anus Khan Burki", "Muhammad Anus Javed"
//     };

    const int SIZE = 200; // Maximum number of students in the file
    string arr[SIZE]; // 1D array to store all student names
    int studentCount = 0; // number of students from the file
    ifstream file("Friends Dataset.csv");
    if (!file.is_open()) {
        cout << "Unable to open file!" << endl;
        return 1;
    }

    // Read the file and store data into the 1D array
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name;

        // Extract each name from the row
        while (getline(ss, name, ',')) {
            if (!name.empty() && studentCount < SIZE) {
                arr[studentCount++] = name;
            }
        }
    }
    file.close();


    // unordered_map<string, int> countMap;
    // for (int i = 0; i < studentCount; i++) {
    //     countMap[arr[i]]++;
    // }
    // string popularStudent;
    // int maxCount = 0;

    // for (const auto& pair : countMap) {
    //     if (pair.second > maxCount) {
    //         maxCount = pair.second;
    //         popularStudent = pair.first;
    //     }
    // }

    // cout << "Most popular student: " << popularStudent 
    //      << " with " << maxCount << " friends." << endl;

    // int SecondDup = 0;
    // string SecStd;
    // int minDup = 2000;
    // string minPopStd;
    int maxDup = 0;
    string popularStd;
    for (int i = 0; i < SIZE; i++) {
        int duplicate = 0;
        for (int k = 0; k < SIZE; k++) {
            if (arr[i] == arr[k]) {
                duplicate++;
            }
        }

        // bool exists = false;
        // for (int h = 0; h < i; h++) {
        //     if (arr[i] == arr[h]) {
        //         exists = true;
        //         break;
        //     }
        // }
        if(maxDup < duplicate){
            // SecondDup= maxDup;
            // SecStd = popularStd;
            maxDup = duplicate -1;
            popularStd = arr[i];


        }
        // if(minDup > duplicate){
        //     minDup= duplicate;
        //     minPopStd = arr[i];
        // }
    }
    
    cout <<"Popular student "<<popularStd<< " appears " << maxDup << " times!!" << endl;
    // cout <<"Second Popular student "<<SecStd<< " appears " << SecondDup << " times!!" << endl;
    // cout <<"Least Popular student "<<minPopStd<< " appears " << minDup << " times!!" << endl;
    
    // cout << "Popular Student is: " << popularStd << " with " << maxDup << " appearances." << endl;

    return 0;
}

