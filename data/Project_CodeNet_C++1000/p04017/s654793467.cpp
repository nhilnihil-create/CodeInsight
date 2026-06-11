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
const int INF = 0xccccccc;
const ll LINF = 0xcccccccccccccccLL;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

#define N 100100
#define LOG 20

//head

int n;
int x[N];
int l;
int q;
int a, b;
int dd[LOG][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  rep(i, n) cin >> x[i];
  cin >> l;
  rep(i, n) {
    dd[0][i] = upper_bound(x, x+n, x[i]+l)-x-1;
  }
  rep(j, LOG-1) rep(k, n) {
    int u = dd[j][k];
    dd[j+1][k] = dd[j][u];
  }
  cin >> q;
  while(q--) {
    cin >> a >> b;
    a--; b--;
    if(a > b) swap(a, b);
    int ans = 0;
    for(int i = LOG-1; i >= 0; i--) {
      if(dd[i][a] < b) {
        a = dd[i][a];
        ans += 1<<i;
      }
    }
    cout << ans+1 << '\n';
  }
}