#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int N;
  ll T;
  cin >> N >> T;
  vector<ll> ts(N);
  for(int i = 0; i < N; ++i) {
    cin >> ts[i];
  }
  ll ans = 0;
  for(int i = 0; i < N - 1; ++i) {
    ans += min(ts[i + 1] - ts[i], T);
  }
  ans += T;
  cout << ans << endl;
  return 0;
}