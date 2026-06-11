#include <bits/stdc++.h>
using namespace std;

const string T = "CODEFESTIVAL2016";

int main(){
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != T[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}