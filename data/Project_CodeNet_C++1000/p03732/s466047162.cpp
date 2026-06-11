#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for(int i = 0; i < (n); i++)
#define REPS(i, n)  for(int i = 1; i <= (n); i++)
#define RREP(i, n)  for(int i = (n)-1; i >= 0; i--)
#define RREPS(i, n) for(int i = (n); i > 0; i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define mt make_tuple
#define pb push_back

using ll  = long long;
using pi  = pair<int, int>;
using pl  = pair<ll, ll>;
using vi  = vector<int>;
using vl  = vector<ll>;
using vs  = vector<string>;
using vb  = vector<bool>;
using vvi = vector<vi>;
using vvl = vector<vl>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll  INFL = 1e18;
const double PI = 3.141592653589793;
const double EPS = 1e-9;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, W; cin >> N >> W;
    vl w(N), v(N); REP(i, N) cin >> w[i] >> v[i];

    vector<vvl> dp(101, vvl(301, vl(101, 0)));

    REP(i, N)
    {
        REP(j, 301)
        {
            REP(k, N+1)
            {
                chmax(dp[i+1][j][k], dp[i][j][k]);
                if(j - w[i] + w[0] >= 0 && k <= N-1) chmax(dp[i+1][j][k+1], dp[i][j-w[i]+w[0]][k] + v[i]);
            }
        }
    }

    ll ans = 0;
    REP(j, 301)
    {
        REP(k, N+1)
        {
            if(W >= k*w[0] + j) chmax(ans, dp[N][j][k]);
        }
    }
    cout << ans << endl;
}