#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N, K;
    ll ans = 1e18;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    rep(i, 1 << (N - 1)) {
        int c = 1, h = a[0];
        ll s = 0;
        rep(j, N - 1) {
            if ((i >> j) & 1) {
                if (a[j + 1] > h) {
                    h = a[j + 1];
                    c++;
                }
                continue;
            }
            h = max(h + 1, a[j + 1]);
            s += h - a[j + 1];
            c++;
        }
        if (c < K) continue;
        ans = min(ans, s);
    }
    cout << ans << endl;
}