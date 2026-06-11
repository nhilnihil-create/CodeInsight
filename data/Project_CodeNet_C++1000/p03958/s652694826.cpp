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
    ll k, t; cin >> k >> t;
    vector<ll> a(t); cin >> a;
    sort(a.rbegin(), a.rend());
    ll s = a[0];
    rep(i, t){
        if(i == 0) continue;
        if(s == 0){
            s = a[i];
            continue;
        }
        ll u = a[i];
        if(s < u) swap(s, u);
        s = s - u;
    }
    ll ans = s-1;
    if(ans < 0) ans = 0;
    cout << ans << endl;
    return 0;
}