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

bool ok = true;
int r = -1;

int sch(int now, int prev, const vvi &g, const vi &a, const vi &d) {
  if(d[now] == 1 && now != r) {
    return a[now];
  }
  int su = 0;
  vi tmp;
  for(auto nxt: g[now]) {
    if(nxt == prev) continue;
    tmp.push_back(sch(nxt, now, g, a, d));
    su += tmp.back();
  }
  //cout << "now:" << now << endl;
  //cout << "su:" << su << endl;
  if(now == r) {
    ok &= su == a[r];
    return 0;
  }
  int res = 2*a[now] - su;
  //cout << tmp << " " << res << endl;

  if(res < 0) ok = false;

  su += res;

  ok &= su % 2 == 0;

  REP(i, SZ(tmp)) {
    if(tmp[i] > su/2) {
      ok = false;
      break;
    }
  }
  if(res > su/2) {
    ok = false;
  }

  //cout << now << ":" << res << endl;

  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n; cin >> n;
  vi a(n);
  REP(i, n) {
    cin >> a[i];
  }

  vvi g(n);
  vi d(n);
  REP(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
    d[u]++;
    d[v]++;
  }

  REP(i, n) {
    if(d[i] == 1) {
      r = i;
      break;
    }
  }

  //cout << r << endl;
  int res = sch(r, -1, g, a, d);
  //cout << res << endl;

  cout << (ok ? "YES" : "NO") << endl;

}






















