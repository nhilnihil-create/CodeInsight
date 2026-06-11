#include <bits/stdc++.h>
using namespace std;
 
int main() {
    //
    string strA, strB, strC;
    int indexA = 0;
    int indexB = 0;
    int indexC = 0;
    string turn = "a";
    string kekka;
 
    cin >> strA >> strB >> strC;
 
    while (true) {
        if (turn == "a") {
            if (strA.size() == indexA) {
                cout << "A";
                return 0;
            }
            turn = strA.at(indexA);
            indexA++;
        } else if (turn == "b") {
            if (strB.size() == indexB) {
                cout << "B";
                return 0;
            }
            turn = strB.at(indexB);
            indexB++;
        } else if (turn == "c") {
            if (strC.size() == indexC) {
                cout << "C";
                return 0;
            }
            turn = strC.at(indexC);
            indexC++;
        }
    }
    //
}