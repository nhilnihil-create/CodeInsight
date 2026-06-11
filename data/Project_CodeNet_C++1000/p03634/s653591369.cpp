#pragma target("avx")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef unordered_map<ll, ll> U_MAP;
typedef priority_queue<ll> pq;
typedef priority_queue<ll, vector<ll>, greater<ll>> rpq;
constexpr ll INF = 1e9, MOD = 1e9 + 7, ohara = 1e6 + 10;
constexpr ll LINF = 1e18;

#define rep(i, n) for (ll(i) = 0; (i) < (int)(n); (i)++)
#define rrep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout << (x) << endl
#define doublecout(a) cout << fixed << setprecision(15) << a << endl;
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

//------ Believe yourself as a genius!!!!!! ------

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
// int dy[]={-1,0,1,-1,1,-1,0,1};int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"), s;
ll n, cnt, ans, a, b, c, d[ohara], tmp, m, h, w, x, y, sum, k, q;
struct edge {
  ll to, cost;
};
vector<edge> g[ohara];

void dijkstra(ll s) {
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
  fill(d, d + n, LINF);
  d[s] = 0;
  que.push(pair<ll, ll>(0LL, s));
  while (!que.empty()) {
    pair<ll, ll> p = que.top();
    que.pop();
    ll v = p.second;
    if (d[v] < p.first) continue;
    rep(i, Size(g[v])) {
      edge e = g[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(pair<ll, ll>(d[e.to], e.to));
      }
    }
  }
}

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  rep(i, n - 1) {
    cin >> a >> b >> c;
    a--;
    b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  cin >> q >> k;
  k--;
  dijkstra(k);
  rep(i, q) {
    cin >> x >> y;
    x--;
    y--;
    Cout(d[x] + d[y]);
  }
  return 0;
}