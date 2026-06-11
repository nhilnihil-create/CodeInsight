#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
using PL = pair<ll , ll> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007
 
int main(){
    int n, k ;
    cin >> n >> k ;
    vector<ll> a (n) ;
    ll ans = INF ;
    if(k == 1){
        cout << 0 << endl ;
        return 0 ;
    }
    rep(i, n) cin>> a[i] ;
    rep(i, 1 << n){
        int cnt = 0 ;
        rep(j, n){
            if(i >> j & 1){
                cnt++ ;
            }
        }
        if(cnt < k || !(i >> 0 & 1)) {
            continue ;
        }
        ll pos = 0 ;
        ll mx = a[0] ;
        rep(j, n){
            if(j == 0) {
                continue ;
            }
            if(i >> j & 1){
                if(mx >= a[j]){
                    pos += (mx - a[j]) + 1 ;
                    mx++ ;
                }
            }
            mx = max(mx, a[j]) ;
        }
        ans = min(pos, ans) ;
    }
    cout << ans << endl ;
}