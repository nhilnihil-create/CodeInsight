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
  int N, x;
  cin >> N >> x;
  if(x == 1 || x == 2*N-1) {
    cout << "No" << endl;
    return 0;
  }
  vector<int> ans(2*N-1);
  ans[N-1] = x;
  ans[N-2] = x+1;
  ans[N] = x-1;
  int now = 1;
  REP(i, 2*N-1) {
    if(i >= N-2 && i <= N) continue;
    if(now == x-1) now = x+2;
    ans[i] = now;
    now++;
  }
  cout << "Yes" << endl;
  REP(i, 2*N-1) cout << ans[i] << "\n";
}