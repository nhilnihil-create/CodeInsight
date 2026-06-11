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

int N, M, R;
int r[10];
ll g[210][210];

int main() {
    cin >> N >> M >> R;
    rep(i, R) cin >> r[i];
    rep(i, R) r[i]--;

    rep(i, N) rep(j, N) g[i][j] = LLINF;
    rep(i, N) g[i][i] = 0;
    while (M--) {
        int a, b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        g[a][b] = g[b][a] = c;
    }

    rep(k, N) rep(i, N) rep(j, N) {
        chmin(g[i][j], g[i][k] + g[k][j]);
    }

    vector<int> v(R);
    rep(i, R) v[i] = i;

    ll ans = LLINF;
    do {
        ll sum = 0;
        rep(i, R-1) {
            int from = r[v[i]];
            int to = r[v[i+1]];
            sum += g[from][to];
        }
        chmin(ans, sum);
    } while (next_permutation(all(v)));

    cout << ans << endl;
}
