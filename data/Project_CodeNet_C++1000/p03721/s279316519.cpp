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
    vector<pair<ll, ll>> ab(n);
    rep(i, n){
        ll a, b; cin >> a >> b;
        ab[i] = make_pair(a, b);
    }
    sort(ab.begin(), ab.end());
    ll cnt = 0;
    for(auto i : ab){
        cnt += i.second;
        if(k <= cnt){
            cout << i.first << endl;
            break;
        }
    }
    return 0;
}