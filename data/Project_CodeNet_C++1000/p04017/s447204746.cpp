#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

ll pow_mod(ll a, ll n, ll p)
{
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res*a%p;
        a = a*a%p;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    const ll MOD = 1e9+7;
    for(i = 0;i < n;++i){
        cin >> x.at(i);
    }
    for(i = 0;i < n;++i){
        y.at(i) = MOD - x.at(n-1-i);
    }
    ll l,q;
    cin >> l >> q;
    ll tmptime = 33;
    vector<vector<ll>> dp(n+1,vector<ll>(tmptime));
    rep(j,tmptime){
        for(i = 0;i < n;++i){
            if(j == 0){
                ll ind = upper_bound(all(x), x.at(i) + l) - x.begin();
                dp.at(i).at(j) = ind-1;
            }else{
                dp.at(i).at(j) = dp.at(dp.at(i).at(j-1)).at(j-1);
            }
        }
    }
    vector<vector<ll>> dp2(n+1,vector<ll>(tmptime));
    rep(j,tmptime){
        for(i = 0;i < n;++i){
            if(j == 0){
                ll ind = upper_bound(all(y), y.at(i) + l) - y.begin();
                dp2.at(i).at(j) = ind-1;
            }else{
                dp2.at(i).at(j) = dp2.at(dp2.at(i).at(j-1)).at(j-1);
            }
        }
    }
    
    for(i = 0;i < q;++i){
        ll a,b;
        cin >> a >> b;
        --a;    --b;
        if(a < b){
            ll now = a;
            ll ans = 0;
            if(b != n-1){
                while(true){
                    ll ind = lower_bound(all(dp.at(now)), b) - dp.at(now).begin();
                    if(ind == 0){
                        ++ans;
                        break;
                    }else if(dp.at(now).at(ind) == b){
                        ans += pow_mod(2ll, ind, MOD);
                        break;
                    }else{
                        now = dp.at(now).at(ind - 1);
                        ans += pow_mod(2ll, ind - 1, MOD);
                    }
                }
            }else{
                while(true){
                    ll ind = lower_bound(all(dp.at(now)), b) - dp.at(now).begin();
                    if(ind == 0){
                        ++ans;
                        break;
                    }else{
                        now = dp.at(now).at(ind - 1);
                        ans += pow_mod(2ll, ind - 1, MOD);
                    }
                }
            }
            cout << ans << endl;
        }else{
            ll now = n-1-a;
            b = n-1-b;
            ll ans = 0;
            if(b != n-1){
                while(true){
                    ll ind = lower_bound(all(dp2.at(now)), b) - dp2.at(now).begin();
                    if(ind == 0){
                        ++ans;
                        break;
                    }else if(dp2.at(now).at(ind) == b){
                        ans += pow_mod(2ll, ind, MOD);
                        break;
                    }else{
                        now = dp2.at(now).at(ind - 1);
                        ans += pow_mod(2ll, ind - 1, MOD);
                    }
                }
            }else{
                while(true){
                    ll ind = lower_bound(all(dp2.at(now)), b) - dp2.at(now).begin();
                    if(ind == 0){
                        ++ans;
                        break;
                    }else{
                        now = dp2.at(now).at(ind - 1);
                        ans += pow_mod(2ll, ind - 1, MOD);
                    }
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}