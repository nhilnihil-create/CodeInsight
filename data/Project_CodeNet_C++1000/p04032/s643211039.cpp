#include <bits/stdc++.h>
using namespace std;

int main() {
  long ansa=-1,ansb=-1;
  string s;
  cin >> s;
  for(long i=1;i<s.size();i++) if(s[i-1]==s[i]) ansa=i,ansb=i+1;
  for(long i=2;i<s.size();i++) if(s[i-2]==s[i])ansa=i-1,ansb=i+1;
  cout << ansa << " " << ansb << endl;
}