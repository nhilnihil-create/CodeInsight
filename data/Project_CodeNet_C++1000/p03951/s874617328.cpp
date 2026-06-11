#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int duplication = 0;
  
  string s, t; cin >> s >> t;
  
  for (int i = 1; i <= N; i++) {
    
    string tmpS = s.substr(N - i, i);
    
    string tmpT = t.substr(0, i);
    
    if (tmpS == tmpT) duplication = i;
    
  }
  
  int ans = N * 2 - duplication;
  
  cout << ans << endl;
  
}