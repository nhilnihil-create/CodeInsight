#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, A, B;
  cin >> N >> A >> B;
  vector<long> X(N);
  for (long i = 0; i < N; i++) cin >> X.at(i);
  long ans = 0;
  for (long i = 0; i + 1 < N; i++) {
    long tmp = X.at(i + 1) - X.at(i);
    tmp *= A;
    ans += min(tmp, B);
  }
  cout << ans << "\n";
}