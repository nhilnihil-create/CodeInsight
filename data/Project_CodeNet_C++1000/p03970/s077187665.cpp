#include <bits/stdc++.h>
using namespace std;

int main() {
    string CF = "CODEFESTIVAL2016";
    string S;
    cin >> S;
    int res = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] != CF[i]) {
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}