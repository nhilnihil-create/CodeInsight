#include<bits/stdc++.h>
using namespace std;
#define int long
main(){
  int c=0;
  string s;
  cin>>s;
  for(int i=0;i<s.size();++i){
    if(i%2)c+=s[i]=='g';
    else c-=s[i]=='p';
  }
  cout<<c;
}