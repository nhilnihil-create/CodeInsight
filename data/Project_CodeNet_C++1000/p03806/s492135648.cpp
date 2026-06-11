#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 1e9;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N);
  REP(i, N) cin >> A[i] >> B[i] >> C[i];
  vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(401, vector<int>(401, INF)));
  dp[0][0][0] = 0;
  REP(i, N) REP(j, 401) REP(k, 401) {
    dp[i+1][j][k] = dp[i][j][k];
    if(j-A[i] >= 0 && k-B[i] >= 0) dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j-A[i]][k-B[i]] + C[i]);
  }
  int ans = INF;
  int Mat = Ma;
  int Mbt = Mb;
  while(Mat <= 400 && Mbt <= 400) {
    ans = min(ans, dp[N][Mat][Mbt]);
    Mat += Ma; Mbt += Mb;
  }
  cout << (ans == INF ? -1 : ans) << endl;
}