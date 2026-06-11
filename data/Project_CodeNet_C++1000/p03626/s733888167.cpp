#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define rrep(i, a, n) for (int i = (int)(a); i >= (int)(n); --i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) \
  rep(f, 0, (x.size() - 1)) cerr << x[f] << (f == (x.size() - 1) ? "\n" : " ")
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5 + 5, INF = 5 << 28, MOD = 1e9 + 7;

int N, M, K;
vector<int> A, B;
string S1, S2;

void input() {
  cin >> N;
  int x, y, z;
  cin >> S1 >> S2;
  ;
}

vector<int> v[52 + 5] = {};
void solve() {
  int ans = 1;
  int prv = 0;
  for (int i = 0; i < N;) {  //横に見る
    if (S1[i] == S2[i])      // 縦になってるやつ
    {
      if (prv == 0) {
        ans *= 3;
      } else if (prv == 1) {  //横
        ans *= 2;
      } else {
        ans *= 1;
      }
      prv = 1;
      i += 1;
    } else {  // tate
      if (prv == 0) {
        ans *= 6;
      } else if (prv == 1) {
        ans *= 2;
      } else {
        ans *= 3;
      }
      prv = 2;
      i += 2;
    }
    ans %= MOD;
  }
  cout << ans << endl;

  ;
  ;
}
signed main() {
  input();
  solve();
  return 0;
}