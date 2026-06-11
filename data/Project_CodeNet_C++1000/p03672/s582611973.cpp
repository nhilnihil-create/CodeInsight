#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string s;
  cin>>s;
  int n=s.size();
  int ans;
  for(int i=2; i<=n; i+=2){
    bool flag=1;
    rep(j,(n-i)/2){
      if(s[j]!=s[(n-i)/2+j])flag=0;
    }
    if(flag){
      ans=n-i;
      break;
    } 
  }
  cout<<ans<<endl;
}
