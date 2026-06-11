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
  vector<int> X(N);
  REP(i, N) cin >> X[i];
  vector<int> tmp(100001);
  REP(i, N) tmp[X[i]]++;
  vector<int> cnt(M);
  vector<int> pr(M);
  REP(i, 100001) {
    cnt[i%M] += tmp[i];
    pr[i%M] += tmp[i]/2*2;
  }
  int ans = 0;
  REP(i, M) {
    if(i == M-i || i == 0) {
      ans += cnt[i] / 2;
    } else if(i < M-i){
      int tmp = min(cnt[i], cnt[M-i]);
      ans += tmp;
      cnt[i] -= tmp;
      cnt[M-i] -= tmp;
      if(cnt[i] > 0) ans += min(cnt[i], pr[i])/2;
      else ans += min(cnt[M-i], pr[M-i])/2;
    }
  }
  cout << ans << endl;
}