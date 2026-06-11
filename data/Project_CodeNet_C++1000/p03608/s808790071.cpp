#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}
const ll INF = 1LL<<60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, R;
    cin >> n >> m >> R;

    vvll d(n, vll(n, INF));
    rep(i, n) d[i][i] = 0;

    vi r(R);
    rep(i, R) {
        cin >> r[i];
        r[i]--;
    }
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
    } 
    rep(k, n) rep(i, n) rep(j, n) chmin(d[i][j], d[i][k] + d[k][j]);
    ll ans = INF;
    sort(all(r));
    do {
        ll now = 0;
        rep(i, R-1) {
            now += d[r[i]][r[i+1]];
        } 
        chmin(ans, now);
    } while (next_permutation(all(r)));
    cout << ans << endl;
}