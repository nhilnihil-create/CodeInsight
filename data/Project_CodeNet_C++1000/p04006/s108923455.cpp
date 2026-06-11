#include <iostream>

using namespace std;

typedef long long ll;

const ll INF = 1e18 + 5;
const int MAX_N = 2e3 + 5;

int arr [MAX_N];
int prem [MAX_N][MAX_N];

int main () {
  int n;
  ll x;
  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    prem[i][0] = arr[i];
  }

  for (int i = 0; i < n; i++) {
    for (int k = 1; k < n; k++) {
      prem[i][k] = min(prem[i][k - 1], arr[(n + i - k) % n]);
    }
  }

  ll ans = INF;
  for (int k = 0; k < n; k++) {
    ll cur = x * (ll) k;
    for (int i = 0; i < n; i++) {
      cur += prem[i][k];
    }
    ans = min(ans, cur);
  }
  cout << ans << endl;
}
