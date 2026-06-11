#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
constexpr int sign(int n) { return n < 0 ? -1 : n > 0; }

int main() {
  int N; cin >> N;

  vi A(N);
  rep(i, N)
    cin >> A[i];

  ll ans = 1e18;
  rep(k, 2) {
    ll sum = 0, tmp = 0;
    int SIGN = k*2-1;
    rep(i, N) {
      SIGN *= -1;
      if (sign(sum+A[i]) != SIGN) {
        tmp += abs(SIGN - (sum + A[i]));
        sum = SIGN;
      } else
        sum += A[i];
    }
    if (sum == 0)
      ++tmp;
    ans = min(ans, tmp);
  }
  cout << ans << endl;

  return 0;
}
