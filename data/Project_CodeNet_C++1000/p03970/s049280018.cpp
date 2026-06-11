#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string k = "CODEFESTIVAL2016";
  int ans = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] != k[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}