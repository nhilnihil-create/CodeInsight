#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

int calc_digit(int n) {
  int res = 0;
  while (n) {
    n /= 10;
    res++;
  }
  return res;
}

int main() {
  ll N;
  cin >> N;
  int ans = 1e9;
  for (long long a = 1; a * a <= N; a++) {
    if (N % a == 0) {
      ll b = N / a;
      int f = max(calc_digit(a), calc_digit(b));
      ans = min(ans, f);
    }
  }
  cout << ans << endl;

  return 0;
}