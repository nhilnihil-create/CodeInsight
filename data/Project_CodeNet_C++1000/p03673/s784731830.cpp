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
for (ll i = 0; i < n;i++){
    cin >> a[i];
}
deque<ll> ans;
for (ll i = 0; i < n; i++) {
    if(i%2==0){
        ans.push_back(a[i]);
    }
    else{
        ans.push_front(a[i]);
    }
}
if(n%2==0){
    for (ll i = 0; i < n;i++){
        cout << ans[i] << " ";
    }
}
else{
    for (ll i = 0; i < n;i++){
        cout << ans[n-1-i] << " ";
    }
}
}