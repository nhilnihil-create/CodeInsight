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
    ll n,k;
    cin >> n >> k;
    map<ll, ll> bukkit;
    for (ll i = 0; i < n;i++){
        ll a, b;
        cin >> a >> b;
        bukkit[a] += b;
    }
    for(auto i:bukkit){
        k -= i.second;
        if(k<=0){
            cout << i.first << endl;
            break;
        }
    }
}