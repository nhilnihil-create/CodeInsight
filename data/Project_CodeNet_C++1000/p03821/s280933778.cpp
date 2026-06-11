#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<long long> A(N);
  vector<long long> B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    cin >> B.at(i);
  }

  long long ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    A.at(i) += ans;
    if (A.at(i) % B.at(i) == 0) continue;
    ans += B.at(i) - A.at(i) % B.at(i);
  }

  cout << ans << endl;
}