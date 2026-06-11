// review
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAXN = 5010;

int n, k;
ll a[MAXN];

void solve() {
  sort(a, a + n);
  ll sum = 0;
  int ans = n;
  for (int i=n-1;i>=0;i--) {
    if (sum + a[i] < k) {
      sum += a[i];
    } else {
      ans = min(ans, i);
    }
  }
  cout << ans << endl;
}

int main() {
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  solve();
}
