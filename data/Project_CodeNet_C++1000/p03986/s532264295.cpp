#include <bits/stdc++.h>
using namespace std;

signed main(){
  string s;cin>>s;
  int now=0,ans=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='T'){
      if(now==0)ans++;
      else now--;
    }
    else now++;
  }
  cout<<now+ans<<endl;
}
