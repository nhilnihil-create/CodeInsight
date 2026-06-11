#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    vector<vector<int>> min_a(N, vector<int>(N, 2e9));
    rep(i, N) {
        min_a[i][i] = a[i];
        rep(j, N - 1) {
            min_a[i][(i + j + 1) % N] = min(min_a[i][(i + j) % N], a[(i + j + 1) % N]);
        }
    }
    ll ans = 1e18;
    rep(i, N) {
        ll ans0 = 1LL * x * i;
        rep(j, N) {
            ans0 += min_a[j][(i + j) % N];
        }
        if (ans0 < ans) ans = ans0;
    }
    cout << ans << endl;
}