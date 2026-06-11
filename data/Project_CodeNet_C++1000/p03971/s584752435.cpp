// @prefix atcoder
// @description atcoder template

#include <bits/stdc++.h>
using namespace std;
#define int long long

// typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VP;

// rep
//------------------------------------------
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
#define DEBUG(x) cerr << #x << ": " << x << '\n'
#define DEBUGP(x) cerr << #x << ": " << x.first << " \t" << x.second << '\n'
#define INF (1ll << 60)

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
const int MOD = 1e9 + 7;

int n, a, b;
string s;
signed main() {
  cin >> n >> a >> b >> s;

  int cnt = 0;
  int cntb = 0;
  REP(i, n) {
    char ch = s[i];
    if (ch == 'a') {
      if (a + b > cnt) {
        cnt++;
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else if (ch == 'b') {
      if (a + b > cnt && b > cntb) {
        cnt++;
        cntb++;
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
