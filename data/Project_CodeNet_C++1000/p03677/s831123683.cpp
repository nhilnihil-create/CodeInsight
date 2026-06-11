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
const ll LINF = 922337203685477580LL;
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

int n, m;
int a[N];
ll bit1[N], bit2[N];
ll ans;

void add(int i, int x, ll *bit) {
  while(i <= m) {
    bit[i] += x;
    i += i&-i;
  }
}
ll sum(int i, ll *bit) {
  ll res = 0;
  while(i) {
    res += bit[i];
    i &= i-1;
  }
  return res;
}
inline void place(int l, int r, int x) {
  add(l, x, bit1);
  add(r, -x, bit1);
  add(l, -x*(l-1), bit2);
  add(r, x*(l-1), bit2);
}
inline ll get(int i) {
  return sum(i, bit1)*i + sum(i, bit2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  rep(i, n) cin >> a[i];
  rep(i, n-1) {
    if(a[i] > a[i+1]) {
      ans += m;
      place(1, a[i+1]+1, 1);
      place(a[i]+1, m+1, 1);
      add(1, m-a[i]-1, bit2);
      add(a[i+1]+1, a[i]+1-m, bit2);
      add(a[i]+1, -1, bit2);
    }
    else {
      place(a[i]+1, a[i+1]+1, 1);
      add(a[i]+1, -1, bit2);
      add(a[i+1]+1, 1, bit2);
    }
    ans += a[i+1]-a[i];
    //rep(i, m) cout << get(i+1) << (i == m-1?'\n':' ');
  }
  ll ma = 0;
  rep(i, m) chmax(ma, get(i+1));
  //rep(i, m) cout << P(i+1, get(i+1)) << endl;
  cout << ans-ma << endl;
}