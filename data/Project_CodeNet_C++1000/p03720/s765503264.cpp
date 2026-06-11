#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  int n, m;
  cin >> n >> m;
  
  int x;
  vector<int> v(n);
  for(int i=0; i<m*2; i++) {
    cin >> x;
    v[x-1] += 1;
  }
  
  for(int i=0; i<n; i++) cout << v[i] << endl;
  return 0;
}