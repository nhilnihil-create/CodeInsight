#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  
  int m;
  cin >> m;
  
  int p, q;
  int sum = 0;
  for(int i=0; i<m; i++) {
    cin >> p >> q;
    for(int j=0; j<n; j++) {
      if(j==p-1) sum += q;
      else sum += v[j];
      if(j==n-1) cout << sum << endl;
    }
    sum = 0;
  }
  return 0;
}