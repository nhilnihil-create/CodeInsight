#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
const double PI = acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n;
ll a, b, h[100010];

int main() {
    cin >> n >> a >> b;
    rep(i, n) cin >> h[i];

    ll diff = a - b;
    ll ng = -1, ok = 2e9;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;

        ll sum = 0;
        rep(i, n) {
            ll rem = max(h[i] - b * mid, 0ll);
            sum += (rem + diff - 1) / diff;
        }

        if (sum <= mid) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}
