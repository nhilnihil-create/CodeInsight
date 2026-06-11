#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> abs(n);
    rep(i, n) cin >> abs[i].first >> abs[i].second;

    sort(abs.begin(), abs.end());
    ll ans = abs[0].first-1;
    for (int i = 0; i < n - 1; i++){
        ans += min(abs[i + 1].first - abs[i].first, abs[i].second - abs[i+1].second);
    }
    ans += abs[n - 1].second + 1;
    cout << ans << endl;
}
