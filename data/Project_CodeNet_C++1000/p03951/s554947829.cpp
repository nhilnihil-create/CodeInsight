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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  int ans = n * 2;
  rep(i,n) {
    string ns = s.substr(i);
    string nt = t.substr(0, n - i);
    if (ns == nt) {
      ans -= (n - i);
      break;
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}