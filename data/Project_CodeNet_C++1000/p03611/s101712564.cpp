#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> mp;
    rep(i, n){
        cin >> a[i];

        for(ll j=-1;j<2;j++){
            ll a_ = a[i]+j;
            if (mp.find(a_) == mp.end()){
                mp[a_] = 1;
            }else{
                mp[a_] += 1;
            }
        }
    }

    ll ans = 0;
    for(auto o : mp){
        ans = max(o.second, ans);
    }
    cout << ans << endl;


    return 0;
}
