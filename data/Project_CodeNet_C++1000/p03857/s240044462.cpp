#include <bits/stdc++.h>
typedef long long int ll;
#define FOR(i, a, b) for (ll i = (signed)(a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define EREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define MOD 1000000007
#define pb push_back
#define INF 93193111451418101
#define MIN -93193111451418101
#define EPS 1e-11
#define tp(a, b, c) make_tuple(a, b, c)
#define lb(a, b) lower_bound((a).begin(), (a).end(), (b))
#define ub(a, b) upper_bound((a).begin(), (a).end(), (b))
#define bitcnt(a) (ll) __builtin_popcount((a))
using namespace std;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
template <typename T> void fill_all(T &arr, const T &v) { arr = v; }
template <typename T, typename ARR> void fill_all(ARR &arr, const T &v) {
  for (auto &i : arr) {
    fill_all(i, v);
  }
}
//------------------変数-----------------------//
//-------------------関数----------------------//
ll par[300000], depth[300000];
ll cnt[214514];
void init(ll n) {
  REP(i, n) {
    par[i] = i;
    depth[i] = 0;
  }
  return;
}

ll find(ll x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void merge(ll x, ll y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  }
  if (depth[x] > depth[y]) {
    par[y] = x;
  } else {
    par[x] = y;
    if (depth[x] == depth[y]) {
      depth[y]++;
    }
  }
}

bool same(ll x, ll y) {
  if (find(x) != find(y)) {
    return false;
  }
  return true;
}
//親を知りたいときは必ずfind()を使う！
ll par2[300000], depth2[300000];
void init2(ll n) {
  REP(i, n) {
    par2[i] = i;
    depth2[i] = 0;
  }
  return;
}

ll find2(ll x) {
  if (par2[x] == x) {
    return x;
  } else {
    return par2[x] = find2(par2[x]);
  }
}

void merge2(ll x, ll y) {
  x = find2(x);
  y = find2(y);
  if (x == y) {
    return;
  }
  if (depth2[x] > depth2[y]) {
    par2[y] = x;
  } else {
    par2[x] = y;
    if (depth2[x] == depth2[y]) {
      depth2[y]++;
    }
  }
}

bool same2(ll x, ll y) {
  if (find2(x) != find2(y)) {
    return false;
  }
  return true;
}
bool vis[314514];
bool one[314514];

void check(vector<ll> v) {
  ll center = v[0], c = 0;
  vector<ll> vv;
  REP(i, v.size()) {
    if (same2(center, v[i])) {
      vv.pb(v[i]);
      c++;
    } else {
      cnt[v[i]] = 1;
    }
  }
  REP(i, vv.size()) { cnt[vv[i]] = c; }
  return;
}
int main() {
  ll n, k, l;
  cin >> n >> k >> l;
  init(n);
  init2(n);
  REP(i, k) {
    ll p, q;
    cin >> p >> q;
    p--;
    q--;
    merge(p, q);
  }
  REP(i, l) {
    ll p, q;
    cin >> p >> q;
    p--;
    q--;
    merge2(p, q);
  }
  REP(i, n) {
    find(i);
    find2(i);
  }

  map<P, ll> mp;
  REP(i, n) { mp[P(par[i], par2[i])]++; }
  REP(i, n) {
    if (i)
      cout << " ";
    cout << mp[P(par[i], par2[i])];
  }
  cout << endl;
}
