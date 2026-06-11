#include <bits/stdc++.h>
using namespace std;
int main(){
  string e = "CODEFESTIVAL2016", s; cin >> s;
  int ans = 0;
  for(int i = 0; i < e.size(); i++) ans += e[i] != s[i];
  cout << ans << endl;
  return 0;
}