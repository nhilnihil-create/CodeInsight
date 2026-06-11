#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string s,t;
    cin >> N >> s >> t;
    for(int i = 0; i <= N; ++i) {
        // sの[i,N)と、tの[0,N-i)が等しいか調べる
        bool flg = true;
        for(int j = 0; j < N-i; ++j) {
            if(s[i+j] != t[j]) {
                flg = false; break;
            }
        }
        if(flg) {
            cout << N + i << endl;
            return 0;
        }
    }
    cout << 2*N << endl;
    return 0;
}