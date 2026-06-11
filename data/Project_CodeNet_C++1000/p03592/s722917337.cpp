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
    ll n, m, k; cin >> n >> m >> k;
    map<ll, ll> list;
    ll first = 0, end = n*m;
    rep(i, n+1){
        ll step = (end - first) / m;
        rep(j, m+1){
            ll tmp = first + step * j;
            list[tmp] = tmp;
        }
        first += m;
        end -= m;
    }
    if(list.count(k) == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}