#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<ll> a(N);
  for (ll i = 0; i < N; ++i) {
    cin >> a.at(i);
    a.at(i) -= 1;
  }
  ll ans = 0;
  for (ll i = 0; i < N; ++i) {
    if (a.at(a.at(i)) == i) {
      ans += 1;
    }
  }
  cout << ans / 2 << "\n";
}
