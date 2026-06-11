#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int m = 1;
  int num = 1;
  while (num*2 < n) {
    num *= 2;
    m++;
  }
  vector<int> x(n);
  for (int i=0;i<n;i++) cin >> x[i];
  int l,q;
  cin >> l >> q;
  vector<vector<int>> to(m,vector<int>(n,0));
  for (int i=0;i<n;i++) {
    int tomax = x[i]+l;
    int ind = upper_bound(x.begin(),x.end(),tomax)-x.begin();
    to[0][i] = ind-1;
  }
  for (int i=1;i<m;i++) {
    for (int j=0;j<n;j++) {
      to[i][j] = to[i-1][to[i-1][j]];
    }
  }
  for (int i=0;i<q;i++) {
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    int high = n-1;
    int low = 1;
    if (a > b) swap(a,b);
    int las = high;
    while (low <= high) {
      int now = (low+high)/2;
      int na = a;
      int left = now;
      int times = 0;
      while (left > 0) {
        if (left%2 == 1) {
          na = to[times][na];
        }
        left /= 2;
        times++;
      }
      if (na >= b) {
        las = now;
        high = now-1;
      }
      else {
        low = now+1;
      }
    }
    cout << las << endl;
  }
}
