#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    for(int i = 1; i < n; ++i){
        if(a[i] + a[i-1] > x){
            if(a[i-1] > x){
                ans += a[i];
                a[i] = 0;
                ans += a[i-1] - x;
                a[i-1] = x;
            }
            else{
                ans += a[i] + a[i-1] - x;
                a[i] -= a[i] + a[i-1] - x;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
