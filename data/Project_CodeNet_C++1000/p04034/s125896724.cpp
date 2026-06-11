#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> b(n, 1);
    vector<pair<bool, bool> > rw(n);
    rw[0] = make_pair(1, 0);
    REP(i,1,n)rw[i] = make_pair(0, 1);
    rep(i,m){
        ll x, y;
        cin >> x >> y;
        x--; y--;
        if(!rw[x].first && rw[x].second)rw[y].second = 1;
        else if(rw[x].first && !rw[x].second)rw[y].first = 1;
        else rw[y].first = rw[y].second = 1;
        b[x]--; b[y]++;
        if(b[x] == 0)rw[x].first = rw[x].second = 0;
    }

    ll ans = 0;
    rep(i,n)if(rw[i].first)ans++;
    cout << ans << endl;
    
    return 0;
}