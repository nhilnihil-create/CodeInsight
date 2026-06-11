#include <bits/stdc++.h>
using namespace std;

int main() {
  string o,e,ans="";
  cin >> o >> e;
  for(long i=0;i<e.size();i++) ans=ans+o[i]+e[i];
  if(o.size()!=e.size()) ans=ans+o[o.size()-1];
  cout << ans << endl;
}