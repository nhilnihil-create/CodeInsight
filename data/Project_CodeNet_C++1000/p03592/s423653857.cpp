#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, M, K;
  cin >> N >> M >> K;
  for (ll i = 0; i <= N; ++i) {
    for (ll j = 0; j <= M; ++j) {
      ll temp = i * j + (N - i) * (M - j);
      if (temp == K) {
        cout << "Yes" << "\n";
        return 0;
      }
    }
  }
  cout << "No" << "\n";
}
