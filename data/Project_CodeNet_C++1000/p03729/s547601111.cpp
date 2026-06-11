#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b,c;
  cin>>a>>b>>c;
  int x=a.size();
  int y=b.size();
  string ans="YES";
  if(a[x-1]!=b[0] || b[y-1]!=c[0]) ans="NO";
  cout<<ans<<endl;
}
