#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1e18;
const long double EPS = 1e-10;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  bool flag = false;
  if (n & 1) flag = true;
  bool same = false;
  if (s[0] == s[n - 1]) same = true;

  cout << ((flag ^ same) ? "First" : "Second") << endl;
  


  
  return 0;
}