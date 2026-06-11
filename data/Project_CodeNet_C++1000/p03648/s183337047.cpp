#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  constexpr int N = 50;

  int64 k;
  cin >> k;
  vector<int64> xs(N, N - 1);
  for (int i = 0; i < N; i++) {
    xs[i] += k / N;
  }
  int64 r = k % N;
  for (int i = 0; i < N - r; i++) {
    xs[i] -= r;
  }
  for (int i = N - r; i < N; i++) {
    xs[i] += N;
    xs[i] -= r - 1;
  }

  cout << N << endl;
  for (int64 x : xs) {
    cout << x << " ";
  }
  cout << endl;
}