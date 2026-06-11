#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define repr(i, n) for (ll i = n - 1; i >= 0; --i)
const int MOD = 1000000007;
const ll INF = 10000000000;
using namespace std;

void solve(void)
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> mp;
    rep(i, n) mp[a[i] % 2]++;
    if (mp[1] % 2 == 1 && mp[0] > 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
int main(void)
{
    solve();
}