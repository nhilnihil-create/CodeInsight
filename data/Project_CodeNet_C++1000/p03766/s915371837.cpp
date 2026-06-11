#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int add(int x,int y) {
  return x + y >= mod ? x + y - mod : x + y;
}

inline int mul(int x,int y) {
  return (ll) x * y % mod;
}

int n,dp[N],pre[N + N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  pre[0] = 1;
  for (int i = 1 ; i <= N ; i++)
    pre[i] = pre[i - 1] + 1;
  dp[1] = n;
  pre[N + 1] = add(n,pre[N]);
  for (int i = 2 ; i <= n ; i++) {
    dp[i] = add(dp[i],dp[i - 1]);
    dp[i] = add(dp[i],mul(n - 1,n - 1));
    dp[i] = add(dp[i],add(pre[i - 3 + N],mod - pre[i - n - 2 + N]));
    pre[i + N] = add(pre[i + N - 1],dp[i]);
  }
  cout << dp[n] << endl;
}