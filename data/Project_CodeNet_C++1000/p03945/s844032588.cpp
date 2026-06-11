#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    char X = 'A';
    int ans = -1;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] != X){
            X = S[i];
            ans++;
        }
    }
    cout << ans << endl;
}