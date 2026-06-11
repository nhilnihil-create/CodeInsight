#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;

ll dp[1010][1010];

int main() {
  ll n,k;
  cin >> n >> k;
  for (int i = 1; i <= k; i++) dp[1][i] = 1;
  ll pre = k;
  ll sum = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = pre - dp[i-1][j];
      sum += dp[i][j];
    }
    pre = sum;
    sum = 0;
  }
  cout << pre << endl;
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/