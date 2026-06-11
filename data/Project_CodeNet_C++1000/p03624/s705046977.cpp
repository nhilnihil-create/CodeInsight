#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    map<char, int>d;
    for (int i=0; i<S.size(); i++) {
        if (d.count(S[i]) == 0) {
            d[S[i]] = 1;
        }
    }

    bool ikeru = false;
    char a;
    for (char j='a'; j <= 'z'; j++) {
        if (d.count(j) == 0) {
            ikeru = true;
            a = j;
            break;
        }
    }

    if (ikeru) {
        cout << a << endl;
    } else {
        cout << "None" << endl;
    }

    return 0;
}