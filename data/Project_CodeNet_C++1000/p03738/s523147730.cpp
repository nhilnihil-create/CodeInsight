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
  string a, b;
  cin >> a >> b;
  if (a.size() != b.size()) {
    if (a.size() > b.size()) cout << "GREATER" << endl;
    else cout << "LESS" << endl;
    return;
  }
  if (a > b) cout << "GREATER" << endl;
  else if (a < b) cout << "LESS" << endl;
  else cout << "EQUAL" << endl;
}

int main() {
  solve();
  return 0;
}