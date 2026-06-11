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
  lint n, m;
  cin >> n >> m;
  vector<lint> x(n);
  REP(i, n) cin >> x[i];
  vector<lint> y(m);
  REP(i, m) cin >> y[i];
  lint xsum = 0;
  REP(i, n-1) xsum = (xsum + (x[i+1] - x[i]) * (i+1) % MOD * (n-1-i) % MOD) % MOD;
  lint ysum = 0;
  REP(i, m-1) ysum = (ysum + (y[i+1] - y[i]) * (i+1) % MOD * (m-1-i) % MOD) % MOD;
  cout << xsum * ysum % MOD << endl;
}