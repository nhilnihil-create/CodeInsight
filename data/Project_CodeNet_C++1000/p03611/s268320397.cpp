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
  vector<int> v(100001);
  int n;
  cin >> n;
  rep(i,n) {
    int a;
    cin >> a;
    for(int i = -1; i <= 1; i++) {
      if (a + i < 0 || 100000 < a + i) continue;
      v[a + i]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= 100000; i++) {
    ans = max(ans, v[i]);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}