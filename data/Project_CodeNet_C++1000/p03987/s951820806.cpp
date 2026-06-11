#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n;
    cin >> n;
    vector<P> v(n);
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[i] = P(a, i+1);
    }
    sort(v.begin(), v.end());
    set<int> s;
    s.insert(v[0].second);
    s.insert(n+1);
    ll ans = v[0].second * (n-v[0].second+1);

    for(int i = 1; i < n; i++)
    {
        P p = v[i];
        ll num = p.first;
        ll pos = p.second;
        s.insert(pos);
        auto itr = s.find(pos);
        if(itr == s.begin())
        {
            itr++;
            ll l = *itr; 
            ans += num * pos * (l-pos);
        }
        else
        {
            itr--;
            ll l = *itr;
            auto it = s.lower_bound(pos);
            it++;
            ll r = *it;
            ans += num * (pos-l) * (r-pos);
        }
    }
    cout << ans << endl;
}

