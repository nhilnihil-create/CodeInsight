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
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl

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
//const int MOD = 998244353;
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

    int V, E; cin >> V >> E;
    vector<tuple<int, int, ll>> e(E);
    REP(i, E)
    {
        int a, b;
        ll c; cin >> a >> b >> c;
        a--; b--;
        e[i] = mt(a, b, -c);
    }

    vl dist(V, INFL);
    dist[0] = 0;

    REP(i, V)
    {
        REP(j, E)
        {
            int a, b;
            ll c;
            tie(a, b, c) = e[j];
            if(dist[a] == INF) continue;
            if(chmin(dist[b], dist[a] + c) && i == V-1 && b == V-1)
            {
                cout << "inf" << endl;
                return 0;
            }
        }
    }
    cout << -dist[V-1] << endl;
}