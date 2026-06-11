#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S; cin >> S;
  
  int ans = 0;
  
  for (int i = 0; i < S.size() - 1; i++) {
    
    if (S.at(i) != S.at(i + 1)) ans++;
    
  }
  
  cout << ans << endl;
  
}