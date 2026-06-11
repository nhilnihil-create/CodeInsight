#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int X = S.size()-1;
    while(X >= 2) {
        bool ok = true;
        if(X%2 == 1) {
            X--;
            continue;
        }
        for(int i = 0; i < X/2; i++) {
            if(S[i] != S[i+X/2]) {
                ok = false;
            }
        }
        if(ok) {
            cout << X << endl;
            return 0;
        }
        X--;
    }
}