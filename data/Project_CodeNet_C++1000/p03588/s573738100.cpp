#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  int n;
  cin >> n;
  vector<P> ab(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    ab[i] = P(a, b);
  }

  sort(ab.begin(), ab.end());
  int ans = ab[0].first;
  for (int i = 1; i < n; ++i) {
    ans++;
    int order_diff = ab[i].first - ab[i - 1].first - 1;
    int value_diff = ab[i - 1].second - ab[i].second - 1;
    ans += min(order_diff, value_diff);
  }
  ans += ab.back().second;
  cout << ans << '\n';
  return 0;
}
