#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 50;

main() {
  ll K; cin >> K;
  ll a[N];
  for (int i = 0; i < N; i++) {
    a[i] = N - 1;
  }
  ll q = K / N;
  int r = K % N;
  for (int i = 0; i < N; i++) a[i] += q;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < N; j++) {
      if (j == i) {
        a[j] += N;
      } else {
        a[j]--;
      }
    }
  }
  cout << N << endl;
  for (int i = 0; i < N; i++) cout << a[i] << ( (i == N - 1) ? '\n' : ' ' );
}