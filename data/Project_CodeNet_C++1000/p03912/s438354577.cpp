#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()

ll num_same_pairs(vector<ll>& x){
    sort(ALL(x));
    ll ret = 0;
    for(ll i = 0; i + 1 < x.size();){
        if(x.at(i) == x.at(i + 1)){
            ret++;
            i += 2;
        }else{
            i++;
        }
    }
    return ret;
}

int main(){
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> modm(m);
    REP(i, n){
        ll xi;
        cin >> xi;
        const ll mx = xi % m;
        modm.at(mx).push_back(xi);
    }

    ll ans = 0;
    for(ll mx = 0; mx <= m / 2; ++mx){
        const ll my = (m - mx) % m;
        if(mx == my){
            ans += modm.at(mx).size() / 2;
        }else{
            ll xi = mx, yi = my;
            if(modm.at(mx).size() > modm.at(my).size()){
                swap(xi, yi);
            }

            const ll ns = num_same_pairs(modm.at(yi));
            const ll sx = modm.at(xi).size();
            ans += sx + min(((ll)modm.at(yi).size() - sx) / 2, ns);
        }
    }
    cout << ans << endl;

    return 0;
}
