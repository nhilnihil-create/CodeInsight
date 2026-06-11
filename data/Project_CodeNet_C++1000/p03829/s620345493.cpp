#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  vector<ll> X(N);
  REP(i, N) cin >> X[i];
  ll ans = 0;
  REP(i, N - 1) {
    ll dis = X[i + 1] - X[i];
    if (dis * A > B)
      ans += B;
    else
      ans += dis * A;
  }
  cout << ans << endl;
  return 0;
}