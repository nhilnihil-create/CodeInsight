#include <bits/stdc++.h>
using namespace std;
#define INF_LL 1000000000000000000LL
#define INF 200000000
//#define MOD 1000000007
#define MOD 10000
#define ll long long
#define all(x) x.begin(), x.end()
#define REP(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
// typedef float double;
// typedef priority_queue prique;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<ll> vl;
typedef vector<vi> matrix;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int sign[2] = {1, -1};
template <class T> bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

ll modpow(ll a, ll b, ll m) {
    if(b == 0)
        return 1;
    ll t = modpow(a, b / 2, m);
    if(b & 1) {
        return (t * t % m) * a % m;
    } else {
        return t * t % m;
    }
}

struct edge {
    int to;
    ll cost;
    edge(int t, ll c) { to = t, cost = c; }
};

bool dp1[5001][5001];
bool dp2[5001][5001];

signed main() {
    int n, k;
    cin >> n >> k;
    vi p(n);
    rep(i, n) cin >> p[i];
    dp1[0][0] = 1;
    dp2[n][0] = 1;
    rep(i, n) rep(j, k + 1) {
        if(j >= p[i]) {
            dp1[i + 1][j] = dp1[i][j - p[i]] | dp1[i][j];
        } else {
            dp1[i + 1][j] = dp1[i][j];
        }
    }
    for(int i = n; i > 0; i--) {
        rep(j, k) {
            if(j >= p[i - 1]) {
                dp2[i - 1][j] = dp2[i][j - p[i - 1]] | dp2[i][j];
            } else {
                dp2[i - 1][j] = dp2[i][j];
            }
        }
    }
    int ans = n;
    rep(i, n) {
        vi a, b;
        rep(j, k + 1) {
            if(dp1[i][j])
                a.push_back(j);
            if(dp2[i + 1][j])
                b.push_back(j);
        }
        for(int x : a) {
            if(x >= k)
                break;
            int y = *(lower_bound(all(b), k - x) - 1);
            if(x + y >= k - p[i]) {
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
