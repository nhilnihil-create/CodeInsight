#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define sort_(a) stable_sort(a.begin(), a.end())
#define rsort(a) stable_sort(a.rbegin(), a.rend())
#define sum(a) accumulate(a.begin(), a.end(), 0)
#define join(a, d) accumulate(a.begin() + 1, a.end(), a[0], [](string s, string t) {return s + d + t;})
#define all(a) a.begin(), a.end()
// #define __lcm(a, b) std::__detail::__lcm(a, b)
typedef long long ll;
const long mod = 1e9 + 7;

int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) cin >> A[i];
  array<int, 8> rate{0, 0, 0, 0, 0, 0, 0, 0};
  int max_ = 0;
  for (auto a : A) {
    if (a > 3199) ++max_;
    else if (a > 2799) rate[7] = 1;
    else if (a > 2399) rate[6] = 1;
    else if (a > 1999) rate[5] = 1;
    else if (a > 1599) rate[4] = 1;
    else if (a > 1199) rate[3] = 1;
    else if (a > 799) rate[2] = 1;
    else if (a > 399) rate[1] = 1;
    else rate[0] = 1;
  }
  cout << max(1, sum(rate)) << ' ' << sum(rate) + max_ << endl;
  return 0;
}
