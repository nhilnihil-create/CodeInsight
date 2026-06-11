#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, t;
  cin >> k >> t;
  vector<int> a(t);
  for(int i = 0; i < t; i++) cin >> a.at(i);
  
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int ans;
  if(a.at(0) <= (k + 1) / 2) ans = 0;
  else if(k % 2) ans = (a.at(0) - (k+1) / 2) * 2;
  else ans = 1 + (a.at(0) - k / 2 - 1) * 2;
  
  cout << ans << endl;  
}