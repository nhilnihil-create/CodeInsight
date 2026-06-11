#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');

const string YES = "Yes";
const string NO = "No";
void solve(long long N, std::vector<long long> a) {
  ll s4 = 0, s2 = 0, s1 = 0;
  rep(i, N)++(a[i] % 4 == 0 ? s4 : a[i] % 2 == 0 ? s2 : s1);
  cout << (s4 >= s1 || (s4 == s1 - 1 && s2 == 0) ? YES : NO) << endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> a(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  solve(N, std::move(a));
}
