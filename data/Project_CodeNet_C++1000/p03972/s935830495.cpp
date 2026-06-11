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
  lint W, H;
  cin >> W >> H;
  vector<lint> p(W);
  REP(i, W) cin >> p[i];
  vector<lint> q(H);
  REP(i, H) cin >> q[i];
  vector<P> s;
  REP(i, W) s.push_back(make_pair(p[i], 0));
  REP(i, H) s.push_back(make_pair(q[i], 1));
  sort(ALL(s), [](auto const &a, auto const &b) { return a.first < b.first; });
  lint ans = 0;
  lint zeros = 0;
  lint ones = 0;
  REP(i, W+H) {
    if(s[i].second == 0) {
      ans += s[i].first * (H-ones + 1);
      zeros++;
    } else {
      ans += s[i].first * (W-zeros + 1);
      ones++;
    }
  }
  cout << ans << endl;
}