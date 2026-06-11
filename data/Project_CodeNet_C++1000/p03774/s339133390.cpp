#include <bits/stdc++.h>
using namespace std;

// エイリアス
using  ll = long signed long;
using ull = long unsigned long;
using  ld = long double;
using   P = pair<int, int>;
using llP = pair<ll, ll>;
using DoP = pair<double, double>;

// 汎用マクロ
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOREACH(i,q) for (auto &i : q)
#define UNIQUE(v) do { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); } while (false)
#define SZ(x) ((int)(x).size())
template <class T>inline bool chmin(T &a, const T b) {if (a > b) { a = b; return true;} return false;}
template <class T>inline bool chmax(T &a, const T b) {if (a < b) { a = b; return true;} return false;}
template <class T>inline void line_out(const vector<T> vec) {int n = SZ(vec); rep(i, n) { cout << vec[i]; if(i < n-1) cout << " ";}cout << endl;}
const int di[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dj[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int di2[] = {1, 1, -1, -1, 0, 1, 2, 2, 2, 2, 2, 1, 0, -1, -2, -2, -2, -2, -2, -1};
const int dj2[] = {1, -1, 1, -1, 2, 2, 2, 1, 0, -1, -2, -2, -2, -2, -2, -1, 0, 1, 2, 2};
const int INF = 1 << 28;
const ll INF64 = 1ll << 55;
const int mod = 1000000007;
//const int mod = 998244353;

int main(){
  int n, m; cin >> n >> m;
  vector<llP> h(n), c(m);
  rep(i, n) cin >> h[i].first >> h[i].second;
  rep(i, m) cin >> c[i].first >> c[i].second;

  rep(i, n) {
    int ans;
    ll dist = INF64;
    rep(j, m) {
      if(chmin(dist, abs(h[i].first-c[j].first)+abs(h[i].second-c[j].second))) ans = j+1;
    }
    cout << ans << endl;
  }
}