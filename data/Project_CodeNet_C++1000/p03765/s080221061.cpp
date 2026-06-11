#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  string s, t;
  cin >> s >> t;

  int ns = s.length(), nt = t.length();
  vector<int> as(ns + 1, 0), at(nt + 1, 0);
  rep(i, ns) as[i + 1] = as[i] + s[i] - 'A' + 1;
  rep(i, nt) at[i + 1] = at[i] + t[i] - 'A' + 1;

  int q;
  cin >> q;
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, c--;

    cout << ((as[b] - as[a]) % 3 == (at[d] - at[c]) % 3 ? "YES" : "NO") << '\n'; 
  }




  
  return 0;
}