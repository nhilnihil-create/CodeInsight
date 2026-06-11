#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, A, B;
  cin >> N >> A >> B;
  vector<long> X(N);
  for (long i = 0; i < N; i++) cin >> X.at(i);
  long tmp = X.at(0);
  for (long i = 0; i < N; i++) X.at(i) -= tmp;
  long ans = 0;
  for (long i = 0; i + 1 < N; i++) {
    if ((X.at(i + 1) - X.at(i)) * A > B) ans += B;
    else ans += (X.at(i + 1) - X.at(i)) * A;
  }
  cout << ans << "\n";
}