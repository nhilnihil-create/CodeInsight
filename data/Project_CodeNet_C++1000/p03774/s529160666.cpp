#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

ll calc_diff(ll x1, ll x2, ll y1, ll y2){
    ll diff = abs(x1 - x2) + abs(y1-y2);
    return diff;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(n);
    vector<pair<ll, ll>> c(m);
    vi cp(n);
    rep(i, n){
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        a[i] = make_pair(tmp1, tmp2);
    }
    rep(i, m){
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        c[i] = make_pair(tmp1, tmp2);
    }

    rep(i, n){
        ll tmp_max_diff = 99999999999999999;
        rep(j, m){
            if(tmp_max_diff > calc_diff(a[i].first, c[j].first, a[i].second, c[j].second)){
                tmp_max_diff = calc_diff(a[i].first, c[j].first, a[i].second, c[j].second);
                cp[i] = j;
            }
            /* printf("%d -> %d = ", i, j);
            cout << calc_diff(a[i].first, c[j].first, a[i].second, c[j].second) << endl; */
        }
    }

    rep(i, n){
        cout << cp[i] + 1 << endl;
    }
}