#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    ll n,k; cin >> n >> k;
    multimap<ll,ll> p;
    for(int i = 0;i < n;i++){
        ll x,y; cin >> x >> y;
        p.insert(make_pair(x,y));
    }
    ll total = 0;
    for(auto a:p){
        total += a.second;
        if(total >= k){
            cout << (ll)a.first;
            break;
        }
    }
}

