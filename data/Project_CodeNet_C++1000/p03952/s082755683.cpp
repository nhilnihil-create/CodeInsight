#include <bits/stdc++.h>
#define INF 100000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;


int main()
{
  ll N, x;
  cin >> N >> x;
  if (x == 1 || x == (2 * N - 1)) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  for (ll i = N - 1; i >= 0; --i) {
    ll temp = x - i;
    if (temp <= 0) {
      temp += 2 * N - 1;
    }
    cout << temp << endl;
  }
  for (ll i = 1; i < N; ++i) {
    ll temp = x + i;
    if (temp > 2 * N - 1) {
      temp -= 2 * N - 1;
    }
    cout << temp << endl;
  }
}
