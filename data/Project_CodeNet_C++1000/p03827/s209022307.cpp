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
  string s;
  cin >> n >> s;
  int ans = 0;
  int cnt = 0;
  rep(i,n) {
    if (s[i] == 'D') cnt = cnt-1;
    else cnt++;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}