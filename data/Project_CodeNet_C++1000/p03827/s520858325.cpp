#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n;
  string s;
  cin>>n>>s;
  int x=0;
  int ans=0;
  rep(i,s.size()){
    if(s[i]=='I'){
      x++;
      ans=max(ans,x);
    }
    else{
      x--;
      ans=max(ans,x);
    }
  }
  cout<<ans<<endl;
}