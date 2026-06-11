#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n,a,b; cin>>n>>a>>b;
  int x=b/a;
  int pre; cin>>pre;
  ll ans=0;
  for(int i=1;i<n;i++){
    int now; cin>>now;
    if(now-pre>x){
      ans+=b;
    }else{
      ans+=(now-pre)*a;
    }pre=now;
  }
  cout<<ans<<endl;
}