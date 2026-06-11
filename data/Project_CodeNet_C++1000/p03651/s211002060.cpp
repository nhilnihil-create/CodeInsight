#include <bits/stdc++.h>
#define INF 100000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, K;
  cin >> N >> K;
  ll gcd;
  ll M = 0;
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    if (a > M) {
      M = a;
    }
    if (i == 0) {
      gcd = a;
    }
    else {
      gcd = __gcd(gcd, a);
    }
  }
  if (K % gcd == 0 && M >= K) {
    cout << "POSSIBLE" << endl;
  }
  else {
    cout << "IMPOSSIBLE" << endl;
  }
}
