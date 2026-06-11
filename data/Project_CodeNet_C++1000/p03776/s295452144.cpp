#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr lint MOD = 1000000007;
constexpr int INF = 2147483647;
constexpr double EPS = 1e-6;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, A, B;
  cin >> N >> A >> B;
  vector<lint> v(N);
  REP(i, N) cin >> v[i];
  sort(ALL(v), greater<lint>());
  lint sum = 0;
  REP(i, A) sum += v[i];
  double mean = (double)sum/(double)A;
  cout << fixed << setprecision(10) << mean << "\n";

  lint ans = 0;
  lint ncr[51][51];
  REP(i, 51) REP(j, i+1) {
    if(j == 0 || j == i) ncr[i][j] = 1;
    else ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j]; 
  }
  lint cnt1 = 0;
  REP(i, N) if(v[A-1] == v[i]) cnt1++;
  FOR(k, A, B+1) {
    if(k != A && v[k-1] != v[0]) break;
    lint cnt2 = 0;
    REP(i, k) if(v[A-1] == v[i]) cnt2++;
    ans += ncr[cnt1][cnt2];
  }
  
  cout << ans << "\n";

}