#include <iostream>
using namespace std;
typedef long long ll;
#define MAXN 100000

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int x[MAXN];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  ll ans = 0;
  for (int i = 0; i < n-1; i++) {
    ll walk = 1LL * (x[i+1] - x[i]) * a;
    ans += (walk < b ? walk : b);
  }
  cout << ans << endl;
}