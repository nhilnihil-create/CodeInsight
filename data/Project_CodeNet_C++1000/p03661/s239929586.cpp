#include <bits/stdc++.h>
using namespace std;

using LL = long long;

#define ALL(a) begin((a)), end((a))
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define RFOR(i, a, b) for (int(i) = (a); (i) > (b); (i)--)
#define debug(x) cout << #x << " : " << x << '\n'

const int INF = 1e9;
const LL LINF = 1e16;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  LL ans;
  int N;
  cin >> N;
  vector<LL> a(N);
  vector<LL> sum(N);
  LL acc = 0;
  FOR(i, 0, N) {
    cin >> a[i];
    acc += a[i];
    sum[i] = acc;
  }

  ans = LINF;
  LL temp;
  FOR(i, 0, N - 1) {
    temp = abs(sum[i] - (sum[N - 1] - sum[i]));
    ans = min(ans, temp);
  }

  cout << ans << '\n';

  return 0;
}