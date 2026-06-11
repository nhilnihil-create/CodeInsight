#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 1e18;
    rep(mask,(1 << n)){
        int cnt = 0;
        ll cmp = 0;
        ll b = 0, maxwall = 0;
        vector<ll> c(n);
        rep(i,n) c[i] = a[i];
        rep(i,n){
            if((mask >> i) & 1){
                if(b >= c[i]){
                    cmp += b+1-c[i];
                    c[i] = b+1;
                }
                b = c[i];
                cnt++;
                if(maxwall > c[i]) cnt = -30;
            }
            chmax(maxwall, c[i]);
        }
        if(cnt != k) continue;
        chmin(ans, cmp);
    }
    cout << ans << endl;
    return 0;
}