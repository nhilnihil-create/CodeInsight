#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
//#pragma GCC optimize("Ofast")
//#define _GLIBCXX_DEBUG
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
//#define int ll
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define irep(it, stl) for(auto it = stl.begin(); it != stl.end(); it++)
#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define mp(p,q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define floatprec(dig) fixed << setprecision(dig)
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int;
#define invar(typ, var) typ var; cin >> var;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);}};
const int INF = INT_MAX / 2;
const ll LLINF = 1LL<<60;
constexpr ll MOD = 1000000007;
const double EPS = 1e-9;

struct edge { ll from; ll to; ll cost; };

void dfs(vector<vector<edge>>& edges, vll& dist, ll ck, unordered_set<ll>& seen, ll cdist) {
  dist[ck] = cdist;
  for(auto ed : edges[ck]) {
    if(seen.find(ed.to) == seen.end()) {
      seen.emplace(ed.to);
      dfs(edges, dist, ed.to, seen, cdist + ed.cost);
    }
  }
}

signed main(void) {
  cin.tie(0); ios::sync_with_stdio(false);
  
  ll N;
  cin >> N;
  
  vector<vector<edge>> edges(N, vector<edge>());
  
  rep(i, N-1) {
    ll a; ll b; ll c;
    cin >> a >> b >> c;
    a--; b--;
    edges[a].push_back({a, b, c});
    edges[b].push_back({b, a, c});
  }
  
  ll Q; ll K;
  cin >> Q >> K;
  
  K--;
  //前計算
  vector<ll> dist(N);
  unordered_set<ll> seen;
  seen.emplace(K);
  dfs(edges, dist, K, seen, 0);
  
  rep(i, Q) {
    ll x; ll y;
    cin >> x >> y;
    x--; y--;
    ll r = dist[x] + dist[y];
    fin(r);
  }
}