#include <bits/stdc++.h>
using namespace std;

signed main(){
  string s;int k;cin>>s>>k;
  for(int i=0;i<s.size()&&k;i++){
    if(s[i]=='a')continue;
    int res=s[i]-'a';
    res=26-res;
    if(res>k)continue;
    k-=res;
    s[i]='a';
  }
  k%=26;
  for(int i=0;i<k;i++){
    s[s.size()-1]=char(s[s.size()-1]+1);
    if(s[s.size()-1]>'z')s[s.size()-1]='a';
  }
  cout<<s<<endl;
}
