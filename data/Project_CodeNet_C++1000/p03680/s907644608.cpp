#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int cnt = 0;
  int s = a[0];
  int flg = 0;
  rep(i,n) {
    cnt++;
    if (s == 2) {
      flg = 1;
      break;
    } else {
      s = a[s-1];
    }
  }
  if (flg) cout << cnt << endl;
  else cout << -1 << endl;
  return 0;
}