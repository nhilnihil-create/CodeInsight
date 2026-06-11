#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const ll MAX_N = (ll)(5000 + 5);
const ll MAX_K = (ll)(5000 + 5);

ll n, k;
ll a[MAX_N];
ll aexclude[MAX_N];

bool dp[5000 + 5];

ll ans = 0;

bool makeable(ll exc) {
  for (ll j = 0; j < k; ++j) dp[j] = false;

  dp[0] = true;

  /*
  cout << a[exc] << endl;
  for (ll i = 0; i < k; ++i) {
    printf("%2lld ", i);
  }
  cout << endl;
  */

  for (ll i = 0; i < n; ++i) {
    if (i == exc) continue;
    for (ll j = k - 1; j >= 0; --j) {
      if (j - a[i] >= 0 && dp[j - a[i]]) dp[j] = true;
    }

    /*
    for (ll i = 0; i < k; ++i) {
      printf("%2lld ", dp[i]);
    }
    cout << endl;
    */
  }

  ll left = max((ll)(0), k - a[exc]);

  /*
  cout << a[exclude] << endl;
  for (ll i = 0; i < k; ++i) {
    printf("%2lld ", i);
  }
  cout << endl;

  for (ll i = 0; i < k; ++i) {
    printf("%2lld ", dp[i]);
  }
  cout << endl;
  cout << endl;
  */

  for (ll i = left; i < k; ++i) {
    if (dp[i]) {
      // cout << a[exclude] << "_" << i << endl;
      return true;
    }
  }

  return false;
}

int main(void) {
  // Here your code !
  scanf("%lld %lld", &n, &k);

  for (ll i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  sort(a, a + n);

  /*
  for (int i = 0; i < n; ++i) {
    if (!makeable(i)) ans += 1;
  }
  */

  ll l = 0;
  ll r = n;

  if (makeable(0)) {
    ans = 0;
    printf("%lld\n", ans);
    return 0;
  }

  while (abs(l - r) > 1) {
    // cout << l << "_" << r << endl;

    ll mid = (l + r) / 2;

    if (makeable(mid)) {
      r = mid;
    }
    else l = mid;
  }

  ans = l + 1;

  // cout << l << endl;

  printf("%lld\n", ans);

	return 0;
}