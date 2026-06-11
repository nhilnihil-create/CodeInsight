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
  lint H, W, N;
  cin >> H >> W >> N;
  map<pair<int, int>, lint> mp;
  REP(i, N) {
    int a, b;
    cin >> a >> b;
    REP(j, 3) {
      if(a <= 0 || a >= H-1) {
        a--; continue;
      }
      int bb = b;
      REP(k, 3) {
        if(bb <= 0 || bb >= W-1) {
          bb--; continue;
        }
        mp[make_pair(a, bb)]++;
        bb--;
      }
      a--;
    }
  }
  vector<lint> ans(10);
  for(auto itr = mp.begin(); itr != mp.end(); itr = next(itr)) {
    ans[itr->second]++;
  }
  ans[0] = (H-2)*(W-2);
  FOR(i, 1, 10) ans[0] -= ans[i];
  REP(i, 10) cout << ans[i] << "\n";
}