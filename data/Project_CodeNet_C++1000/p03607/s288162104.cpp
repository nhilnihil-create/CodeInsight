#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);

    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    a.push_back(0);

    ll ans = 0, cnt = 0;
    rep(i, n) {
        cnt++;
        if (a[i] != a[i + 1]) {
            if (cnt % 2) ans++;
            cnt = 0;
        }
    }

    cout << ans << endl;

    return 0;
}