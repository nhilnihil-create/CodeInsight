#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    map<int, bool> mp;
    rep(i, 0, n) mp[a[i]] = !mp[a[i]];
    int ans = 0;
    for(auto i : mp) if(i.second) ans++;
    cout << ans << endl;
    return 0;
}
