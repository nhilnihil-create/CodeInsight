#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m;
  cin >> n >> m;
  vector<int> sx(n);
  vector<int> sy(n);
  vector<int> cx(m);
  vector<int> cy(m);
  for (int i=0; i<n; i++) {
    cin >> sx.at(i) >> sy.at(i);
  }
  for (int i=0; i<m; i++) {
    cin >> cx.at(i) >> cy.at(i);
  }
  for (int i=0; i<n; i++) {
    int t=1000000009,s=0,ans=0;
    for (int j=0; j<m; j++) {
      s = abs(sx.at(i)-cx.at(j)) + abs(sy.at(i)-cy.at(j));
      if (t>s) {
        t = s;
        ans = j+1;
      }
    }
    cout << ans << endl;
  }
}