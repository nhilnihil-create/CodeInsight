#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;


int main() {

    int n,m; cin >> n >> m;
    ll Min = 100000000000000000;
    int ans;
    pair<ll,ll> p[51];
    pair<ll,ll> s[51];
    rep(i,n){
        ll x,y;
        cin >> x >> y;
        s[i] = make_pair(x,y);
    }

    rep(i,m){
        ll x,y;
        cin >> x >> y;
        p[i] = make_pair(x,y);
    }

    rep(i,n){
        Min = 100000000000000000;
        rep(j,m){
            ll tmp = abs(s[i].first-p[j].first)+abs(s[i].second-p[j].second);
            if(tmp < Min){
                Min = tmp;
                ans = j+1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}









