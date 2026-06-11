#include <iostream>

using namespace std;

template<class T>
bool chmax(T &a, const T &b) { return b > a && (a = b, 1); }

int x[50];
long long dp[55][55][3000];

int main() {
  int N, A;
  cin >> N >> A;

  for (int i = 0; i < N; ++i) {
    cin >> x[i];
  }

  dp[0][0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    int _x = x[i - 1];
    for (int k = 0; k <= i; ++k) {
      for (int s = 0; s < 3000; ++s) {
        dp[i][k][s] = dp[i - 1][k][s];
        if (_x <= s && k > 0) dp[i][k][s] += dp[i - 1][k - 1][s - _x];
      }
    }
  }

  long long cnt = 0;
  for (int i = 1; i <= N; ++i) {
    cnt += dp[N][i][i * A];
  }

  cout << cnt << endl;
}
