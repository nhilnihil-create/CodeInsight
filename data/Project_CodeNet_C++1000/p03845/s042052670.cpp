#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m;
  cin >> n;
  vector<int> t(n);
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> t[i];
    sum += t[i];
  }
  cin >> m;
  
  for(int i = 0; i < m; i++){
    int p, x, sum_i = sum;
    cin >> p >> x;
    p--;
    sum_i -= t[p];
    sum_i += x;
    cout << sum_i << endl;
  }
  
  return 0;
  
}