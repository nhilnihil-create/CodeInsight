#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, M;
  cin >> N >> M;
  long long x   = N;
  long long y   = M;
  long long ans = 0;
  // Sを使った場合
  if (N < M / 2) {
    ans += N;
    M -= 2 * N;
    N = 0;
  } else {
    ans += M / 2;
    N -= M / 2;
    M = 0;
  }
  // Cのみの組み合わせ
  ans += M / 4;
  cout << ans << endl;
}