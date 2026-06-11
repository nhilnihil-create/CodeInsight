#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> rb(n);
  for(int i=0; i<n; i++) cin >> rb[i];
  
  int cnt = 0;
  for(int i=0; i<n; i++) if(rb[rb[i]-1]==i+1) cnt++;
  
  cout << cnt/2 << endl;
  return 0;
}