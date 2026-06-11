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
  cout << (expr ? "YES" : "NO") << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string S, T;
  cin >> S >> T;
  vector<int> SS(S.size()+1);
  REP(i, S.size()) SS[i+1] = SS[i] + (S[i]=='A' ? 1 : -1);
  vector<int> TT(T.size()+1);
  REP(i, T.size()) TT[i+1] = TT[i] + (T[i]=='A' ? 1 : -1);
  int Q;
  cin >> Q;
  REP(q, Q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    yes((SS[b]-SS[a-1] + 300000)%3 == (TT[d]-TT[c-1] + 300000)%3);
  }
}