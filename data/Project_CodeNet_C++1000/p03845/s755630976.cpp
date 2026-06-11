#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> list(n+1);
  for (int i=1; i<=n; i++) {
    cin >> list.at(i);
  }
  int m;
  cin >> m;
  int a,b,t;
  for (int i=0; i<m; i++) {
    int ans = 0;
    cin >> a >> b;
    t = list.at(a);
    list.at(a) = b;
    for (int i=1; i<list.size(); i++) {
      ans += list.at(i);
    }
    cout << ans << endl;
    list.at(a) = t;
  }
}