#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

template <class T>
T gcd(T a, T b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

template <typename T>
set<T> factorize(T num) {
  set<T> result;
  T d = 2;
  while (d * d <= num) {
    if (num % d == 0) {
      num /= d;
      result.insert(d);
    } else {
      d++;
    }
  }
  if (num != 1) result.insert(num);
  return result;
}

int main() {
  ll n, k;
  cin >> n >> k;
  V<ll> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());
  if (k > a.back()) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  if (find(a.begin(), a.end(), k) != a.end()) {
    cout << "POSSIBLE" << endl;
    return 0;
  }

  ll d = a[0];
  rep(i, n) d = gcd(d, a[i]);

  auto fs = factorize(d);
  if (d == 1) fs.insert(1);
  auto itr = lower_bound(a.begin(), a.end(), k);
  int j = distance(a.begin(), itr);
  for (int i = j; i < n; i++) {
    for (auto f : fs) {
      if ((a[i] - k) % f == 0) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
