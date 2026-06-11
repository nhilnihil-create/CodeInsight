#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int n,k;
  cin>>n>>k;
  vector<Int> a(n),b(n);
  for(Int i=0;i<n;i++) cin>>a[i]>>b[i];
  Int ans=0;
  for(int i=0;i<n;i++) if((k|a[i])==k) ans+=b[i];
  //cout<<ans<<endl;
  for(Int i=0;i<=40;i++){
    if(((k>>(40-i))&1)==0) continue;
    Int x=0;
    for(Int j=0;j<=i;j++) x+=(1LL<<(40-j));
    Int res=0;
    Int y=((k-(1LL<<(40-i)))&x);
    for(int j=0;j<n;j++)
      if((y|(a[j]&x))==y) res+=b[j];
    //for(int j=0;j<n;j++) cout<<(40-i)<<":"<<(a[j]&x)<<" "<<y<<" "<<b[j]<<endl;
    //cout<<res<<endl;
    ans=max(ans,res);
  }
  cout<<ans<<endl;
  return 0;
}
