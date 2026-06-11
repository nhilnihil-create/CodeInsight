#include <bits/stdc++.h>
#define rep(i, a, n) for(ll i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    map<int, int> mp;
    rep(i, 0, n){
        mp[a[i]]++;
        mp[a[i]-1]++;
        mp[a[i]+1]++;
    }
    int mx = 0;
    for(auto i : mp) mx = max(mx, i.second);
    cout << mx << endl;
    return 0;
}
