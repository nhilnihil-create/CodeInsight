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
    ll n; cin >> n;
    vector<ll> a(n); cin >> a;
    sort(a.begin(), a.end());
    vector<ll> as(n, 0);
    rep(i, n){
        if(i > 0) as[i] += as[i-1] + a[i];
        else as[i] += a[i];
    }
    vector<ll> ab(n, false);
    ab[n-1] = true;
    rep(i, n){
        if(i == n-1) continue;
        if(as[i]*2 >= a[i+1]) ab[i] = true;
    }
    ll cnt = 0;
    for(ll i = n-1; i >= 0; --i){
        if(!ab[i]) break;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}