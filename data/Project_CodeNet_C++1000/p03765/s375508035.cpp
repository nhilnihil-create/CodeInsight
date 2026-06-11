#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    string S, T;
    cin >> S >> T;
    int m = S.size(), n = T.size();
    vector<int> Ssum(m + 1, 0), Tsum(n + 1, 0);
    rep(i, m) Ssum[i + 1] = Ssum[i] + 1 + (S[i] == 'B');
    rep(i, n) Tsum[i + 1] = Tsum[i] + 1 + (T[i] == 'B');
    int q, a, b, c, d;
    cin >> q;
    rep(i, q) {
        cin >> a >> b >> c >> d;
        if ((Ssum[b] - Ssum[a - 1] - Tsum[d] + Tsum[c - 1]) % 3 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}