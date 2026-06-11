#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  vector<int> t(n);
  for (int i = 0; i < n; i++)
    cin >> t.at(i);
  
  int m;
  cin >> m;
  
  int p, x, ans, temp;
  
  for (int i = 0; i < m; i++) {
    cin >> p >> x;
    
    temp = t.at(p-1);
    t.at(p-1) = x;
    
    ans = 0;
    for (int y : t) ans += y;
    cout << ans << endl;
    
    t.at(p-1) = temp;
  }
}