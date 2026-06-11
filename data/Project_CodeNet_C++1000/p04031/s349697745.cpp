#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

int main() {
  int N, sum, ans = 10e8;
  cin >> N;
  vector<int> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  rep(i, -100, 101) {
    sum = 0;
    rep(j, 0, N) {
      if (i != v[j]) {
        sum += (i - v[j]) * (i - v[j]);
      }
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
  getchar();
}