#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

vector<vector<string>> vs;

int main() {

  int H, W; cin >> H >> W;
  vs.resize(H);
  rep(i, H) vs[i].resize(W);
  rep(i, H) rep(j, W) {
    cin >> vs[i][j];
    if(vs[i][j] == "snuke") {
      cout << char(j + 'A') << i + 1 << endl;
      return 0;
    }
  }
  
  return 0;
}