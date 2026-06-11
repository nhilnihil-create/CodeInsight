#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  int a;
  vector<int> b(100001, 0);
  for(int i = 0; i < n; i++){
    cin >> a;
    b.at(a)++;
  }
  
  int ans = 0, even = 0;
  for(int i = 0; i < 100001; i++){
    if(b.at(i) == 0) continue;
    else if(b.at(i) == 1) ans++;
    else if(b.at(i) % 2 == 1) ans++;
    else even++;
  }
  
  if(even % 2 == 0) ans += even;
  else ans += even - 1;
  
  cout << ans << '\n';
}