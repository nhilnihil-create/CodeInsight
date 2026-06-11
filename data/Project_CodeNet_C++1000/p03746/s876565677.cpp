#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
#define inputv(v, n)                                                           \
    vl v;                                                                      \
    rep(i, n) {                                                                \
        ll x;                                                                  \
        cin >> x;                                                              \
        v.push_back(x);                                                        \
    }
bool chmin(ll& a, ll& b) { if (b < a) { a = b; return 1; } return 0; }
bool chmax(ll& a, ll& b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
vl A, B;
struct Gragh {
    ll N;
    vector<vl> G;
    vl visited;

    Gragh(ll n) {
        N = n;
        G.resize(N);
        resetv();
    }

    void add(ll a, ll b) { G[a].push_back(b); }

    void resetv(void) { visited = vl(N, 0); }

    //重さ無し
    void dfs1(ll x) {
        visited[x] = 1;
        for (ll i : G[x]) {
            if (visited[i] == 0) {
                dfs1(i);
                A.push_back(i);
                break;
            }
        }
    }

    //重さ無し
    void dfs2(ll x) {
        visited[x] = 1;
        for (ll i : G[x]) {
            if (visited[i] == 0) {
                dfs2(i);
                B.push_back(i);
                break;
            }
        }
    }
};
int main() {
    cin >> n >> m;
    Gragh G(n);
    rep(i, m) {
        cin >> a >> b;
        a--;
        b--;
        G.add(a, b);
        G.add(b, a);
    }

    G.dfs1(0);
    G.dfs2(0);
    reverse(all(B));
    cout << A.size() + B.size() + 1 << endl;
    rep(i, A.size()) {
        cout << A[i] + 1 << " ";
    }
    cout << 1 << " ";
    rep(i, B.size()) {
        cout << B[i] + 1 << " ";
    }

}
