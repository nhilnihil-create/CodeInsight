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
  int N;
  cin >> N;
  vector<int> p(N);
  REP(i, N) cin >> p[i];
  vector<int> a(N);
  REP(i, N) a[i] = i*20000+1;
  vector<int> b(N);
  REP(i, N) b[i] = (N-i)*20000+1;
  int last = 0;
  REP(i, N) a[p[i]-1] += i;
  REP(i, N) cout << a[i] << (i!=N-1 ? " " : "");
  cout << "\n";
  REP(i, N) cout << b[i] << (i!=N-1 ? " " : "");
  cout << "\n";

}