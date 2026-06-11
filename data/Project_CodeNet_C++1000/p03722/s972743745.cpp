#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cout << fixed << setprecision(16);

    ll n, m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> es(m);
    for(ll i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        es[i] = make_tuple(a, b, -c);
    }

    vector<ll> dis(n, 1e15);
    dis[0] = 0;

    {
        ll i;
        for(i=0; i<n; i++) {
            bool ok = true;
            for(auto &e: es) {
                ll a, b, c;
                tie(a, b, c) = e;
                if(dis[a] + c < dis[b])
                    dis[b] = dis[a]+c, ok = false;
            }
            if(ok) break;
        }
        for(i=0; i<n; i++) {
            bool ok = true;
            for(auto &e: es) {
                ll a, b, c;
                tie(a, b, c) = e;
                if(dis[a] + c < dis[b]) {
                    if(b == n-1) {
                        cout << "inf" << endl;
                        return 0;
                    }
                    dis[b] = dis[a]+c, ok = false;
                }
            }
            if(ok) break;
        }
        cout << -dis[n-1] << endl;
    }
}
