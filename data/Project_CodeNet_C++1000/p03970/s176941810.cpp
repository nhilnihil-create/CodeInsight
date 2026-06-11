#include <bits/stdc++.h>
using namespace std;
int main () {
    string s = "CODEFESTIVAL2016";
    string S;
    cin >> S;
    int a = 0;
    for (int i = 0; i < S.length(); i++) {
        if (s[i] != S[i]) {
            a++;
        }
    }
    cout << a << endl;
}