#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, a, b;
  cin >> n >> a >> b;

  vector<ll> vv(n);
  map<ll, int> cnts;
  for (int i = 0; i < n; ++i) {
    cin >> vv[i];
    cnts[vv[i]]++;
  }

  auto ncr = [&](ll n, ll r) -> ll {
    if (n < r) {
      return 0;
    }

    ll nume = 1, deno = 1;
    for (int i = 0; i < r; ++i) {
      nume *= n - i;
      deno *= r - i;
      ll g = gcd(nume, deno);
      nume /= g;
      deno /= g;
    }

    return nume / deno;
  };

  sort(vv.begin(), vv.end(), greater<ll>());
  vector<ll> psum{0};
  partial_sum(vv.begin(), vv.end(), back_inserter(psum));
  ll s = psum[a];
  ll ans = 0;
  for (int i = a; i <= b; ++i) {
    if (s * i % a != 0) {
      continue;
    }

    ll sum = s * i / a;
    if (sum != psum[i]) {
      continue;
    }

    // 各数が何個含まれるか
    map<ll, int> cnts2;
    for (int j = 0; j < i; ++j) {
      cnts2[vv[j]]++;
    }

    ll ans2 = 1;
    for (auto &p : cnts2) {
      ans2 *= ncr(cnts[p.first], p.second);
    }

    ans += ans2;
  }

  double ds = s, da = a;
  cout << fixed << setprecision(9) << ds / da << '\n';
  cout << ans << '\n';
}