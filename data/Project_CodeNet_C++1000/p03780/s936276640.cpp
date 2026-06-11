#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

bool dp[5001][5001];

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  sort(ALL(a));
  int ok = n, ng = -1;
  while (1 < abs(ok - ng)) {
    int mid = (ok + ng) / 2;
    vector<int> vc;
    REP(i, n) {
      if (i == mid) continue;
      vc.push_back(a[i]);
    }
    REP(i, n + 1) REP(j, k + 1) dp[i][j] = false;
    dp[0][0] = true;
    REP(i, n - 1) REP(j, k + 1) {
      if (dp[i][j]) {
        dp[i + 1][j] = true;
        if (j + vc[i] <= k) {
          dp[i + 1][j + vc[i]] = true;
        }
      }
    }
    bool flag = false;
    for (int i = 0; i < k; ++i) {
      if (k - a[mid] <= i && dp[n - 1][i]) {
        flag = true;
      }
    }
    if (flag) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;
  return 0;
}