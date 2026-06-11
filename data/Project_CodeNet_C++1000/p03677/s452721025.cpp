#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
#define long ll

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(auto &e: a) cin >> e, e--;

    vector<ll> imos(m+1), imos2(m+1);
    ll s = 0;
    for(ll i=0; i<n-1; i++) {
        ll t = (m + a[i+1] - a[i]) % m;
        s += t;
        if(t <= 1) continue;

        ll u = (a[i]+2) % m;
        ll v = a[i+1]+1;
        if(u < v) {
            imos[u]++;
            imos[v]--;
            imos2[v]-=v-u;
        } else {
            imos[0]++;
            imos2[0]+=m-u;
            imos[v]--;
            imos2[v]-=v+m-u;
            imos[u]++;
        }
    }
    for(ll i=1; i<m; i++)
        imos[i] += imos[i-1];
    imos[0] += imos2[0];
    for(ll i=1; i<m; i++)
        imos[i] += imos[i-1] + imos2[i];

    ll r = s;
    for(ll i=0; i<m; i++)
        r = min(r, s - imos[i]);

    cout << r << endl;

}
