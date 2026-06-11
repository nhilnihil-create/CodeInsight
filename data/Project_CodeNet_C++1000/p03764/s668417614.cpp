#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

i64 MOD = 1e9 + 7;

i64 solve(const vector<i64>& a) {
  i64 ans = 0;
  for(int i = 0;i < a.size();i++) {
    i64 x = a[i] % MOD;
    ans += x * (1 + i) % MOD * (a.size() - i) % MOD;
    ans %= MOD;
  }
  return ans;
}

int main() {
  vector<i64> xs;
  vector<i64> ys;
  int n, m;
  cin >> n >> m;
  vector<i64> x(n), y(m);
  for(int i = 0;i < n;i++) cin >> x[i];
  for(int i = 0;i < m;i++) cin >> y[i];
  for(int i = 1;i < n;i++) xs.push_back(x[i] - x[i - 1]);
  for(int i = 1;i < m;i++) ys.push_back(y[i] - y[i - 1]);
  cout << solve(xs) * solve(ys) % MOD << endl;
}
