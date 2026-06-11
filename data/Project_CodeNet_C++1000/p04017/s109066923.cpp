#include <bits/stdc++.h>
using namespace std;

int N, L, Q;
int X[100005];

int dp[31][100005]; // dp[d][s] maximum travel given 2^d days and starting from s

int trial(int a, int x) { // maximum hotel starting from a with x days of travel
  int cur = a;
  for (int i = 30; i >= 0; i--) {
    if (x & (1 << i)) {
      cur = dp[i][cur];
    }
  }
  return cur;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> X[i];
  }
  cin >> L >> Q;

  for (int i = 1; i <= N; i++) {
    dp[0][i] = upper_bound(X + 1, X + N + 1, X[i] + L) - X - 1;
  }

  for (int j = 1; j < 31; j++) {
    for (int i = 1; i <= N; i++) {
      dp[j][i] = dp[j - 1][dp[j - 1][i]]; 
    }
  }

  for (int qi = 0; qi < Q; qi++) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
    }
    if (a == b) {
      cout << 0 << "\n";
      continue;
    }

    int lo = 1, hi = N;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (trial(a, mid) >= b) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }

    cout << hi << "\n";
  } 

}
