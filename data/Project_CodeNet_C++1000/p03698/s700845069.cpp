#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,ans="yes";
  cin >> s;
  sort(s.begin(),s.end());
  for(long i=0;i<s.size()-1;i++) {
    if(s[i]==s[i+1]) ans="no";
  }
  cout << ans << endl;
}