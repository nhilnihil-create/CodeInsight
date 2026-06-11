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
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b) {
    if (c == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;
  }
  rep(i, b) {
    int temp = a * (i + 1) % b;
    if (temp == c) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  solve();
  return 0;
}