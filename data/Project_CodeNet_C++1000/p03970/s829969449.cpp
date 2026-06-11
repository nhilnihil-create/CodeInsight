#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long ans=0;
  string s,t="CODEFESTIVAL2016";
  cin >> s;
  for(long i=0;i<16;i++) if(s[i]!=t[i]) ans++;
  cout << ans << endl;
}