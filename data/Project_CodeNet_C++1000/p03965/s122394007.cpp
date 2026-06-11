#include <bits/stdc++.h>
using namespace std;

int main() {
  long ans;
  string s;
  cin >> s;
  ans=s.size()/2;
  for(long i=0;i<s.size();i++) if(s[i]=='p') ans--;
  cout << ans << endl;
}