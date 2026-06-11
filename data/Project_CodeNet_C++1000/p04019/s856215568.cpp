#include <bits/stdc++.h>
using namespace std;

int main() {

string S;
cin>>S;

bool n=false,s=false,e=false,w=false, flg=true;

for(int i=0;i<S.size();i++){
  char tmp=S[i];
  if(tmp=='N') n=true;
  if(tmp=='S') s=true;
  if(tmp=='E') e=true;
  if(tmp=='W') w=true;
}
if(n) if(!s) flg=false;
if(s) if(!n) flg=false;
if(e) if(!w) flg=false;
if(w) if(!e) flg=false;
if(flg) cout<<"Yes"<<endl;
else cout<<"No"<<endl;
}
