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
  vector<lint> a(N);
  REP(i, N) cin >> a[i];
  map<lint, lint> minidx;
  map<lint, lint> cnt;
  minidx[0] = 0;
  cnt[0] = 0;
  REP(i, N) {
    if(minidx.find(a[i]) == minidx.end()) {
      minidx[a[i]] = i;
      cnt[a[i]] = 1;
    } else {
      cnt[a[i]]++;
    }
  }
  vector<lint> ans(N);
  auto itr = prev(minidx.end());
  lint idx = INF;
  lint cntsum = 0;
  lint lastkey = -1;
  while(true) {
    lint key = itr->first;
    if(lastkey != -1) ans[idx] += (lastkey-key) * cntsum;
    if(itr == minidx.begin()) break;
    cntsum += cnt[key];
    if(itr->second < idx) idx = itr->second;
    lastkey = key;
    itr = prev(itr);
  }
  REP(i, N) cout << ans[i] << "\n";
}