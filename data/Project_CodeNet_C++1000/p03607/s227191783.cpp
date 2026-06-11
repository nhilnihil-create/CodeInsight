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
ll n;
cin >> n;
ll a[n];
for (ll i = 0; i < n; i++) cin >> a[i];
map<ll, bool> mp;
for (ll i = 0; i < n;i++){
    if(mp[a[i]]){
        mp[a[i]] = false;
        continue;
    }
    else{
        mp[a[i]] = true;
        continue;
    }
}
ll cnt = 0;
for(auto i:mp)
    if (i.second) cnt++;
cout << cnt << endl;
}