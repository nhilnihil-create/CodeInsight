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

vector<long long> enum_divisors(long long N) {
  vector<long long> res;
  for (long long i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      // 重複しないならば i の相方である N/i も push
      if (N / i != i) res.push_back(N / i);
    }
  }
  // 小さい順に並び替える
  sort(res.begin(), res.end());
  return res;
}

int calc_digit(long long N) {
  int res = 0;
  while (N) {
    res++;
    N /= 10;
  }
  return res;
}

int main() {  // TODO
  ll n;
  cin >> n;
  int ans = 1e9;
  for (ll a = 1; a * a <= n; a++) {
    if (n % a == 0) {
      ll b = n / a;
      ans = min(ans, (max(calc_digit(a), calc_digit(b))));
    }
  }
  cout << ans << endl;

  return 0;
}