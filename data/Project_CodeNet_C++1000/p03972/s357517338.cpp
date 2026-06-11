#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()


int main(){
    ll w, h;
    cin >> w >> h;
    vector<pair<ll, ll>> cost;
    REP(i, w){
        ll pi;
        cin >> pi;
        cost.emplace_back(pi, 0);
    }
    REP(i, h){
        ll qi;
        cin >> qi;
        cost.emplace_back(qi, 1);
    }

    sort(ALL(cost));

    ll ans = 0;
    for(auto p : cost){
        const ll ci = p.first;
        const ll flg = p.second;
        if(flg == 0){ // horizontal
            ans += (h + 1) * ci;
            w--;
        }else{ // vertical
            ans += (w + 1) * ci;
            h--;
        }
        if(w + h == 0){ break; }
    }
    cout << ans << endl;
    return 0;
}
