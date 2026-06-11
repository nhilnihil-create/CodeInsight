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
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> v(9);
  rep(i,n) {
    v[min(8, (a[i] / 400))]++;
  }
  int mn = 0;
  int yet = 0;
  int sw = v[8];
  rep(i,8) {
    if (v[i]) mn++;
    else yet++;
  }
  if (mn && !sw) {
    cout << mn << " " << mn << endl;
  } else if (!mn && !sw) {
    cout << 0 << " " << 0 << endl;
  } else if (mn && sw) {
    cout << mn << " " << mn + sw << endl;
  } else {
    cout << 1 << " " << sw << endl;
  }
}

int main() {
  solve();
  return 0;
}