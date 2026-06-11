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
    ll h, w, n;
    cin >> h >> w >> n;
    ll grid[h * w];
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll sum = 0;
    for (ll i = 0; i < n;i++) {
        for (ll j = 0; j < a[i];j++){
            grid[sum] = i + 1;
            sum++;
        }
    }
    for (ll i = 0; i < h;i++){
        for (ll j = 0; j < w;j++){
            if(i%2==0){
                cout << grid[i * w + j] << " ";
            }
            else{
                cout << grid[(i+1) * w - j-1] << " ";
            }
        }
        cout << endl;
    }
}