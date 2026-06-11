#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  int x, y;
  vector<pair<int,int>> v(n);
  for(int i=0; i<n; i++) {
    cin >> x >> y;
    v[i] = make_pair(x, y);
  }
  
  vector<pair<int,int>> w(m);
  for(int i=0; i<m; i++) {
    cin >> x >> y;
    w[i] = make_pair(x, y);
  }
  
  int xn, xm, yn, ym, dis, ans;
  int i = 1;
  int min = 1000000000;
  for(auto s : v) {
    tie(xn, yn) = s;
    for(auto t : w) {
      tie(xm, ym) = t;
      dis = abs(xn-xm)+abs(yn-ym);
      if(min>dis) {
        min = dis;
        ans = i;
      }
      i++;
    }
    cout << ans << endl;
    min = 1000000000;
    i = 1;
  }
  return 0;
}