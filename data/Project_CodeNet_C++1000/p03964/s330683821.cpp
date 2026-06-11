#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll INF = 1e9;
const long long INFL = 1LL<<60;

int main() {
  int n;
  cin >> n;
  ll t = 1;
  ll a = 1;
  rep(i, n) {
    int ti, ai;
    cin >> ti >> ai;
    // 1. (t + a) は (ti + ai) の倍数
    // 2. t / ti = a / ai

    if (t % ti != 0) {
      t = ti * ((t / ti) + 1);
    }

    if (a % ai != 0) {
      a = ai * ((a / ai) + 1);
    }

    if (t / ti > a / ai) {
      a = ai * (t / ti);
    } else if (t / ti < a / ai) {
      t = ti * (a / ai);
    }

    // cerr << ti << ":" << ai << " = " << t << ":" << a << endl;
  }

  cout << t + a << endl;

  return 0;
}
