//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

const int N = 1e5+10;

//head

int n, m, q;
int num[N];
int col[N];
int v[N], d[N], c[N];
vi G[N];
void dfs(int v, int d, int c) {
  if(num[v] >= d) return;
  if(col[v] == 0) col[v] = c;
  num[v] = d;
  if(d) for(int x:G[v]) {
    dfs(x, d-1, c);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  memset(num, -1, sizeof(num));
  cin >> q;
  rep(i, q) cin >> v[i] >> d[i] >> c[i];
  for(int i = q-1; i >= 0; i--) {
    dfs(v[i]-1, d[i], c[i]);
  }
  rep(i, n) cout << col[i] << '\n';
}