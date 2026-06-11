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
  int a, b;
  cin >> a >> b;

  if (a % 3 == 0) cout << "Possible" << endl;
  else if (b % 3 == 0) cout << "Possible" << endl;
  else if ((a + b) % 3 == 0) cout << "Possible" << endl;
  else cout << "Impossible" << endl;


  
  return 0;
}