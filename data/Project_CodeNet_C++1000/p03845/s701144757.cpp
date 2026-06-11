#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    vector<ll> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    int m;
    cin >> m;
    vector<pair<int,ll>> d(m);
    for(int i = 0; i < m; i++){
        int p;
        ll x;
        cin >> p >> x;
        d[i] = make_pair(p, x);
    }
    for(int i = 0; i < m; i++){
        ll ans = 0;
        for(int j = 0; j < n; j++){
            if(d[i].first - 1 == j) ans += d[i].second;
            else ans += t[j];
        }
        cout << ans << endl;
    }
    return 0;
}