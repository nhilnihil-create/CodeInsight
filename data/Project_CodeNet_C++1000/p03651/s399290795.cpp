#include <bits/stdc++.h>

using namespace std;

template <typename T>
T gcd(T a, T b) {
  while (a) {
    b %= a;
    std::swap(a, b);
  }
  return b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int g = 0;
  for (int a : A) {
    g = gcd(g, a);
  }
  for (int a : A) {
    if (a < K) continue;
    if ((a - K) % g == 0) {
      cout << "POSSIBLE" << '\n';
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << '\n';
  return 0;
}
