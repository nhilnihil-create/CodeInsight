#include<bits/stdc++.h>
#define maxn 5009
#define mod 1000000007
using namespace std;
char s[maxn];
int f[maxn][maxn*2];
inline void upd(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int main(){
  int n,m;
  scanf("%d%s",&n,s);
  m=strlen(s);
  f[0][0]=1;
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n+m;j++)
      if(f[i][j]) upd(f[i+1][max(0,j-1)],f[i][j]),upd(f[i+1][j+1],f[i][j]*2%mod);
  long long ans=1;
  for(int i=1;i<=m;i++) ans=ans*500000004%mod;
  printf("%lld",ans*f[n][m]%mod);
  return 0;
}
