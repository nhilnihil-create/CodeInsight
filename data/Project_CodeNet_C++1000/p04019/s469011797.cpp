#include <bits/stdc++.h>
using namespace std;

int main() {
  string st;
  cin>>st;
  bool n,w,s,e;
  n=false;
  w=false;
  s=false;
  e=false;
  for(int i=0;i<st.size();i++){
    if(st[i]=='N') n=true;
    else if(st[i]=='W') w=true;
    else if(st[i]=='S') s=true;
    else e=true;
  }
  if((s && n) && (w && e)) cout<<"Yes"<<endl;
  else if((s && n) && (!w && !e)) cout<<"Yes"<<endl;
  else if((!s && !n) && (!w && !e)) cout<<"Yes"<<endl;
  else if((!s && !n) && (w && e)) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
