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
int N;
int bit[200010];
void add(int a, int w) {
  while(a <= N+1) {
    bit[a] += w;
    a += a & -a;
  }
}
int sum(int a) {
  int s = 0;
  while(a > 0) {
    s += bit[a];
    a -= a & -a;
  }
return s;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lint K;
  cin >> N >> K;
  vector<lint> A(N);
  REP(i, N) cin >> A[i];
  REP(i, N) A[i] -= K;
  vector<lint> S(N+1);
  REP(i, N) S[i+1] = S[i] + A[i];
  vector<lint> St(S);
  sort(ALL(St));
  map<lint, lint> mp;
  REP(i, N+1) mp[St[i]] = i+1;
  REP(i, N+1) S[i] = mp[S[i]];
  lint ans = 0;
  REP(i, N+1) {
    ans += (lint)sum(S[i]);
    add(S[i], 1);
  }
  cout << ans << endl;

}