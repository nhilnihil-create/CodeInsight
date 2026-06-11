/*
  Contest 065
  C - Reconciled?
  Rakesh Kumar --> 01/09/2020
 */

#include <bits/stdc++.h>

using ll = long long int;

ll f (ll n) {
    ll r = 1;
    for (ll i = 2; i <= n; ++i)
        r = (r * i) % static_cast<ll>((1e9 + 7));
    return r;
}

/*
  combinations maths questions.
  for example
  D --> dog, M --> Monkey
  if abs(D - M) == 0
  let's D = M = 2
  can be 2 combinations where DMDM or MDMD therefore (D! * M!) * 2
  if abs(D - M) = 1
  DMD, MDM so D! * M!
  else abs(D - M) > 1
  0, because dog and monkey can't stand each other
 */

const ll M = (1e9 + 7);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    ll n = 0, m = 0;
    std::cin >> n >> m;
    if (std::abs(n - m) <= 1) {
        ll result = 1;
        for (int i = 1; i <= n; ++i)
            result = (result * i) % M;
        for (int i = 1; i <= m; ++i)
            result = (result * i) % M;
        if (n == m)
            result = (result << 1) % M;
        std::cout << result << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }


    return 0;
}
