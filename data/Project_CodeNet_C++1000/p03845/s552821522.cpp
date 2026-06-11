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
  vector<int> t(n);
  rep(i,n) cin >> t[i];
  int m;
  cin >> m;
  vector<pii> px(m);
  rep(i,m) cin >> px[i].first >> px[i].second;
  rep(i,m) {
    int temp = px[i].second;
    rep(j,n) {
      if (px[i].first - 1 == j) continue;
      temp += t[j];
    }
    cout << temp << endl;
  }
}

int main() {
  solve();
  return 0;
}