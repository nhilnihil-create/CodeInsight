#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin>>n;
  vector<int> s(n);
  int ans=0;
  rep(i,n) {
    cin>>s[i];
    ans+=s[i];
  }
  sort(s.begin(),s.end());
  if(ans%10==0){
    rep(i,n){
      if(s[i]%10!=0){
        ans-=s[i];
        break;
      }
    }
  }
  if(ans%10==0)cout<<0<<endl;
  else cout<<ans<<endl;
}