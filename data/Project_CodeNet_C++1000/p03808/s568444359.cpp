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
  lint N;
  cin >> N;
  vector<lint> A(N);
  REP(i, N) cin >> A[i];
  lint Asum = 0;
  REP(i, N) Asum += A[i];
  if(Asum % (N*(N+1)/2) != 0) {
    cout << "NO" << endl;
    return 0;
  }
  lint cnt = Asum / (N*(N+1)/2);
  REP(i, N) {
    lint diff = A[i] - A[(i+1)%N] + cnt;
    if(diff < 0 || diff%N != 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}