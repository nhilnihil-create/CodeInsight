/*
  Contest 065
  C - Reconciled?
  Rakesh Kumar --> 01/09/2020
 */

#include <bits/stdc++.h>

using ll = long long int;
const ll M = (1e9 + 7);

inline ll fact(ll n) {
    ll r = 1;
    for (ll i = 2; i <= n; ++i)
        r = (r * i) % M;
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    ll n = 0, m = 0;
    std::cin >> n >> m;
    if (std::abs(n - m) <= 1) {
        ll result = fact(n);
        result = (result * fact(m)) % M;
        if (n == m)
            result = (result << 1) % M;
        std::cout << result << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }


    return 0;
}
