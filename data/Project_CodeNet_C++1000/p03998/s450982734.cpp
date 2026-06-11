#include <bits/stdc++.h>
using namespace std;

int main() {
    string S[10];
    cin >> S[0] >> S[1] >> S[2];

    char turn = 'a';
    while (1) {
        int idx = turn - 'a';
        if (S[idx].empty()) {
            cout << (char)toupper(turn) << endl;
            return 0;
        }
        turn = S[idx].front();
        S[idx] = S[idx].substr(1);
    }
}