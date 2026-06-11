#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
 
using namespace std;
 
typedef long long ll;
 
ll pow_mod(ll x,int k) {
  ll ans=1;
  while (k) {
    if (k&1) ans=ans*x%MOD;
    x=x*x%MOD;
    k>>=1;
  }
  return ans;
}
 
ll facd[4000005],facv[4000005];
 
void pre(int n) {
  facd[0]=1;
  for(int i=1;i<=n;i++) facd[i]=facd[i-1]*i%MOD;
  facv[n]=pow_mod(facd[n],MOD-2);
  for(int i=n-1;i>=0;i--) facv[i]=facv[i+1]*(i+1)%MOD;
}
 
inline ll C(int n,int m) {
  return facd[n]*facv[m]%MOD*facv[n-m]%MOD;
}
 
ll f[2005][2005],sum[2005][2005];
 
int main() {
  int n,k;
  scanf("%d%d",&n,&k);
  if (k==1) {
    puts("1");
    return 0;
  }
  pre(n*k);
  f[0][0]=sum[0][0]=1;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++) {
        f[i][j]=sum[i-1][i-1];
        if (j>1) f[i][j]=(f[i][j]-sum[i-1][j-2]+MOD)%MOD;
        f[i][j]=C(i*k-j-1,k-2)*f[i][j]%MOD;
        sum[i][j]=(sum[i][j-1]+f[i][j])%MOD;
    }
  printf("%lld\n",sum[n][n]*facd[n]%MOD);
  return 0;
}
