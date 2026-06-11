#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int INF = 1e9+10;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x] = i;
    }
    set<int> s;
    s.insert(0);
    s.insert(n+1);
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int pos = a[i];
        auto it = s.lower_bound(pos);
        ll h = *it;
        it--;
        ll l = *it;
        ans += (pos - l) * (h - pos) * i;
        s.insert(pos);
    }
    cout << ans << endl;
}
