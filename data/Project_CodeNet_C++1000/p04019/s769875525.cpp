#include <bits/stdc++.h>
using namespace std;

int main() {

    string S; cin >> S;

    int numN = 0; int numS = 0; int numE = 0; int numW = 0;

    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == 'N') numN++;
        if (S.at(i) == 'S') numS++;
        if (S.at(i) == 'E') numE++;
        if (S.at(i) == 'W') numW++;
    }

    if (0 < numN * numS * numE * numW) cout << "Yes" << endl;

    else if (0 < numE * numW && numN == 0 && numS == 0) cout << "Yes" << endl;

    else if (0 < numN * numS && numE == 0 && numW == 0) cout << "Yes" << endl;

    else cout << "No" << endl;

}