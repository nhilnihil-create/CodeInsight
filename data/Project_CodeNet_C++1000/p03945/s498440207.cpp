#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  string s;
  cin >> s;
  char c = s[0];
  ll ans = 0;
  for (int i = 1; i < s.size(); i++) {
    if(c!=s[i]){
      ans++;
      c = s[i];
    }
  }
  cout << ans << endl;
}