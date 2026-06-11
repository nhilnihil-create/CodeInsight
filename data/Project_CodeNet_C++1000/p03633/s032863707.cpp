#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  vector<long> T(N);
  for (long i = 0; i < N; i++) cin >> T.at(i);
  long ans = 1;
  for (auto t : T) {
    ans = lcm(ans, t);
  }
  cout << ans << "\n";
}