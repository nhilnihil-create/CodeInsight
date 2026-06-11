#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+7;
const int mod=1e9+7;
typedef long long ll;
ll dp[maxn][maxn];
ll quick(ll a,ll b)
{
 ll ret=1;
 while(b)
 {
  if(b&1) ret=ret*a%mod;
  a=a*a%mod;
  b>>=1;
 }
 return ret;
}
int main() {
int n;
string s;
cin>>n>>s;
dp[0][0]=1;
for(int i=1;i<=n;i++)
{
 for(int j=0;j<=i;j++)
 {
  if(!j)
   dp[i][j]=(dp[i-1][j]+dp[i-1][j+1])%mod;
  else
   dp[i][j]=(dp[i-1][j-1]*2+dp[i-1][j+1])%mod;
 }
}
 cout<<dp[n][s.length()]*quick(quick(2,s.length()),mod-2)%mod<<endl;
	return 0;
}