#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  
  int x = 1;
  int count = 0;
  for(int i=0; i<n; i++) {
    count++;
    if(v[x-1]==2) break;
    x = v[x-1];
  }
  if(count==n) cout << -1 << endl;
  else cout << count << endl;
  return 0;
}