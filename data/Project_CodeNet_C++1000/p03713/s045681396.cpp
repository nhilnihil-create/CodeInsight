#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
// template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }


ll solve(ll h, ll w) {
    ll ans = 1e18;
    rep3(i, 1, h) {
        // cout << i << endl;
        ll A[3];
        A[0] = i * w;
        A[1] = (h - i) / 2 * w;
        A[2] = ((h - i) / 2 + ((h - i) % 2 ? 1 : 0)) * w;
        // rep(i, 3) cout << A[i] << " "; cout << endl;
        chmin(ans, max({A[0], A[1], A[2]}) - min({A[0], A[1], A[2]}));
        
        A[1] = (h - i) * (w / 2);
        A[2] = (h - i) * (w / 2 + (w % 2 ? 1 : 0));
        // rep(i, 3) cout << A[i] << " "; cout << endl;
        chmin(ans, max({A[0], A[1], A[2]}) - min({A[0], A[1], A[2]}));
        
        
    }
    return ans;
}
int main() {
    ll h, w;
    cin >> h >> w;
    
    cout << min(solve(h, w), solve(w, h)) << endl;
}
