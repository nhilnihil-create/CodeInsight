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
    ll n, k; cin >> n >> k;
    vector<ll> a(n); cin >> a;
    sort(a.begin(), a.end());
    if(a[n-1] < k){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    ll g = 0;
    rep(i, n){
        if(i == 0) g = a[i];
        else g = gcd(g, a[i]);
    }
    if(k%g == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}