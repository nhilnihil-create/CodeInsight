#include<bits/stdc++.h>

using namespace std;

using ll = long long;
#define long long long

int main(void) {
    ll n, ma, mb;
    cin >> n >> ma >> mb;
    vector<tuple<ll,ll,ll>> v(n);
    for(auto &e: v) {
        ll a, b, c;
        cin >> a >> b >> c;
        e = make_tuple(a, b, c);
    }
    
    auto f = [&](ll a, ll b) {
        return mb * a - ma * b;
    };

    map<ll, ll> mp;
    for(ll i=0; i<n/2; i++) {
        map<ll, ll> pre = mp;
        pre[0] = 0;
        ll a, b, c;
        tie(a, b, c) = v[i];
        for(auto &t: pre) {
            ll k = t.first + f(a, b);
            if(mp.count(k)) mp[k] = min(mp[k], t.second + c);
            else mp[k] = t.second + c;
        }
    }

    map<ll, ll> mq;
    for(ll i=n/2; i<n; i++) {
        map<ll, ll> pre = mq;
        pre[0] = 0;
        ll a, b, c;
        tie(a, b, c) = v[i];
        for(auto &t: pre) {
            ll k = t.first + f(a, b);
            if(mq.count(k)) mq[k] = min(mq[k], t.second + c);
            else mq[k] = t.second + c;
        }
    }

    ll r = 1e18;
    for(auto &t: mp) {
        ll k, c;
        tie(k, c) = t;
        if(mq.count(-k))
            r = min(r, c + mq[-k]);
    }
    if(mp.count(0)) r = min(r, mp[0]);
    if(mq.count(0)) r = min(r, mq[0]);
    cout << (r == 1e18 ? -1 : r) << endl;
}
