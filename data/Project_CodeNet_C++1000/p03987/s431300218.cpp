#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n); rep(i,n) { cin >> a[i]; a[i]--; }
    vector<int> aa(n); rep(i,n) aa[a[i]] = i;

    ll ans = 0ll;
    set<int> data;
    data.insert(-1);
    data.insert(n);
    rep(i,n) {
        auto iter = data.upper_bound(aa[i]);
        ans += (ll)(i+1) * (ll)(*iter - aa[i]) * (ll)(aa[i] - *prev(iter));
        data.insert(aa[i]);
    }
    cout << ans << endl;
    return 0;
}