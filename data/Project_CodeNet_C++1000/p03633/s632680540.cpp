#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> T(N);
  for (int i = 0; i < N; i++) cin >> T[i];
  long long ans = 1;
  for (int i = 0; i < N; i++) {
    ans = ans / __gcd(ans, T[i]) * T[i];
  }
  cout << ans << endl;
}