#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll w,h;
    cin >> w >> h;
    ll tate = h + 1;
    ll yoko = w + 1;
    vector<pair<ll,ll>> pq;
    rep(i,w){
        ll p;
        cin >> p;
        pq.emplace_back(p, 0);
    }
    rep(i,h){
        ll q;
        cin >> q;
        pq.emplace_back(q, 1);
    }
    sort(all(pq));
    ll spare = (h + 1)*(w + 1) - 1;
    ll ans = 0;
    i = 0;
    while(spare){
        auto x = pq.at(i);
        ll num = x.first;
        ll flag = x.second;
        if(flag == 0){
            ans += num*tate;
            --yoko;
            spare -= tate;
        }else{
            ans += num*yoko;
            --tate;
            spare -= yoko;
        }
        ++i;
    }
    cout << ans << endl;

    return 0;
}