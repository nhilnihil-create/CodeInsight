#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  string S; cin >> S;
  long long cnt[26];
  REP(i, 26) cnt[i] = 0;
  REP(i, S.size()) cnt[(int)(S[i] - 'a')]++;

  long long ans = 1 + S.size() * (S.size() - 1) / 2;
  REP(i, 26) ans -= cnt[i] * (cnt[i] - 1) / 2;
  cout << ans << endl;
  return 0;
}