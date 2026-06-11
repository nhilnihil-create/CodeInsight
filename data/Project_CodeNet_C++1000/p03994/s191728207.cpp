#include<bits/stdc++.h>
using namespace std;
signed main(){
  string s;
  int k;
  cin>>s>>k;
  for(int i=0;i<s.size();i++){
    if(s[i]!='a'){
      if(k-(26-(s[i]-97))>=0){
        k=k-(26-(s[i]-97));
        s[i]='a';
      }
    }
  }
  if(k%26!=0){
    k%=26;
    s[s.size()-1]+=k;
  }
  cout<<s<<"\n";
}