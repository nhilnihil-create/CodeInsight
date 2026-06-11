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
  rep(i,n) {
    int a;
    cin >> a;
    a--;
    v[i] = a;
  }
  vector<int> cnt(n);
  int i = 0;
  int p = 0;
  bool b = true;
  for(;;) {
    if (i == 1) break;
    if (cnt[i]) {
      b = false;
      break;
    }
    p++;
    cnt[i] = 1;
    i = v[i];
  }
  cout << (b? p: -1) << endl;
}

int main() {
  solve();
  return 0;
}