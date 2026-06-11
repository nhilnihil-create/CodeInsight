#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  
  int x = 1, c = 0;
  for(int i=0; i<n; i++) {
    c++;
    if(v[x-1] == 2) break;
    x = v[x-1];
  }
  if(c == n) cout << -1 << endl;
  else cout << c << endl;
}