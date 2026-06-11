#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n) {
        int a;
        cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for(auto x : mp) {
        if(x.second % 2 == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
