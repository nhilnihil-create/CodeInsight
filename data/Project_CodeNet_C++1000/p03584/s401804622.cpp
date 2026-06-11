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
ll k, a[100010], b[100010];
vector<ll> cand;

void dfs(ll x, int i, bool smaller) {
    if (i == -1) {
        cand.push_back(x);
        return;
    }
    if (smaller) {
        dfs(x + (1 << i), i-1, true);
    } else {
        if (k & (1 << i)) {
            dfs(x + (1 << i), i-1, false);
            dfs(x, i-1, true);
        } else {
            dfs(x, i-1, false);
        }
    }
}

int main() {
    cin >> n >> k;
    rep(i, n) cin >> a[i] >> b[i];

    dfs(0, 30, false);

    ll ans = -1;
    for (auto &bit: cand) {
        ll tmp = 0;
        rep(i, n) {
            bool ok = true;
            rep(j, 30) {
                if (!(bit & (1 << j)) && (a[i] & (1 << j))) ok = false;
            }
            if (ok) tmp += b[i];
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;
}
