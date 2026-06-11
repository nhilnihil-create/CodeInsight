#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
ll n,p;
cin >> n >> p;
map<ll, ll> mp;
for (ll i = 0; i < n;i++){
    ll t;
    cin >> t;
    mp[t % 2]++;
}
if(mp[0]==n){
    if (p == 0) cout << (1LL<<n) << endl;
    else
        cout << 0 << endl;
}
else
    cout << (1LL<<(n-1)) << endl;
}
