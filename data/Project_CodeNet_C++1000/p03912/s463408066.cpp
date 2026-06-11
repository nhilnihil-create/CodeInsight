#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(N), a(100001, 0), b(M, 0), c(M, 0);
    /*
    a[i]: iが何枚あるか
    b[i % M]: i % Mが何枚あるか.
    c[i % M]: iのペアの数
    */
    rep(i, N) {
        cin >> X[i];
        a[X[i]]++;
        b[X[i] % M]++;
    }
    rep(i, 100001) {
        c[i % M] += a[i] / 2;
    }
    /*
    rep(i, M) {
        cout << b[i] << " " << c[i] << endl;
    }
    */
    int ans = b[0] / 2;
    rep(i, M / 2) {
        if (i * 2 + 2 == M) {
            ans += b[i + 1] / 2;
        } else {
            int d = min(b[i + 1], b[M - i - 1]);
            ans += d;
            ans += min(c[i + 1], (b[i + 1] - d) / 2);
            ans += min(c[M - i - 1], (b[M - i - 1] - d) / 2);
        }
    }
    cout << ans << endl;
}