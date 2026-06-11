#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);
  long ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    A.at(i) += ans;
    if (A.at(i) % B.at(i) == 0) continue;
    ans += B.at(i) - A.at(i) % B.at(i);
  }
  cout << ans << "\n";
}