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
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  rep(i,n/2-1) {
    string s1 = s.substr(0, i+1);
    string s2 = s.substr(i+1, i+1);
    if (s1 == s2) ans = 2 * (i + 1);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}