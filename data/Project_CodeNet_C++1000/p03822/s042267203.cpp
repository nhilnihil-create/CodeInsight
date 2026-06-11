#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<int> win[100100];

// 1-indexed
int dp[100100];
int rec(int root) {

  if (dp[root] != -1) return dp[root];

  int child = win[root].size();
  if (child == 0) return dp[root] = 0;

  int mn = 1 << 30, mx = -1, cnt = 0;
  vector<int> d;
  for (auto& des: win[root]) d.push_back(rec(des));
  sort(d.rbegin(), d.rend());
  for (int i = 0; i < d.size(); ++i) d[i] += i + 1;

  int ret = -1;
  for (auto& e: d) if (e > ret) ret = e;

  return dp[root] = ret;

}

signed main() {

  cin >> N;
  for (int i = 2; i <= N; ++i) {
    int A;  cin >> A;
    win[A].push_back(i);
  }

  memset(dp, 0xff, sizeof(dp));

  cout << rec(1) << endl;

  // for (int i = 0; i < 10; ++i) cerr << i << " : " << dp[i] << endl;

}
