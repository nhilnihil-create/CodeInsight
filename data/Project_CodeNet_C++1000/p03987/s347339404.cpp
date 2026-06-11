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
#define INF (ll)(1e18)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    int n;
    cin >> n;
    vector<pii> v(n);
    rep(i, n) { cin >> v[i].F; v[i].S = i; }
    sort(all(v));
    
    set<int> s; // index
    s.insert(-1);
    s.insert(n);
    
    ll ans = 0;
    rep(i, n) {
        auto it = s.upper_bound(v[i].S);
        auto it2 = it;
        --it2;
        ans += (ll)v[i].F * (*it - v[i].S) * (v[i].S - *it2);
        
        s.insert(v[i].S);
        // cout << *it << " " << *it2 << endl;
        // for (auto e : s) cout << e << " "; cout << endl;
    }
    cout << ans << endl;
}
