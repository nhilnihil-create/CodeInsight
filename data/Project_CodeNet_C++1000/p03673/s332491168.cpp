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
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  
  for (int i = n - 1; i >= 0; i -= 2) {
    cout << v[i] << " ";
  }
  for (int i = n % 2; i < n; i += 2) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  solve();
  return 0;
}