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
  vector<lint> a(N);
  REP(i, N) cin >> a[i];
  vector<lint> idx(N);
  REP(i, N) idx[a[i]-1] = i;
  lint ans = 0;
  set<lint> st;
  REP(i, N) {
    lint tmpl = 0, tmpr = 0;
    auto itr = st.lower_bound(idx[i]);
    if(itr == st.end()) {
      tmpr = N - idx[i];
    } else {
      tmpr = *itr - idx[i];
    }
    if(itr == st.begin()) {
      tmpl = idx[i] + 1;
    } else {
      itr = prev(itr, 1);
      tmpl = idx[i] - *itr;
    }
    st.insert(idx[i]);
    ans += tmpl * tmpr * (i+1);
  }
  cout << ans << endl;
}