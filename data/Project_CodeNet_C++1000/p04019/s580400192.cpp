#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  vector<bool> a(4,false);
  for(int i=0;i<s.size();i++){
    if(s[i]=='N') a[0]=true;
    if(s[i]=='S') a[1]=true;
    if(s[i]=='W') a[2]=true;
    if(s[i]=='E') a[3]=true;
  }
  if(a[0]!=a[1]||a[2]!=a[3]) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}
