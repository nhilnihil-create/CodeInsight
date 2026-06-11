#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(s.at(i) == 'g') ans++;
  }
  
  ans = ans - (n + 1) / 2;
  
  cout << ans << endl;
}