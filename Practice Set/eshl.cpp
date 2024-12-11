#include<iostream>


using namespace std;
int main(){
const int SIZE = 200;
string ab[SIZE][2];
int a = 0;
for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < 5; j++) {
        string f1 = ab[i][1];
        string f2 = ab[i][j];
        if (!f1.empty()) {
            bool issymmetric = false;
            for (int k = 0; k < SIZE; k++) {
                for (int l = 0; l < 5; l++) {
                    if (ab[k][l] == f1 && ab[k] [1]== f2) {
                        issymmetric = true;
                        break;
                    }
                }
                if (issymmetric) break;
            }
            if (!issymmetric) {
                ab[a][0] = f1;
                ab[a][1] = f2;
                a++;
            }
        }
    }
}
for (int i = 0; i < a; i++) {
    cout << "(" << ab[i][0] << "," << ab[i][1] << ")" << endl;
}
return 0;
}


