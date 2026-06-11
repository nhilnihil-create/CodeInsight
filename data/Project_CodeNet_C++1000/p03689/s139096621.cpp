#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;

ll dp[501][501];
void solve() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  ll s = 0;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(i%a == a-1 && j%b == b-1) dp[i][j] = -1e8 - a*b + 1;
      else if(i%a == 0 && j%b == 0) dp[i][j] = 1e8;
      else dp[i][j] = 1;
      s += dp[i][j];
    }
  }
  if(s <= 0) cout << "No\n";
  else {
    cout << "Yes\n";
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        cout << dp[i][j] << " ";
      }
      cout << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}
