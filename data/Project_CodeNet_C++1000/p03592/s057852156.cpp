#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  string ans = "No";
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (i * (M - j) + (N - i) * j == K) {
        ans = "Yes";
        break;
      }
    }
  }
  cout << ans << endl;
}