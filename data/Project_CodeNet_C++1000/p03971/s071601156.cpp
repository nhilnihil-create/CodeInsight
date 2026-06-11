#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  int cntA = 0;
  int cntB = 0;
  vector<int> ans(n);
  rep(i,n) {
    if (s[i] == 'c') ans[i] = 0;
    else if (s[i] == 'a') {
      if (cntA + cntB < a + b) {
        cntA++;
        ans[i] = 1;
      } else ans[i] = 0;
    } else {
      if ((cntA + cntB < a + b) && cntB + 1 <= b) {
        cntB++;
        ans[i] = 1;
      } else ans[i] = false;
    }
  }
  rep(i,n) cout << (ans[i]? "Yes": "No") << endl;
}

int main() {
  solve();
  return 0;
}