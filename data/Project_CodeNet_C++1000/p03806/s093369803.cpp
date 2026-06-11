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

    int N, Ma, Mb; cin >> N >> Ma >> Mb;
    vector<tuple<int, int, int>> d(N);
    REP(i, N)
    {
        int a, b, c; cin >> a >> b >> c;
        d[i] = mt(a, b, c);
    }

    int dp[N+1][401][401];
    REP(i, N+1) REP(j, 401) REP(k, 401) dp[i][j][k] = INF;

    dp[0][0][0] = 0;
    REP(i, N)
    {
        int a, b, c;
        tie(a, b, c) = d[i];
        REP(j, 401)
        {
            REP(k, 401)
            {
                chmin(dp[i+1][j][k], dp[i][j][k]);
                if(j+a < 401 && k+b < 401) chmin(dp[i+1][j+a][k+b], dp[i][j][k] + c);
            }
        }
    }

    int ans = INF;
    REPS(i, 1000)
    {
        if(i*Ma > 400 || i*Mb > 400) break;
        chmin(ans, dp[N][i*Ma][i*Mb]);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}