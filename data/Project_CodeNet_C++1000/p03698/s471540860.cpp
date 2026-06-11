#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    map<char, int>d;
    bool kotonaru = true;
    for (int i=0; i<S.size(); i++) {
        if (d.count(S[i]) > 0) {
            kotonaru = false;
            break;
        } else {
            d[S[i]] = 1;
        }
    }

    if (kotonaru) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}