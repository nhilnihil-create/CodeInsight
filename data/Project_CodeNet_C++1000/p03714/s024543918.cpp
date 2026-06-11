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
  int n;
  cin >> n;
  vector<ll> a(3 * n);
  rep(i, 3 * n) cin >> a[i];

  vector<ll> ans(n + 1, 0);

  priority_queue<ll, vector<ll>, greater<ll>> l;
  ll suml = 0;
  rep(i, n) {
    l.push(a[i]);
    suml += a[i];
  }
  ans[0] += suml;
  rep(i, n) {
    l.push(a[n + i]);
    suml += a[n + i] - l.top();
    ans[i + 1] += suml;
    l.pop();
  }

  priority_queue<ll> r;
  ll sumr = 0;
  repr(i, n - 1) {
    r.push(a[2 * n + i]);
    sumr += a[2 * n + i];
  }
  ans[n] -= sumr;
  repr(i, n - 1) {
    r.push(a[n + i]);
    sumr += a[n + i] - r.top();
    ans[i] -= sumr;
    r.pop();
  }
  
  cout << *max_element(ans.begin(), ans.end()) << endl;


  
  return 0;
}