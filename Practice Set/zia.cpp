// #include <iostream>
// #include <sstream>
// #include <string>
// #include <fstream>

// using namespace std;

// int main() {

//     const int arrRows = 250;  
//     const int arrCols = 7;

//     ifstream open("dataset.csv");
//     string data[arrRows][arrCols];
//     string studentname;

//     int row = 0;
//     while(getline(open, studentname) && row < arrRows) {
//         stringstream stream(studentname);
//         string value;
//         int col = 0;
//         while (getline(stream, value, ',') && col < arrCols) {
//             data[row][col] = value;
//             col++;
//         }
//         row++;
//     }

//     for (int i = 0; i < row; i++) {
//         bool samestudents = false;
//         for (int h = 0; h < row; h++) {
//             if (data[i][0] == data[h][1] && data[i][1] == data[h][0]) {
//                 samestudents = true; 
//                 break;
//             }
//         }
//         if (!samestudents) {
//             cout << data[i][0] << ", " << data[i][1]  << endl;
//         }
//     }
//     return 0;
// }




// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// using namespace std;
// int main() {

//     const int Length = 190; 
//     string arr[Length];

//     string studentname;
//     int stdCount = 0; 

//     ifstream open("dataset.csv");

//         while (getline(open,studentname)){
//             stringstream stream(studentname);
//             string Studentss ;
//             while(getline(stream,Studentss,',')){
//                 if(!Studentss.empty() && stdCount < Length){
//                     arr[stdCount++] = Studentss;
//                 }
//             }
//     }
        

    
//     open.close();
//     int exists = 0;
//     string popularStd;

//     for (int i = 0; i < Length; i++) {
//         int StdDup = 0;
//         for (int k = 0; k < Length; k++) {
//             if (arr[i] == arr[k]) {
//                 StdDup++;
//             }
//         }

//         if(exists < StdDup){
//             exists = StdDup -1;
//             popularStd = arr[i];
//         }
//     }
    
//     cout <<popularStd<<" is the most Popular student who appears " << exists << " times." << endl;

//     return 0;
// }




// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// using namespace std;

// int main() {
//     const int MAX_SIZE = 190; 
//     string names[MAX_SIZE];   
//     int nameCount = 0;        

//     ifstream inputFile("Friends Dataset.csv");


//     string line;


//     while (getline(inputFile, line)) {
//         stringstream lineStream(line);
//         string name;
//         while (getline(lineStream, name, ',')) {
//             if (!name.empty() && nameCount < MAX_SIZE) {
//                 names[nameCount++] = name;
//             }
//         }
//     }

//     inputFile.close();


//     string mostFrequentName;
//     int maxCount = 0;


//     for (int i = 0; i < nameCount; i++) {
//         int count = 0;

       
//         for (int j = 0; j < nameCount; j++) {
//              if (names[i] == names[j]) {
//                 count++;
//             }
//         }

  
//         if (count > maxCount) {
//             maxCount = count - 1;
//             mostFrequentName = names[i];
//         }
//     }

//     cout << "The most popular student is: " << mostFrequentName 
//          << " with " << maxCount << " appearances." << endl;

//     return 0;
// }





// module 2/////////////////////////


// #include <iostream>
// #include <sstream>
// #include <string>
// #include <fstream>

// using namespace std;

// int main() {
//     const int MAX_ROWS = 250; 
//     const int MAX_COLS = 7;  

//     ifstream inputFile("Friends Dataset.csv");
//     string records[MAX_ROWS][MAX_COLS]; 
//     string line;

//     int currentRow = 0;

//     while (getline(inputFile, line) && currentRow < MAX_ROWS) {
//         stringstream lineStream(line);
//         string field;
//         int currentCol = 0;

//         while (getline(lineStream, field, ',') && currentCol < MAX_COLS) {
//             records[currentRow][currentCol] = field;
//             currentCol++;
//         }
//         currentRow++;
//     }

 
//     for (int i = 0; i < currentRow; i++) {
//         bool isDuplicatePair = false;

//         for (int j = 0; j < currentRow; j++) {
//             if (records[i][0] == records[j][1] && records[i][1] == records[j][0]) {
//                 isDuplicatePair = true;
//                 break;
//             }
//         }

        
//         if (!isDuplicatePair) {
//             cout << records[i][0] << ", " << records[i][1] << endl;
//         }
//     }

//     return 0;
// }










// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>

// using namespace std;

// int main() {
//     const int MAX_ENTRIES = 250; 
//     const int MAX_COLUMNS = 7;  

//     ifstream fileStream("Friends Dataset.csv"); 
//     string data[MAX_ENTRIES][MAX_COLUMNS]; 
//     string lineContent;

//     int totalRows = 0; 
    

//     while (getline(fileStream, lineContent) && totalRows < MAX_ENTRIES) {
//         stringstream rowStream(lineContent);
//         string cell;
//         int currentColumn = 0;

//         while (getline(rowStream, cell, ',') && currentColumn < MAX_COLUMNS) {
//             data[totalRows][currentColumn] = cell;
//             currentColumn++;
//         }
//         totalRows++;
//     }

