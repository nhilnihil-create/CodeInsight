#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int cnt = 0;
    int ok = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'S') {
            ok++;
        }
        else if(S[i] == 'T' && ok == 0) {
            cnt++;
        }
        else if(S[i] == 'T' && ok > 0) {
            ok--;
        }
    }
    cout << cnt*2 << endl;
}