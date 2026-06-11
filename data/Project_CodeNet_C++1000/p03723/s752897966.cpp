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

int dfs(ll a, ll b, ll c) {
  if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
    return 0;
  }
  if (a == b && b == c) {
    return -1;
  }
  return 1 + dfs((b+c)/2, (a+c)/2, (a+b)/2);
}

void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  cout << dfs(a, b, c) << endl;
}

int main() {
  solve();
  return 0;
}