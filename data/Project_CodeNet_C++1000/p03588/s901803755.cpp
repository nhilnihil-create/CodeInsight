#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef pair<int, int> P;
typedef long long ll;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<P> p(n);
  int a, b;
  rep(i, n) {
    cin >> a >> b;
    p[i] = {a, b};
  }

  sort(p.begin(), p.end());

  cout << p[n-1].second + p[n-1].first << '\n';
  return 0;
}
