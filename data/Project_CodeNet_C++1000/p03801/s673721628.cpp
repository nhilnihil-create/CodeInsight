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
#define int ll
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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n; cin >> n;
  vi a(n);
  REP(i, n) cin >> a[i];

  map<int, P> mp;
  RREP(i, n-1) {
    mp[a[i]].first++;
    mp[a[i]].second = i;
  }

  vector<pair<int, P>> v;
  for(auto &e: mp) {
    v.push_back({e.first, e.second});
  }
  sort(v.rbegin(), v.rend());
  v.push_back({0, {0, 0}});
  int sz = SZ(v);

  vi cnt(n);
  REP(i, sz-1) {
    cnt[v[i].second.second] += v[i].second.first * (v[i].first - v[i+1].first);
    v[i+1].second.first += v[i].second.first;
    chmin(v[i+1].second.second, v[i].second.second);
  }

  REP(i, n) {
    cout << cnt[i] << endl;
  }

}






















