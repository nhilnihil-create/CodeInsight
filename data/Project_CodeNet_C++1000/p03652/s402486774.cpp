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
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  REP(i, N) REP(j, M) cin >> A[i][j];
  vector<bool> held(M, true);
  int ans = N;
  REP(k, M) {
    vector<int> num(M);
    REP(i, N) {
      REP(j, M) {
        if(held[A[i][j]-1]) {
          num[A[i][j]-1]++;
          break;
        }
      }
    }
    int max = 0;
    int idx = -1;
    REP(i, M) {
      if(held[i] && num[i] > max) {
        max = num[i];
        idx = i;
      }
    }
    if(max < ans) ans = max;
    held[idx] = false;
  }
  cout << ans << endl;
}