#include <iostream>

#define N 100001
typedef long long int ll;

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  ll a, b;
  ll x[N];
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  ll ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ll dist = x[i + 1] - x[i];
    ans += min(dist * a, b);
  }
  std::cout << ans << std::endl;
  return 0;
}
