#include <bits/stdc++.h>
using namespace std;

int f(int N, int K) {
  if (N == 1) return K;
  return (K - 1) * f(N - 1, K);
}

int main() {
  int N, K;
  cin >> N >> K;
  cout << f(N, K) << endl;
}