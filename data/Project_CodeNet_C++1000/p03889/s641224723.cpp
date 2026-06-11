#include <bits/stdc++.h>
using namespace std;

signed main(){
  string s;cin>>s;
  string t=s;
  reverse(t.begin(),t.end());
  for(char &p:t){
    if(p=='b')p='d';
    else if(p=='d')p='b';
    else if(p=='p')p='q';
    else if(p=='q')p='p';
  }
  if(s==t)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
