#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, K, X, Y;
  cin >> N >> K >> X >> Y;
  ll ans = 0;
  ans += min(N, K) * X;
  ans += max(0ll, N - K) * Y;
  cout << ans << "\n";
}
