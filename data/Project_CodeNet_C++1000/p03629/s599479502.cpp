#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
string A;
int N;

int next(int i, char c) {
  int pos = A.find(c, i);
  return ( (pos != string::npos) ? pos : N );
}

int main() {
  cin >> A;
  N = A.length();
  vector<int> dp(N + 2, INF);
  dp[N] = 1; dp[N + 1] = 0;
  for (int i = N; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) {
      int k = next(i, 'a' + j) + 1;
      dp[i] = min(dp[i], dp[k] + 1);
    }
  }
  string ans;
  int cur = 0;
  while (cur < N + 1) {
    for (int j = 0; j < 26; ++j) {
      int k = next(cur, 'a' + j) + 1;
      if (dp[cur] == dp[k] + 1) {
        cur = k;
        ans += static_cast<char>('a' + j);
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

