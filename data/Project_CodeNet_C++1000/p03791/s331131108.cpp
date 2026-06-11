#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int x[n+1];
  for(int i=1;i<=n;i++) cin>>x[i];
  x[0]=-1;
  int ans=1,s1=0,s2=1,MOD=1000000007LL;
  for(int i=1;i<=n;i++){
    if(x[i-1]+2<=x[i]) x[i]=x[i-1]+2,s2++;
    (ans*=min(i-s1,s2))%=MOD;
    if(x[i-1]+2>x[i]) s1++,x[i]=x[i-1];
  }
  cout<<ans<<endl;
  return 0;
}

