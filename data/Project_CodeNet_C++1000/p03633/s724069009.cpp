#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  ll num, ans = 1;
  rep(i, n) {
    cin >> num;
    ans = lcm(ans, num);
  }
  cout << ans << endl;
  return 0;
}