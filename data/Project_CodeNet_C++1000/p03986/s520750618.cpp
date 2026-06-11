#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

ll solve(string X) {
    int i = 0;
    while (!X.empty() && i < X.size()) {
        if (X[i] == 'S' && X[i+1] == 'T') {
            X = X.substr(0,i) + X.substr(i+2);
            if (--i < 0) i++;
        } else i++;
    }
    return X.size();
}

ll solve2(string X) {
    int N = X.size();
    ll S = 0;
    rep(i,N) {
        if (X[i] == 'S') S++;
        else if (S > 0) S--;
    }
    return S * 2;
}
int main() {
    string X; cin >> X;
//    cout << solve(X) << endl;
    cout << solve2(X) << endl;
}
