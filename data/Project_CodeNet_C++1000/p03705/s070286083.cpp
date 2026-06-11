#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll vmin = (n - 1) * a + b;
  ll vmax = a + (n - 1) * b;
  ll ans = vmax - vmin + 1;
  if (0 <= ans)
    cout << ans << endl;
  else
    cout << 0 << endl;
}
