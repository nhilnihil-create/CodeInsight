#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i,0,N) cin >> a[i];

    ll ans = 15000000000;
    rep(bit, 0, 1<<N) {
        if (__builtin_popcount(bit) != K) continue;

        ll price = 0;
        int highest = 0;
        rep(i,0,N) {
            if (bit & (1<<i)) {
                price += max(0, highest + 1 - a[i]);
                highest = max(highest + 1, a[i]);
            } else highest = max(highest, a[i]);
        }
        ans = price < ans ? price : ans;
    }
    cout << ans << endl;
}