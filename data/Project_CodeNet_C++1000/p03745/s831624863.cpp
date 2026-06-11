#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

int main() {
    ll n; cin >> n;
    vector<ll> a(n); rep(i, n) cin >> a[i];
    ll d = 0, ans = 0;
    rep(i, n-1) {
        if(d==0) {
            if(a[i+1] > a[i]) d = 1;
            else if(a[i+1] < a[i]) d = -1;
            continue;
        }
        else if(d>0) {
            if(a[i+1] >= a[i]) continue;
            d = 0;
            ans++;
        } else {
            if(a[i+1] <= a[i]) continue;
            d = 0;
            ans++;
        }
    }
    cout << ans + 1 << endl;
}