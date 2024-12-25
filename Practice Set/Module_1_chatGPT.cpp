#include<iostream>
using namespace std;
int main() {
    // Example 1D array
    const int SIZE = 170;
    string data[SIZE] = {  "Abdul Wasey", "Muhammad Samiullah", "Abdullah Bin Nazar", 
  "Fahad Hameed", "Rehan Ahmad", "Muhammad Burhan Faisal", "Muhammad Anus Javed", "Muhammad Ahmad",
  "Muhammad Hussnain", "Mudassar Hassan", "Abdullah Bin Nazar", 
  "Muhammad Haseeb Aslam", "Rehan Ahmad", "Laban Maseeh", "Muhammad Ahmad", "Muhammad Anus Javed",
  "Abdullah Bin Nazar", "Mudassar Hassan", "Muhammad Ahmad", "Ahmad Hassan", "Zia Ur Rehman",
  "Muhammad Abdullah", "Hafsa Aslam", "Muhammad Faisal Ghaffar", "Mohid Hussain", "Rana Mustehsin Hussain",
  "Nisma", "Rafiah", "Mehwish Samreen", "Seerat Ul Noor", "Rimsha Ahmad",
  "Anus Khan Burki", "Abdul Wasey", "Rana Mustehsin Hussain", 
  "Mudassar Hassan", "Muhammad Hussnain", "Abdullah Bin Nazar", 
  "Rimsha Ahmad", "Adina Tariq", "Dua Fatima", "Tuba Rani", "Hafsa Aslam",
  "Muhammad Hussain Abbas", "Muhammad Ahmad", "Farwah Tasleem", 
  "Rana Mustehsin Hussain", "Muhammad Samiullah", "Abdullah Bin Nazar", "Mudassar Hassan", "Anus Khan Burki",
  "Khadija Asghar", "Khadija Imam", "Farwah Tasleem", 
  "Aiman Mahmood", "Rafiah", "Mehwish Samreen", 
  "Muhammad Shehroz Hameed", "Muhammad Haseeb Aslam", "Fahad Hameed", "Muhammad Ahmad", "Zia Ur Rehman",
  "Seerat Ul Noor", "Rafiah", "Aiman Mahmood", 
  "Seerat Ul Noor", "Mehwish Samreen", "Aiman Mahmood", 
  "Laban Maseeh", "Abdullah Bin Nazar", "Muhammad Haseeb Aslam", "Muhammad Ammar", "Muhammad Shehroz Hameed",
  "Muhammad Ammar", "Muhammad Ahmad", "Muhammad Haseeb Aslam", 
  "Aiman", "Bismah Raees", "Muqadas Fatima", 
  "Warda Ali", "Khadija Imam", "Muqadas Fatima", "Shaiman Anwar", "Maheen Fatima",
  "Farwah Tasleem", "Nisma", "Khadija Imam", 
  "Muhammad Ahmad", "Rehan Ahmad", "Anus Khan Burki", "Muhammad Ammar", "Muhammad Shehroz Hameed",
  "Muhammad Faisal Ghaffar", "Azhar Khan", "Muhammad Daniyal Idrees", "Muhammad Hussnain", "Ahmad Hassan",
  "Nisma", "Khadija Asghar", "Khadija Imam", 
  "Muqadas Fatima", "Nisma", "Khadija Asghar", "Farwah Tasleem", "Zainab Sandhu",
  "Muhammad Hussnain", "Zia Ur Rehman", "Muhammad Abdullah", "Muhammad Anus Javed", "Muhammad Haseeb Aslam",
  "Muhammad Hussnain", "Mohid Hussain", "Muhammad Ahmad", "Muhammad Muneeb Ur Rehman", "Abdullah Bin Nazar",
  "Adina Tariq", "Hiba Sajid", "Muqadas Fatima", "Warda Ali", "Aiman Mahmood",
  "Ruhma Fatima", "Anus Khan Burki", "Zainab Sandhu", "Mudassar Hassan", "Zia Ur Rehman",
  "Muhammad Daniyal Idrees", "Muhammad Abdullah", "Hafsa Aslam", 
  "Muhammad Haseeb Aslam", "Muhammad Burhan Faisal", "Rehan Ahmad", 
  "Bismah Raees", "Rafiah", "Zainab Sandhu", "Muqadas Fatima", "Seerat Ul Noor",
  "Muhammad Samiullah", "Laban Maseeh", "Muhammad Burhan Faisal", "Muhammad Ahmad", "Azhar Khan",
  "Muhammad Anus Javed", "Farwah Tasleem", "Rehan Ahmad", "Muhammad Ammar", "Muhammad Shehroz Hameed",
  "Rimsha Ahmad", "Khadija Asghar", "Muhammad Haseeb Aslam", "Hiba Sajid", "Muhammad Hussnain",
  "Muhammad Ammar", "Hiba Sajid", "Abdullah Bin Nazar", "Muhammad Hussnain", "Khadija Asghar",
  "Maheen Fatima", "Dua Fatima", "Hiba Sajid", "Hafsa", "Eeshal Ahmad",
  "Aiman", "Adina Tariq", "Muqadas Fatima", "Mahnoor Ejaz", "Warda Ali",
  "Azhar Khan", "Muhammad Daniyal Idrees", "Mohid Hussain", "Anus Khan Burki", "Muhammad Anus Javed"
    };

    int size = sizeof(data) / sizeof(data[0]);

    string popularStudent = "";
    int maxCount = 0;

    for (int i = 0; i < SIZE; i++) {
        int count = 0;

        // Check if the current student is a duplicate of any previous student
        bool isDuplicate = false;
        for (int k = 0; k < i; k++) {
            if (data[i] == data[k]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            // Count the occurrences of data[i] in the array
            for (int j = 0; j < SIZE; j++) {
                if (data[i] == data[j]) {
                    count++;
                }
            }

            // Update the most popular student if the count is higher
            if (count > maxCount) {
                maxCount = count;
                popularStudent = data[i];
            }
        }
    }

    // Print the most popular student
    cout << "Most Popular Student: " << popularStudent << " with " << maxCount << " appearances." << endl;

    return 0;
}

