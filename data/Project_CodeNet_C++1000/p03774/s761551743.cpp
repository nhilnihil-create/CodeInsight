#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> sx(n);  vector<int> sy(n);
  vector<int> cx(m);  vector<int> cy(m);
  for (int i=0; i<n; i++) cin >> sx.at(i) >> sy.at(i);
  for (int i=0; i<m; i++) cin >> cx.at(i) >> cy.at(i);
  
  for (int i=0; i<n; i++) {
    int d=1000000009,tmp=0,ans=0;
    for (int j=0; j<m; j++) {
      tmp = abs(sx.at(i)-cx.at(j)) + abs(sy.at(i)-cy.at(j));
      if (d>tmp) {
        d = tmp;
        ans = j+1;
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}
