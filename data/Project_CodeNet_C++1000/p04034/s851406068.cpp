#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> box(n+1, 1);
    vector<bool> red(n+1, false);
    red[1] = true;
    rep(i, m){
        ll x, y; cin >> x >> y;
        if(red[x]) red[y] = true;
        box[x]--;
        box[y]++;

        if(box[x] == 0) red[x] = false;
    }
    ll ans = 0;
    for(auto i : red){
        if(i) ans++;
    }
    cout << ans << endl;
    return 0;
}