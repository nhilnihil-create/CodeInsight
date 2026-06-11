#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  string s;
  cin>>s;
  int ans=100000;
  for(char i='a';i<='z';i++){
    int cnt=0;
    int ma=0;
    rep(j,s.size()){
      if(s[j]!=i)ma=max(ma,++cnt);
      else cnt=0;
    }
    ans=min(ans,ma);
  }
  cout << ans << endl;
}