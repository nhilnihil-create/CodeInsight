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
  int a, b;
  cin >> a >> b;
  if (a <= 0 && 0 <= b) {
    cout << "Zero" << endl;
    return;
  }
  if (0 < a) {
    cout << "Positive" << endl;
    return;
  }
  if ((abs(a - b) + 1)%2 == 0) cout << "Positive" << endl;
  else cout << "Negative" << endl;
}

int main() {
  solve();
  return 0;
}