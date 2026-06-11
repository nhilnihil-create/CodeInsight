#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    for(int i = 1; i < S.size()/2 - 1; i++) {
        //cout << i << ':' << S.substr(0,S.size()/2 - i) << ':' << S.substr(S.size()/2 - i, S.size()/2 - i) << endl;
        if(S.substr(0,S.size()/2 - i) == S.substr(S.size()/2 - i, S.size()/2 - i)) {
            cout << (S.size()/2 - i)*2 << endl;
            return 0;
        }
    }
    cout << 2 << endl;

    return 0;
}