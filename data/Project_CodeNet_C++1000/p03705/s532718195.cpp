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
  ll n, a, b;
  cin >> n >> a >> b;
  if (a > b) {
    cout << 0 << endl;
    return;
  }
  if (n < 2) {
    if (a == b) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return;
  }
  ll r = a + b + (n - 2) * b;
  ll l = a + b + (n - 2) * a;
  cout << r - l + 1 << endl;
}

int main() {
  solve();
  return 0;
}