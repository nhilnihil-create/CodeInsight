#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

ll _gcd(ll x, ll y){
    if(y == 0) return x;
    return (x % y) ? _gcd(y, x % y) : y;
}
ll _lcm(ll x, ll y){
    return x / _gcd(x, y) * y;
}

int main(){
    ll n; cin >> n;
    vector<ll> t(n), tlcm(n);
    rep(i, n){
        cin >> t[i];
        if(i == 0) tlcm[i] = t[i];
        else if(i == 1) tlcm[i] = _lcm(t[i-1], t[i]);
        else tlcm[i] = _lcm(t[i], tlcm[i-1]);
    }
    cout << tlcm[n-1] << endl;
    return 0;
}