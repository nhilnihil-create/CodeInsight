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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, m; cin >> n >> m;
  vll x(n);
  map<int, int> mp;
  REP(i, n) {
    cin >> x[i];
    mp[x[i]]++;
  }

  map<int, P> mp2;
  for(auto &e: mp) {
    if(e.second % 2) mp2[e.first % m].first++;
    mp2[e.first % m].second += e.second / 2;
  }

  vector<bool> sel(m);
  ll rem = 0;
  for(auto &e: mp2) {
    if(sel[e.first]) continue;
    sel[e.first] = true;
    if(e.first != 0) sel[m - e.first] = true;
    auto p1 = e.second;
    if(2 * e.first % m == 0) {
      while(p1.first > 1) p1.first -= 2;
      while(p1.first > 1 && p1.second > 0) p1.first -= 2;
      rem += p1.first;
    } else {
      auto p2 = mp2[m-e.first];
      while(p1.first > 0 && p2.first > 0) {
        p1.first--;
        p2.first--;
      }
      while(p1.first > 1 && p2.second > 0) {
        p1.first -= 2;
        p2.second--;
      }

      while(p2.first > 1 && p1.second > 0) {
        p2.first -= 2;
        p1.second--;
      }

      rem += p1.first + p2.first;
    }
    //cout << e << " " << rem << endl;
  }
  cout << (n - rem) / 2 << endl;



}






















