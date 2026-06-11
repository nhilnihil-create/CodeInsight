#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i).first;
        a.at(i).second = i;
    }
    sort(all(a));
    ll ans = 0;
    for(i = 0;i < n;++i){
        ll ind = a.at(i).second;
        if((ind-i)%2) ++ans;
    }
    cout << ans/2 << endl;

    return 0;
}
