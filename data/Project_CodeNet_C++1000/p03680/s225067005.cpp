#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    --a[i];
  }
  int pos = 0;
  int cnt = 0;
  rep(i, n) {
    if (pos == 1) break;
    pos = a[pos];
    ++cnt;
  }
  if (pos == 1) cout << cnt << endl;
  else cout << -1 << endl;
  return 0;
}