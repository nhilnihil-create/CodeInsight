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

//head

int n;
vi G[N];

unsigned int dfs(int i, int j) {
  unsigned int grundy = 0;
  for(int ne:G[i]) {
    if(ne == j) continue;
    grundy ^= dfs(ne, i)+1;
  }
  return grundy;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  cout << (dfs(0, -1)?"Alice\n":"Bob\n");
}