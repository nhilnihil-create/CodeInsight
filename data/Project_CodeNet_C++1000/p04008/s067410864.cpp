#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RREP(i, n) for(int i=(int)(n);i>=0;--i)
#define RFOR(i, a, b) for(int i=(int)(a);i>=(int)(b);--i)
#define ALL(a) (a).begin(),(a).end()
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;

const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;

template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if(a < b) {a = b; return true;}
  return false;
}

template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if(a > b) {a = b; return true;}
  return false;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  REP(i, SZ(v)) {
    if(i) os << " ";
    os << v[i];
  }
  return os;
}

vector<P> ord;

void dfs(int now, int prev, int nowd, const vvi &g) {
  ord[now] = {nowd, now};
  for(auto &nxt: g[now]) {
    if(nxt == prev) continue;
    dfs(nxt, now, nowd+1, g);
  }
}

void col(int now, int prev, const vvi &g, vector<bool> &sel) {
  if(sel[now]) return;
  sel[now] = true;
  for(auto &nxt: g[now]) {
    if(nxt == prev) continue;
    col(nxt, now, g, sel);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll n, k; cin >> n >> k;

  vvi g(n);
  vi p(n);
  ll ans = 0;
  REP(i, n) {
    int a; cin >> a;
    a--;
    p[i] = a;
    if(i == 0) {
      ans += a != 0;
      p[i] = 0;
    } else {
      g[a].push_back(i);
    }
  }

  ord.resize(n);
  dfs(0, -1, 0, g);
  sort(ord.rbegin(), ord.rend());

  vector<bool> sel(n);
  sel[0] = true;
  REP(i, n-1) {
    if(ord[i].first <= k) break;
    int now = ord[i].second;
    if(sel[now]) continue;
    int par = now;
    bool ok = false;
    REP(j, k-1) {
      par = p[par];
      if(sel[par]) {
        ok = true;
        break;
      }
    }
    if(!ok && p[par] != 0) {
      ans++;
      col(par, p[par], g, sel);
    }
  }
  cout << ans << endl;


}






