//     for (int rowIndex = 0; rowIndex < totalRows; rowIndex++) {
//         bool duplicateFound = false;

//         for (int compareIndex = 0; compareIndex < totalRows; compareIndex++) {
            
//             if (data[rowIndex][0] == data[compareIndex][1] && data[rowIndex][1] == data[compareIndex][0]) {
//                 duplicateFound = true;
//                 break;
//             }
//         }

        
//         if (!duplicateFound) {
//             cout << data[rowIndex][0] << " , " << data[rowIndex][1] << endl;
            
//         }
//     }

//     return 0;
// }





// ACTUAL LOGIC  /////////////////////////////////////////////





// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>

// using namespace std;

// int main() {
//     const int MAX_ROWS = 250;  // Maximum rows
//     const int MAX_COLS = 7;    // Maximum columns (including Name and Friend columns)
//     unordered_map<string, vector<string>> friendships; // Map to store friendships

//     ifstream inputFile("Friends Dataset.csv");
//     string line;
//     bool skipHeader = true; // Flag to skip the first row

//     // Parse the dataset
//     while (getline(inputFile, line)) {
//         if (skipHeader) { // Skip the header row
//             skipHeader = false;
//             continue;
//         }

//         stringstream rowStream(line);
//         string person;
//         vector<string> friends;
//         string friendName;

//         getline(rowStream, person, ','); // Read the person name

//         // Read friends of the person
//         while (getline(rowStream, friendName, ',')) {
//             if (!friendName.empty()) {
//                 friends.push_back(friendName);
//             }
//         }

//         friendships[person] = friends; // Map person to their friends list
//     }

//     // Close the file
//     inputFile.close();

//     // Check for reciprocation
//     for (const auto& pair : friendships) {
//         const string& person = pair.first;
//         const vector<string>& personFriends = pair.second;

//         cout << person << " has friends: ";
//         for (const string& friendName : personFriends) {
//             cout << friendName << " ";
//         }
//         cout << endl;

//         for (const string& friendName : personFriends) {
//             // Check if the friend reciprocates the friendship
//             if (friendships.find(friendName) != friendships.end()) {
//                 const vector<string>& friendList = friendships[friendName];
//                 if (find(friendList.begin(), friendList.end(), person) != friendList.end()) {
//                     // cout << "  -> " << friendName << " also lists " << person << " as a friend." << endl;
//                 } else {
//                     cout << "  -> " << friendName << " does NOT list " << person << " as a friend." << endl;
//                 }
//             } else {
//                 // cout << "  -> " << friendName << " has no friend list available." << endl;
//             }
//         }
//         cout << endl;
//     }

//     return 0;
// }








// #include <iostream>
// #include <sstream>
// #include <string>
// #include <fstream>

// using namespace std;

// int main() {
//     const int MAX_ROWS = 250; // Maximum number of rows
//     const int MAX_COLS = 7;   // Maximum number of columns (Name + 6 Friends)
//     string records[MAX_ROWS][MAX_COLS]; // 2D array to store the data
//     string line;

//     ifstream inputFile("Friends Dataset.csv");
//     if (!inputFile.is_open()) {
//         cout << "Error: Unable to open the file!" << endl;
//         return 1;
//     }

//     int totalRows = 0;
//     bool skipHeader = true;

//     // Reading the CSV file into the 2D array
//     while (getline(inputFile, line) && totalRows < MAX_ROWS) {
//         if (skipHeader) { 
//             skipHeader = false; 
//             continue; 
//         }
        
//         stringstream lineStream(line);
//         string value;
//         int currentCol = 0;

//         while (getline(lineStream, value, ',') && currentCol < MAX_COLS) {
//             records[totalRows][currentCol++] = value;
//         }
//         totalRows++;
//     }
//     inputFile.close();

//     // Checking friendships
//     for (int i = 0; i < totalRows; i++) {
//         string person = records[i][0];
//         cout << person << " has friends: ";

//         // Print all friends of the current person
//         for (int j = 1; j < MAX_COLS; j++) {
//             if (!records[i][j].empty()) {
//                 cout << records[i][j] << " ";
//             }
//         }
//         cout << endl;

//         // Check if each friend of the person also lists the person as a friend
//         for (int j = 1; j < MAX_COLS; j++) {
//             string friendName = records[i][j];
//             if (!friendName.empty()) {
//                 bool mutualFriendship = false;

//                 // Look for the person in the friend's row
//                 for (int k = 0; k < totalRows; k++) {
//                     if (records[k][0] == friendName) {
//                         for (int l = 1; l < MAX_COLS; l++) {
//                             if (records[k][l] == person) {
//                                 mutualFriendship = true;
//                                 break;
//                             }
//                         }
//                         break;
//                     }
//                 }

//                 if (mutualFriendship) {
//                     cout << "  -> " << friendName << " also lists " << person << " as a friend." << endl;
//                 } else {
//                     cout << "  -> " << friendName << " does NOT list " << person << " as a friend." << endl;
//                 }
//             }
//         }
//         cout << endl;
//     }

//     return 0;
// }





