#include <bits/stdc++.h>
const int N=1000050,mo=1e9+7;
using namespace std;
int gi(){
  char ch=getchar(); int x=0,q=0;
  while(ch<'0' || ch>'9') (ch=='-'?q=1:0),ch=getchar();
  while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
  return q?(-x):x;
}
int dp[N][2],st[N<<1],ans;
int main(){
  int n=gi(),s;
  dp[0][0]=1;
  for (int i=0; i<n; ++i){
    if (i) (st[i]+=st[i-1])%=mo;
    (dp[i][1]+=st[i])%=mo;
    s=(dp[i][0]+dp[i][1])%mo;
    (dp[i+1][0]+=s)%=mo;
    if (i!=n-1){
      (st[i+3]+=s)%=mo;
      (st[i+n+2]-=s)%=mo;
    }
    else ans+=1ll*s*n%mo-s;
  }
  (st[n]+=st[n-1])%=mo;
  (dp[n][1]+=st[n])%=mo;
  for (int i=n+1; i<=(n<<1); ++i){
    (st[i]+=st[i-1])%=mo;
    (ans+=1ll*n*st[i]%mo)%=mo;
  }
  for (int i=1; i<=n; ++i)
    (ans+=1ll*(n-1)*dp[i][1]%mo)%=mo;
  (ans+=(dp[n][0]+dp[n][1])%mo)%=mo;
  cout<<ans;
  return 0;
}
