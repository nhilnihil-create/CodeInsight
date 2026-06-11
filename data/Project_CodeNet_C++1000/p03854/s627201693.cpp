#include<bits/stdc++.h>
using namespace std;
signed main(){
  string s,c[4]={"dream","dreamer","erase","eraser"};
  bool f;
  int p,ans=0,l;
  cin>>s;
  for(int i=0;i<s.size();i++){
    for(int j=0;j<4;j++){
      f=1;
      p=0;
      for(int k=0;k<c[j].size();k++){
        if(s[s.size()-1-i-k]!=c[j][c[j].size()-1-k]){
          f=0;
          break;
        }
      }
      if(f){
        i=i+c[j].size()-1;
        ans+=c[j].size();
        break;
      }
    }
  }
  if(ans==s.size()) cout<<"YES\n";
  else cout<<"NO\n";
}