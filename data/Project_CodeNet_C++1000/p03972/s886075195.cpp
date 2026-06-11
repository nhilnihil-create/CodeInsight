#include<bits/stdc++.h>

using namespace std;

using ll = long long;
#define long long long

int main(void) {
    ll w, h;
    cin >> w >> h;
    vector<ll> p(w), q(h);
    for(auto &e: p) cin >> e;
    for(auto &e: q) cin >> e;
    
    vector<pair<ll,ll>> es;
    for(auto &e: p) es.push_back({e, 0});
    for(auto &e: q) es.push_back({e, 1});

    sort(es.begin(), es.end());

    ll xx = 0, yy = 0, r = 0;
    for(auto &e: es) {
        ll c, t;
        tie(c, t) = e;
        if(t == 0)
            r += max(0ll, c * (h+1 - yy)), xx++;
        else
            r += max(0ll, c * (w+1 - xx)), yy++;
    }
    cout << r << endl;

}
