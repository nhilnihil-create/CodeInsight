#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(false), cout << fixed << setprecision(20);
#define int long long
#define gcd __gcd
#define all(x) (x).begin(), (x).end()
template<class T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<class T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}
#define _overload(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(...) _overload(__VA_ARGS__, repi, _rep)(__VA_ARGS__)
#define _rev(i, n) revi(i, n, 0)
#define revi(i, a, b) for(int i = (int)(a - 1); i >= (int)(b); i--)
#define rev(...) _overload(__VA_ARGS__, revi, _rev)(__VA_ARGS__)
#define each(i, n) for(auto&& i: n)
const int INF = 1e18, MOD = 1e9 + 7;
signed main() {
    INCANT;
    int n;
    cin>>n;
    int a[111111], mx = -INF, mn = INF, mxcnt = 0, mncnt = 0;
    rep(i, n) {
        cin>>a[i];
        chmax(mx, a[i]);
        chmin(mn, a[i]);
    }
    if(mx == mn) {
        if(mx == n - 1 || 2 * mx <= n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    } else {
       if(mx - mn > 1) {
            cout<<"No"<<endl;
            return 0;
       }
        rep(i, n) {
            if(a[i] == mx) mxcnt++;
            else mncnt++;
        }
        if(mncnt < mx && 2 * (mx - mncnt) <= mxcnt) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
