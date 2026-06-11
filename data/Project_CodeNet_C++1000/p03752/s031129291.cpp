#include <bits/stdc++.h>
       
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int first_fixed_size_subset(int n, int k) { return (1 << k) - 1; }
int next_fixed_size_subset(int n, int k, int& s) {
  if (k == 0) return 0;

  int x = s & -s, y = s + x;
  s = (((s & ~y) / x) >> 1) | y;
  if (s >= (1 << n)) return 0;
  return s;
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> a(N);
  for (int i = 0; i < (int)(N); ++i) cin >> a[i];

  ll ans = 1e18;

  int s = first_fixed_size_subset(N, K);
  do {
    ll cost = 0, prev = 0;
    for (int i = 0; i < (int)(N); ++i) {
      if ((s >> i) & 1) {
        ll h = max(a[i], prev + 1);
        cost += h - a[i];
        prev = h;
      } else {
        chmax(prev, a[i]);
      }
    }
    chmin(ans, cost);
  } while (next_fixed_size_subset(N, K, s));

  cout << ans << endl;
  return 0;
}
