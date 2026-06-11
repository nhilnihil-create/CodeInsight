#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL<<60;

ll N;
ll a[1111], b[1111];

int main()
{
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }

  ll n = 1;
  ll x = 1, y = 1;
  for (int i = 0; i < N; i++) {
    if (i > 0) {
      n = max((a[i - 1] * n + a[i] - 1) / a[i], (b[i - 1] * n + b[i] - 1) / b[i]);
    }
    x = a[i] * n;
    y = b[i] * n;
  }
  cout << x + y << endl;
  return 0;
}